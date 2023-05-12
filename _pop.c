#include "monty.h"

/**
 * _pop - removes top elememt from the stack
 * @stack: the stack
 * @line_number: the current line number
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		(*stack) = NULL;
	}
	else
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
		(*stack)->prev = NULL;
	}
}
