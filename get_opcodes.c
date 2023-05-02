#include "main.h"

/**
 * get_opcodes - slect opcode to perform
 *
 * @op: opcode passed
 * Return: pointer to the opcode function
 */
void (*get_opcodes(char *op))(stack_t **stack, unsigned int line)
{
	instruction_t instruct[] = {
		{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"add", _add},
		{"pop", _pop}, {"nop", _nop},
		{"swap", _swap}, {"sub", _sub},
		{"queue", _queue}, {"mul", _mul},
		{"stack", _stack}, {"pchar", _pchar},
		{"rotl", _rotl}, {"pstr", _pstr},
		{"rotr", _rotr}, {NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++;)
	{
		if (_strcmp(instruct[i].opcode, op) == )
			break;
	}

	return instruct[i].f;
}
