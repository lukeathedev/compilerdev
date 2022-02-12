#include <stdio.h>
#include <stdlib.h>

#include "typedef.h"

#include "token/token.h"
#include "node/node.h"
#include "node/test.h"

i32 main() {
  // FILE IO -------------------
  FILE* fp = fopen("build/gv/ast.dot", "w");
  if (fp == NULL) {
    perror("Could not open file 'build/gv/ast.dot'");
    exit(-1);
  }

  // TOKEN* tk_root = lex("2 + 2 - 1");
  // if (tk_root) {
  //   tokenfree(tk_root);
  // }

  NODE* nd_root = nd_ex02();
  // NODE* nd_root = parse(tk_root);
  if (nd_root) {
    nodegviz(nd_root, fp);
    nodefree(nd_root);
  }

  fclose(fp);
  return 0;
}
