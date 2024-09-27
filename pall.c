#include "monty.h"
/**
 * pall - print all nodes in the stack
 * @stack: double pointer to the head
 * @line_number: line (number) we're handling
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	if (tmp == NULL)
		return;
	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
