#ifndef CORE_H
#define CORE_H

#include <nib.h>
#include <input.h>

Statement* parse(InputBuffer* buffer);
void exec(Statement* stmt);

// Commands
void set(Statement* stmt);
void get(Statement* stmt);

#endif // CORE_H