#include <stdio.h>
#include <stdlib.h>

#include "typedef.h"

#include "node/node.h"
#include "node/test.h"
#include "token/token.h"

i32 main() {
  // FILE IO -------------------
  // FILE* fp = fopen("build/gv/ast.dot", "w");
  // if (fp == NULL) {
  //   perror("Could not open file 'build/gv/ast.dot'");
  //   exit(-1);
  // }

  TK_LIST* tokens = tokensinit();
  tokenmk(tokens, TK_NULL, "test00");
  tokenmk(tokens, TK_NULL, "test01");
  tokenmk(tokens, TK_PLUS, "test02");
  tokenmk(tokens, TK_NULL, "test03");
  tokenmk(tokens, TK_NULL, "test04");
  tokenmk(tokens, TK_NULL, "test05");
  tokenmk(tokens, TK_NULL, "test06");

  tokensgviz(tokens, stdout);

  tokensfree(tokens);


  // const char* source = "3 * 2 + 2";

  // TOKEN* tk_root = lex((char* ) source);
  // if (!tk_root) {
  //   exit(-1);
  // }
  // tokengviz(tk_root, stdout);
  // return 0; 

  // NODE* nd_root = nd_ex02();
  // // NODE* nd_root = parse(tk_root);
  // if (!nd_root) {
  //   exit(-2);
  // }
  // nodegviz(nd_root, stdout);

  // nodefree(nd_root);
  // tokenfree(tk_root);

  // fclose(fp);
  return 0;
}
