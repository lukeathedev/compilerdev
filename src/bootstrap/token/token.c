#include "token.h"
#include "typedef.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

TK_LIST* tokensinit() {
  TK_LIST* tl = malloc(sizeof(TK_LIST));
  tl->tks = NULL;
  tl->len = 0;

  return tl;
}

void tokenmk(TK_LIST* tokens, TK_TYPE type, char* data, u32 line, u32 col) {
  TOKEN* tk = (TOKEN* ) malloc(sizeof(TOKEN));
  
  tk->type = type;
  strncpy(tk->lxm, data, DATA_SZ - 1);
  tk->line = line;
  tk->col  = col;

  // realloc tks
  tokens->tks = realloc(tokens->tks, sizeof(uptr) * (tokens->len + 1));

  tokens->tks[tokens->len] = tk;
  tokens->len += 1;
}

// Remember to free used buffer!
char* token_get_type(TOKEN* token) {
  char* dest = malloc(DATA_SZ);
  #define s(str) strncpy(dest, str, DATA_SZ - 1)

  switch (token->type) {
    case TK_NULL:  s("TK_NULL");  break;
    case TK_PLUS:  s("TK_PLUS");  break;
    case TK_MINUS: s("TK_MINUS"); break;
    case TK_STAR:  s("TK_STAR");  break;
    case TK_SLASH: s("TK_SLASH"); break;
    case TK_INT:   s("TK_INT");   break;
    default: s("UNKNOWN"); break;
  }

  #undef s

  return dest;
}

void tokensgviz(TK_LIST* tokens, FILE* stream) {
  fprintf(stream, "digraph \"TOKENS\" {\n");
  fprintf(stream, "  // Generated by 'tokensgviz'\n");
  fprintf(stream, "  node [shape=record];\n");

  // Not too pleased with the mallocs
  for (u32 i = 0; i < tokens->len; ++i) {
    TOKEN* tk = tokens->tks[i];
    char *type = token_get_type(tk);

    fprintf(stream, "\n  nd%06u [label=\"[%u:%u]|%s|'%s'\"];\n",
    i, tk->line, tk->col, type, tk->lxm);

    if (i != tokens->len - 1) {
      fprintf(stream, "  nd%06u -> nd%06u\n", i, i+1);
    }

    free(type);
  }

  fprintf(stream, "}\n");
}

void tokensfree(TK_LIST* tokens) {
  for (u32 i = 0; i < tokens->len; ++i) {
    free(tokens->tks[i]);
  }

  free(tokens->tks);
  free(tokens);
}
