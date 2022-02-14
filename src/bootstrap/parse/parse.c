#include "parse.h"
#include "typedef.h"
#include "node/node.h"
#include "node/test.h"

#include <stdlib.h>

// TODO: move this to a more appropriate place
static ND_TYPE tk2nd(TK_TYPE type) {
  switch (type) {
    case TK_NULL:  return ND_NULL;
    case TK_PLUS:  return ND_ADD;
    case TK_MINUS: return ND_SUB;
    case TK_STAR:  return ND_MUL;
    case TK_SLASH: return ND_DIV;
    case TK_INT:   return ND_INT;
    case TK_UNK:   return ND_NULL;

    default: return ND_NULL;
  }
}

// Operation precedence
static i32 OP_PREC[6] = {
  0,  // ND_NULL 
  10, // ND_ADD
  10, // ND_SUB
  20, // ND_MUL
  20, // ND_DIV
  0,  // ND_INT
};

static NODE* bin_expr(TK_LIST* tokens, u32* i, i32 p_prec) {
  #define TK_CUR tokens->tks[*i] // Current token

  NODE* left =  NULL;
  NODE* right = NULL;

  // Left node (must be a number)
  if (TK_CUR->type != TK_INT) {
    fprintf(stderr, "[ERROR] Expected integer, got '%s' at [%u:%u]\n",
    TK_CUR->lxm, TK_CUR->line, TK_CUR->col);
    exit(99);
  }
  left = nodemk(ND_INT, tokens->tks[*i]->lxm, NULL, NULL);

  // Operation node
  *i += 1;
  if (TK_CUR->type == TK_NULL) {
    return left;
  }

  TOKEN* op_token = tokens->tks[*i];

  while (OP_PREC[tk2nd(op_token->type)] > p_prec) {
    *i += 1;
    right = bin_expr(tokens, i, OP_PREC[tk2nd(op_token->type)]);
    left = nodemk(tk2nd(op_token->type), op_token->lxm, left, right);

    op_token = TK_CUR;
    if (op_token->type == TK_NULL) {
      return left;
    }
  }

  #undef TK_CUR
  return left;
}

NODE* parse(TK_LIST* tokens) {
  u32 i = 0;
  NODE* root = bin_expr(tokens, &i, 0);
  return root;
}
