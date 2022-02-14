#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "typedef.h"

#include "node/node.h"
#include "node/test.h"
#include "token/token.h"

#include "lex/lex.h"
#include "parse/parse.h"

// Remember to free returned char*!
// TODO: move to a different file
char* load_file(char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("[ERROR] Could not open file");
    exit(5);
  }

  // get sz
  fseek(fp, 0, SEEK_END);
  u32 fsz = ftell(fp);
  rewind(fp);

  char* buf = malloc((fsz + 1) * sizeof(char));

  u32 read = fread(buf, sizeof(char), fsz, fp);
  if (read != fsz) {
    exit(10);
  }

  fclose(fp);

  buf[fsz] = '\0';
  return buf;
}

i32 main() {
  char* source = load_file("test/input00");

  clock_t start = clock();

  TK_LIST* tokens = lex(source);
  if (!tokens || !tokens->tks) {
    fprintf(stderr, "[ERROR] Could not generate tokens\n");
    exit(-1);
  }

  NODE* ast_root = parse(tokens);
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

  free(source);
  nodefree(ast_root);
  tokensfree(tokens);

  // fclose(fp);
  return 0;
}
