#include "monty.h"

void check_op_func(stack_t **stack, char *str, unsigned int line_number)
{
	int i;

	instruction_t op_array[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	if (str == NULL)
	{
		return;
	}
	i = 0;
	while (op_array[i].opcode != NULL)
	{
		if (strcmp(op_array[i].opcode, str) == 0)
		{
			op_array[i].f(stack, line_number);
			return;
		}
		i = i + 1;
 	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
	exit(EXIT_FAILURE);
}
