#include "monty.h"

void _pop(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL)
	{
		printf("L%u: can't pop an stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		(*stack) = NULL;
	}
	else
	{
		(*stack) = (*stack)->next;
		free ((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
