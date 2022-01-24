#include <nib.h>
#include <input.h>

InputBuffer* newInputBuffer(){
	InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
	input_buffer->buffer = NULL;
	input_buffer->buffer_length = 0;
	input_buffer->input_length = 0;

	return input_buffer;
}

void prompt() { printf(">>> "); }

void readInput(InputBuffer* buffer) {
  ssize_t bytes_read =
      getline(&(buffer->buffer), &(buffer->buffer_length), stdin);

  if (bytes_read <= 0) {
    printf("Error reading input\n");
    exit(EXIT_FAILURE);
  }

  // Ignore trailing newline
  buffer->input_length = bytes_read - 1;
  buffer->buffer[bytes_read - 1] = 0;
}