#ifndef NIB_H
#define NIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>


#include <input.h>

#define BUFSIZE 255

typedef enum {
	SET,
    GET,
    UPDATE,
    DELETE,
    CLEAR,
    EXIT,
    INFO,
    LIST,
    HELP,
    UNKNOWN,
} Command;

typedef struct{
	Command type;
	char* cmd;
	char* statement;
    InputBuffer* buffer;
} Statement;

Statement* newStatement();

#endif // NIB_H