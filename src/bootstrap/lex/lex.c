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

// #define peek(c) _peek(source, i)
// static char _peek(char* source, u32 i) {
//   return source[i+1];
// }

TK_LIST* lex(char* source) {
  char c = '\xFF'; // any value should do
  u32 line = 1, col = 0;

  // TODO: expand data_sz to allow larger lexemes
  char buf[DATA_SZ] = { 0 };

  TK_LIST* tokens = tokensinit();

  for (u32 i = 0; c != '\0'; ++i) {
    col++; c = source[i];
    switch (c) {
      case '\0':
      case ' ':
      break;

      case '\n':
        line++; col = 0;
      break;

      case '+':
        tokenmk(tokens, TK_PLUS, "+", line, col);
      break;

      case '-':
        tokenmk(tokens, TK_MINUS, "-", line, col);
      break;

      case '*':
        tokenmk(tokens, TK_STAR, "*", line, col);
      break;

      case '/':
        tokenmk(tokens, TK_SLASH, "/", line, col);
      break;

      default:
        if (is_number(c)) {
          // TODO: verify buffer won't overflow
          for (u32 j = 0; is_number(c); ++j) {
            buf[j] = c; consume(c); col++;
          } i--; col--;

          tokenmk(tokens, TK_INT, buf, line, col);
          memset(buf, '\0', DATA_SZ);
        }

        else {
          tokenmk(tokens, TK_UNK, "unknown", line, col);
        }
    }
  }

  // Add null token to signify EOF
  tokenmk(tokens, TK_NULL, "EOF", line, col);
  return tokens;
}
