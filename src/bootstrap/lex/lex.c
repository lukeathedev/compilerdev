#include "lex.h"
#include "token/token.h"

#include <stddef.h>
#include <stdbool.h>
#include <string.h>

static bool is_number(char c) {
  return (i8) c >= (i8) '0' && (i8) c <= (i8) '9';
}

// TODO: check EOF
#define consume(c) _consume(&c, source, &i)
static char _consume(char* c, char* source, u32* i) {
  *i += 1; *c = source[*i];
  return *c;
}

TK_LIST* lex(char* source) {
  // iterate per char
  // classify each
  u32 i = 0;
  char c = source[i];

  // TODO: expand data_sz to allow larger lexemes
  char buf[DATA_SZ] = { 0 };

  TK_LIST* tokens = tokensinit();

  while (c != '\0') {
    c = source[i];
    switch (c) {
      case '\0':
      case '\n':
      case ' ':
      break;

      case '+':
        tokenmk(tokens, TK_PLUS, "+");
      break;

      case '-':
        tokenmk(tokens, TK_MINUS, "-");
      break;

      case '*':
        tokenmk(tokens, TK_NULL, "*");
      break;

      case '/':
        tokenmk(tokens, TK_NULL, "/");
      break;

      default:
        if (is_number(c)) {
          // TODO: verify buffer won't overflow
          for (u32 j = 0; is_number(c); ++j) {
            buf[j] = c; consume(c);
          }

          tokenmk(tokens, TK_INT, buf);
          memset(buf, '\0', DATA_SZ);
        }
        else {
          tokenmk(tokens, TK_UNK, "unknown");
        }
    }
    i += 1;
  }

  // Add null token to signify EOF
  tokenmk(tokens, TK_NULL, "EOF");

  return tokens;
}
