#include "parse.h"
#include "node/node.h"
#include "node/test.h"

#include <stdlib.h>

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

static NODE* bin_expr(TK_LIST* tokens, u32* i) {
  NODE* left = NULL;
  
  // Left node (must be a number)
  // TODO: add line, col to errors
  if (tokens->tks[*i]->type != TK_INT) {
    fprintf(stderr, "[ERROR] Expected integer\n");
    exit(99);
  }
  left = nodemk(ND_INT, tokens->tks[*i]->lxm, NULL, NULL);

  if (tokens->tks[*i+1]->type == TK_NULL) {
    return left;
  }

  // Operation node details
  *i += 1;
  ND_TYPE nd_type = tk2nd(tokens->tks[*i]->type);
  char* data = tokens->tks[*i]->lxm;

  // Right node is recursively obtained
  *i += 1;
  return nodemk(nd_type, data, left, bin_expr(tokens, i));
}

NODE* parse(TK_LIST* tokens) {
  u32 i = 0;
  NODE* root = bin_expr(tokens, &i);
  // NODE* root = nd_ex00();
  return root;
}
