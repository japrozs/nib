#include <nib.h>
#include <input.h>
#include <core.h>

Statement* parse(InputBuffer* buffer){
	// create an empty statement struct
	Statement* stmt = newStatement();

	// create a copy of the input buffer
	int len = strlen(buffer->buffer);
	char* context;
	char* copy = (char*) calloc(len + 1, sizeof(char));
	strncpy(copy, buffer->buffer, len);

	// get the first word of the string
	char* cmd = strtok_r(copy, " ", &context);

	// mpa against all the keywords
	if(strcmp(cmd, "set") == 0){
		stmt->type = SET;
	}else if(strcmp(cmd, "get") == 0){
		stmt->type = GET;
	}else if(strcmp(cmd, "update") == 0){
		stmt->type = UPDATE;
	}else if(strcmp(cmd, "delete") == 0){
		stmt->type = DELETE;
	}else if(strcmp(cmd, "clear") == 0){
		stmt->type = CLEAR;
	}else if(strcmp(cmd, "exit") == 0){
		stmt->type = EXIT;
	}else if(strcmp(cmd, "info") == 0){
		stmt->type = INFO;
	}else if(strcmp(cmd, "list") == 0){
		stmt->type = LIST;
	}else if(strcmp(cmd, "help") == 0){
		stmt->type = HELP;
	}else{
		stmt->type = UNKNOWN;
	}

	stmt->cmd = cmd;
	stmt->statement = buffer->buffer;
	stmt->buffer = buffer;

	free(copy);

	return stmt;
}