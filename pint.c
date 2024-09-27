#include "monty.h"
/**
 * pint - print value at the top of the stack
 * @stack: double pointer to the head
 * @line_number: line number we're handling
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", tmp->n);
}
/**
 * pop - remove the top element
 * @stack: double pointer to the head
 * @line_number: line numbwer we're handling
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *firstNode;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	firstNode = *stack;
	*stack = firstNode->next;
	while (*stack != NULL)
		(*stack)->prev = NULL;
	free(firstNode);
}
