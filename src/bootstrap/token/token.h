#ifndef TOKEN_H
#define TOKEN_H

#include "typedef.h"

typedef enum {
  TK_NULL,
  TK_INT,
  TK_PLUS,
  TK_MINUS,
  TK_STAR,
  TK_SLASH
} TK_TYPE;

struct _TOKEN;
typedef struct _TOKEN {
  TK_TYPE type;
  char lxm[DATA_SZ];

  struct _TOKEN* next;
} TOKEN;

TOKEN* tokenmk(TK_TYPE type, char* data, TOKEN* next);
void   tokenfree(TOKEN* token);

#endif
