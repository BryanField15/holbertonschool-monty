#include "monty.h"

stack_t *check_op_func(stack_t *stack, char *str, unsigned int line_no)
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
		printf("opcode string was NULL");
		return (NULL);
	}
	i = 0;
	while (op_array[i].opcode != NULL)
	{
		if (strcmp(op_array[i].opcode, str) == 0)
		{
			printf("string compare success\n");

			op_array[i].f(&stack, line_no);
			return (stack);
		}
		i = i + 1;
 	}
	return (NULL);
}
