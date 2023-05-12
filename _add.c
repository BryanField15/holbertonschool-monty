#include "monty.h"

/**
 * _add - adds the top to elements of the stack
 * @stack: the stack
 * @line_number: the line number
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
