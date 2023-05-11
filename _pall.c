#include "monty.h"

/**
 * _pall - prints the stack
 * @stack: the stack
 * @line_number: line number
 * Return: void
 *
 */
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		return;
	}
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
