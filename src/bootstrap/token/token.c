#include "token.h"
#include "typedef.h"

#include <stdlib.h>

// TOKEN* tokenmk(TK_TYPE type, char* data, TOKEN* next) {}

void tokenfree(TOKEN* token) {
  if (token->next) {
    tokenfree(token->next);
  }

  free(token);
}
