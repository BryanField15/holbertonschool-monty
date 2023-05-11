#include "monty.h"

void _pall(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;

	printf("pall function L5\tstack: [%p]\n",stack);

	if (*stack == NULL)
	{
		return;
	}
	printf("pall function L13\t*stack: [%p]\n", *stack);
	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

}
