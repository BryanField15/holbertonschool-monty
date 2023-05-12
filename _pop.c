#include "monty.h"

/**
 * _pop - removes top elememt from the stack
 * @stack: the stack
 * @line_number: the current line number
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		printf("L%u: can't pop an stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		(*stack) = NULL;
	}
	else
	{
		(*stack) = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
