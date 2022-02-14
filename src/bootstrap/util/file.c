#include "file.h"
#include "typedef.h"
#include "error.h"

#include <stdio.h>
#include <stdlib.h>

// Remember to free returned char*!
char* read_file(char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("[ERROR] Could not open file");
    exit(ERR_BAD_FILE);
  }

  // Get file size
  fseek(fp, 0, SEEK_END);
  u32 file_sz = ftell(fp);
  rewind(fp);

  char* buf = malloc((file_sz + 1) * sizeof(char));

  u32 read = fread(buf, sizeof(char), file_sz, fp);
  if (read != file_sz) {
    exit(ERR_BAD_READ);
  }

  fclose(fp);

  buf[file_sz] = '\0';
  return buf;
}
