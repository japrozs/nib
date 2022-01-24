#include <extract.h>

// converts a '		string		' to 'string'
char* trim(char *str)
{
    char *end;
    while(isspace((unsigned char)*str)) str++;
    if(*str == 0)
        return str;

    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';

    return str;
}

Prop* extractProps(char* path){
	FILE* file = fopen(path, "r");
	int i = 0;
	Prop* props = malloc(999999 * sizeof(Prop));
	char line[999999];

	while (fgets(line, sizeof(line), file)) {
		int len = strlen(line);
		char* context;
		char* copy = (char*) calloc(len + 1, sizeof(char));
		strncpy(copy, line, len);

		char* key = strtok_r(copy, ":", &context);
		Prop* p = malloc(sizeof(Prop));
		if(p == NULL){
			printf("Could not allocate enough memory for a new variable!\n");
			exit(0);
		}
		p->key = key;
		p->value = trim(context);

		props[i] = *p;
		i++;
    }

	fclose(file);

	return props;
}

void writePropToFile(Prop* prop, char* path){
	FILE* file = fopen(path, "a");
	char str[99999] = "";
	strcat(str, prop->key);
	strcat(str, ": ");
	strcat(str, prop->value);
	strcat(str, "\n");
	printf("%s",str);

	fputs(str, file);
}