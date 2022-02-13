#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "typedef.h"

#include "node/node.h"
#include "node/test.h"
#include "token/token.h"

#include "lex/lex.h"

i32 main() {
  // FILE* fp = fopen("build/gv/ast.dot", "w");
  // if (fp == NULL) {
  //   perror("Could not open file 'build/gv/ast.dot'");
  //   exit(-1);
  // }

  // char* source = "3 * 2 + 1"; // =7 (with prec), =9 (without)
  char* source = "10 * 10 - 4 + 3 * 2 / 2";

  clock_t start = clock();

  TK_LIST* tokens = lex(source);
  if (!tokens || !tokens->tks) {
    fprintf(stderr, "[ERROR] Could not generate tokens\n");
    exit(-1);
  }

  NODE* ast_root = nd_ex02();
  if (!ast_root) {
    fprintf(stderr, "[ERROR] Failed to generate AST\n");
    exit(-2);
  }

  clock_t end = clock();

  tokensgviz(tokens, stdout);
  printf("\n");
  nodegviz(ast_root, stdout);

  f64 exec_time = (f64) (end - start) / CLOCKS_PER_SEC;
  printf("\n[INFO]  Done in %.6fs\n", exec_time);

  // Cleanup --------------------

  nodefree(ast_root);
  tokensfree(tokens);

  // fclose(fp);
  return 0;
}
