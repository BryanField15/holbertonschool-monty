#include "monty.h"

/**
 * check_op_func - checks opcode against known functions
 * @stack: the stack
 * @line_number: the current line number
 * @str: opcode string
 * Return: void
 */
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
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
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
