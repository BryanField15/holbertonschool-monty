#include "monty.h"

void _pall(stack_t **stack, unsigned int line_no)
{
	printf("in pall, memory address is %p\n", stack);
	//printf("this is top node [%d]", stack->n);

	stack_t *current_node;

	current_node = *stack;
	while (current_node != NULL)
	{
		printf("in pall whileoopl");
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
