#include "monty.h"

/**
 *
 *
 *
 *
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	new_node = malloc(sizeof(new_node));
	if (new_node == NULL)
	{
		return;
	}
	new_node->n = g_push_arg;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
