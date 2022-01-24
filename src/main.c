#include <nib.h>
#include <input.h>
#include <core.h>

#define VERSION "0.0.1"

Statement* newStatement(){
	Statement* stmt = malloc(sizeof(Statement));
	if(stmt == NULL){
		printf("Could not allocate enough memory for a new variable!\n");
		exit(0);
	}
	stmt->type = UNKNOWN;
	stmt->cmd = "";
	stmt->statement = "";
	stmt->buffer = newInputBuffer();

	return stmt;
}

int main(int argc, char** argv){
	InputBuffer* buffer = newInputBuffer();

	// loop forever
	while(true){
		prompt();
		readInput(buffer);
		Statement* stmt = parse(buffer);
		exec(stmt);
	}

	return 0;
}