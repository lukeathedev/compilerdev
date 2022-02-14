#ifndef NODE_H
#define NODE_H

#include <stdio.h>

#include "typedef.h"
#include "token/token.h"

typedef enum {
  ND_NULL,
  ND_ADD,
  ND_SUB,
  ND_MUL,
  ND_DIV,
  ND_INT,
} ND_TYPE;

struct _NODE;
typedef struct _NODE {
  ND_TYPE type;
  char data[DATA_SZ];
  struct _NODE* left;
  struct _NODE* right;
} NODE;

NODE* nodemk(ND_TYPE type, char* data, NODE* left, NODE* right);
char* node_get_type(NODE* node);
void  nodegviz(NODE* root, FILE* stream);
void  nodefree(NODE* node);

#endif
