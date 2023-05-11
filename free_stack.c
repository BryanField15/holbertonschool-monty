#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: the stack
 *
 * Return: void.
 */
void free_stack(stack_t *stack)
{
	if (stack != NULL)
	{
		free_stack(stack->next);
		free(stack);
	}
}
