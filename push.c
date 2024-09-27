#include "monty.h"
/**
 * push - push an element to the stack
 * @stack: pointer to the first node(the head)
 * @line_number: line number we're handling
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int argInt;
	stack_t *newNode;

	if (opNFunc[1] != NULL)
	{
		argInt = atoi(opNFunc[1]);
		if (argInt == 0 && strcmp(opNFunc[1], "0") != 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = argInt;
	if (*stack == NULL)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		*stack = newNode;
	}
	else
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
		*stack = newNode;
	}
}
