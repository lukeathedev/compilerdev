#ifndef ERROR_H
#define ERROR_H

typedef enum {
  SUCCESS,      // 0
  ERR_GENERIC,  // 1
  ERR_LEX_FAIL, // 2
  ERR_AST_FAIL, // 3
  ERR_SYNTAX,   // 4
  ERR_BAD_FILE, // 5
  ERR_BAD_READ, // 6
} ERR_TYPE;

#endif
