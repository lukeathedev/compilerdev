#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "typedef.h"
#include "error.h"

#include "util/file.h"
#include "node/node.h"
#include "token/token.h"

#include "lex/lex.h"
#include "parse/parse.h"

// TODO: add error code definitions
i32 main() {
  char* source = load_file("test/input00");

  clock_t start = clock();

  TK_LIST* tokens = lex(source);
  if (!tokens || !tokens->tks) {
    fprintf(stderr, "[ERROR] Failed to generate tokens\n");
    exit(ERR_LEX_FAIL);
  }

  NODE* ast_root = parse(tokens);
  if (!ast_root) {
    fprintf(stderr, "[ERROR] Failed to generate AST\n");
    exit(ERR_AST_FAIL);
  }

  clock_t end = clock();

  tokensgviz(tokens, stdout);
  printf("\n");
  nodegviz(ast_root, stdout);

  f64 exec_time = (f64) (end - start) / CLOCKS_PER_SEC;
  printf("\n[INFO]  Done in %.6fs\n", exec_time);

  // Cleanup --------------------

  free(source);
  nodefree(ast_root);
  tokensfree(tokens);

  exit(SUCCESS);
}
