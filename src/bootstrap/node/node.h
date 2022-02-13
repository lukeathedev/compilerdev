#ifndef NODE_H
#define NODE_H

#include <stdio.h>

#include "typedef.h"
#include "token/token.h"

struct _NODE;
typedef struct _NODE {
  struct _NODE* left;
  struct _NODE* right;
  char data[DATA_SZ];
} NODE;

NODE* nodemk(char* data, NODE* left, NODE* right);
void  nodegviz(NODE* root, FILE* stream);
void  nodefree(NODE* node);

#endif
