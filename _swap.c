#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: the current line number
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp_int;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	temp_int = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp_int;

}
