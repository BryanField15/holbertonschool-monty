#include "monty.h"

void _pall(stack_t **stack, unsigned int line_no)
{
	while (stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}

}
