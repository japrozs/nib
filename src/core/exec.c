#include <nib.h>
#include <core.h>

void exec(Statement* stmt){
	switch(stmt->type){
		case SET:
			set(stmt);
			break;
		case GET:
			get(stmt);
			break;
		case UPDATE:
			printf("udpate function\n");
			break;
		case DELETE:
			printf("delete function\n");
			break;
		case CLEAR:
			printf("clear function\n");
			break;
		case EXIT:
			printf("Bye!\n");
			exit(0);
			break;
		case INFO:
			printf("info function\n");
			break;
		case LIST:
			printf("list function\n");
			break;
		case HELP:
			printf("help function\n");
			break;
		case UNKNOWN:
			printf("unknown function\n");
			break;
	}
}