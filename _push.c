#include "monty.h"

//extern int g_push_arg;

void _push(stack_t **stack, unsigned int line_no)
{
//	extern int g_push_arg;
//	int i = 6;

	printf("global var in _push func: %d\n", g_push_arg);

	printf("we are in the push func\n");
	stack_t *new_node;

	if (stack == NULL)
	{
		return;
	}
	printf("line 20 flag\n");
	new_node = malloc(sizeof(new_node));
	if (new_node == NULL)
	{
		return;
	}
	printf("line 25 flag\n");
	new_node->n = g_push_arg;
	printf("line 27 flag\n");
	new_node->next = *stack;
	printf("line 29 flag\n");
	new_node->prev = NULL;
	printf("line 30 flag\n");
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
	printf("line 36 flag\n");
	printf("this the is new node [%d]",(*stack)->n);
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	printf("line 44 flag\n");

}
