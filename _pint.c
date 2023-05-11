#include "monty.h"

/**
 * _pint - prints the first element of the stack
 * @stack: the stack
 * @line_number: the current line number
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
