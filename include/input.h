#ifndef INPUT_H
#define INPUT_H

#include <nib.h>

typedef struct {
  char* buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

InputBuffer* newInputBuffer();
void prompt();
void readInput(InputBuffer* buffer);

#endif // INPUT_H