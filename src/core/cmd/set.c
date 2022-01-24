#include <nib.h>
#include <io.h>
#include <core.h>
#include <extract.h>

void set(Statement* stmt){
	char* path = getFilePath();

	char* str = malloc(999999 * sizeof(char));
	strcpy(str, stmt->statement);

	while (*str != 0 && *(str++) != ' ') {}

	char key[999999] = "";
	char value[999999] = "";

	int i = 0;
	int j = 0;
	// extract the key
	while(str[i] != 0 && str[i] != ' '){
		key[i] = str[i];
		i++;
	}

	while(str[i] != 0){
		value[j] = str[i];
		i++;
		j++;
	}

	Prop* prop = malloc(sizeof(Prop));
	prop->key = key;
	prop->value = trim(value);

	writePropToFile(prop, path);
}