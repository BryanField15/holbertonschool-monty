#include "monty.h"

int check_op_func(char *str, unsigned int line_no)
{
	int i;
	stack_t **stack = NULL;

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
	i = 0;
	while (op_array[i].opcode != NULL)
	{
		if (strcmp(op_array[i].opcode, str) == 0)
		{
			printf("string compare success");
			op_array[i].f(stack, line_no);
			return (0);
		}
		i = i + 1;
 	}
	return (1);
}
