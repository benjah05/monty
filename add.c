#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the head
 * @line_number: line number we're on
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *tmp = *stack, *firstNode = *stack;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = tmp->n + (tmp->next)->n;
	tmp->next->n = sum;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(firstNode);
}
/**
 * nop - nop does nothing
 * @stack: double pointer to the head
 * @line_number: line number we're on
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub - subtract the top elemenet from the second
 * @stack: double pointer to the first element
 * @line_number: line muber we're on
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int diff;
	stack_t *tmp = *stack, *firstNode = *stack;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = (tmp->next)->n - tmp->n;
	tmp->next->n = diff;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(firstNode);
}
