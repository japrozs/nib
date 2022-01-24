#ifndef EXTRACT_H
#define EXTRACT_H

#include <nib.h>
#include <core.h>
#include <input.h>
#include <io.h>

typedef struct{
	char* key;
	char* value;
} Prop;

Prop* extractProps(char* path);
char* trim(char *str);
void writePropToFile(Prop* prop, char* path);

#endif // EXTRACT_H