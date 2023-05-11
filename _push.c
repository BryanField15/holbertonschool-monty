#include "monty.h"

/**
 *
 *
 *
 *
 */

void _push(stack_t **stack, unsigned int line_number)
{


	printf("memory address of stack head: [%p]\n", stack);

	printf("global var in _push func: %d\n", g_push_arg);
	printf("memory address of stack head: [%p]\n", stack);

	printf("we are in the push func\n");
	stack_t *new_node;

	if (stack == NULL)
	{
		printf("in push the stack is null\n");
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	new_node = malloc(sizeof(new_node));
	if (new_node == NULL)
	{
		return;
	}
	printf("new node address %p", new_node);
	new_node->n = g_push_arg;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
	printf("this the is new node [%d]\n",(*stack)->n);
//	while (*stack != NULL)
//	{
	printf("second node %d\n", (*stack)->n);
	if ((*stack)->next != NULL)
	{
		printf("From node %d\n", (*stack)->next->n);
	}


//		*stack = (*stack)->next;
//	}
	printf("memory address of stack head end: [%p]\n", stack);

}
