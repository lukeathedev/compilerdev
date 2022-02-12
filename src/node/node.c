#include "node.h"
#include "typedef.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// NODE* parse(TOKEN* tk_root) {

// }

NODE* nodemk(char* data, NODE* left, NODE* right) {
  NODE* nd = (NODE* ) malloc(sizeof(NODE));

  nd->left  = left;
  nd->right = right;
  strncpy(nd->data, data, DATA_SZ);

  return nd;
}

// I kind of blanked and decided to try this child thing
// it works, so I'm not complaining
static void traverse(NODE* node, i32* i, FILE* stream) {
  i32 child = *i;

  if (node->left) {
    traverse(node->left, i, stream);
    child = *i-1;
  }
  if (node->right) {
    traverse(node->right, i, stream);
  }

  fprintf(stream, "\n");
  if (*i == child) {
    fprintf(stream, "  // Leaf node\n");
  }
  fprintf(stream, "  nd%06d [label=\"%s\"];\n", *i, node->data);

  if (*i != child) {
    fprintf(stream, "  nd%06d -- nd%06d;\n", *i, *i-1);
    fprintf(stream, "  nd%06d -- nd%06d;\n", *i, child);
  }

  *i += 1;
}

void nodegviz(NODE* root, FILE* stream) {
  i32 i = 0;
  fprintf(stream, "graph \"AST\" {\n");
  fprintf(stream, "  // Generated by 'nodegviz'");
  // fprintf(stream, "  rankdir=\"BT\";\n");

  traverse(root, &i, stream);

  fprintf(stream, "}\n");
}

void nodefree(NODE* node) {
  if (node->left) {
    nodefree(node->left);
  }
  if (node->right) {
    nodefree(node->right); 
  }

  // printf("free -> %s\n", node->data);
  free(node);
}
