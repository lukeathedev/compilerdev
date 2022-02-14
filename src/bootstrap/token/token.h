#ifndef TOKEN_H
#define TOKEN_H

#include "typedef.h"
#include <stdio.h>

typedef enum {
  TK_NULL,
  TK_PLUS,
  TK_MINUS,
  TK_STAR,
  TK_SLASH,
  TK_INT,
  TK_UNK, // unknown token
} TK_TYPE;

typedef struct {
  TK_TYPE type;
  char    lxm[DATA_SZ]; // lexeme

  u32 line, col;
} TOKEN;

typedef struct {
  TOKEN** tks;
  u32    len;
} TK_LIST;

TK_LIST* tokensinit();
void     tokenmk(TK_LIST* tokens, TK_TYPE type,
                 char* data, u32 line, u32 col);
char*    token_get_type(TOKEN* token);
void     tokensgviz(TK_LIST* tokens, FILE* stream);
void     tokensfree(TK_LIST* tokens);

#endif
