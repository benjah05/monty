#include "monty.h"
/**
 * handle_lines - read lines and determine opcode and argument
 * @line: double pointer to the line
 * @numLines: line number we're handling
 * Return: void
 */
void handle_lines(char **line, unsigned int numLines)
{
	char *opcmdV[3], *cmd;
	int i = 0;

	cmd = strtok(*line, " $");
	while (cmd != NULL && i < 3)
	{
		opcmdV[i++] = cmd;
		cmd = strtok(NULL, " $");
	}
	opcmdV[i] = NULL;
	opNFunc = opcmdV;
	handle_opcodes(numLines);
}
/**
 * handle_opcodes - handle opcodes and their functions
 * @numLines: line number we're handling
 * Return: void
 */
void handle_opcodes(unsigned int numLines)
{
	instruction_t i[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", custom_div},
		{"mul", mul},
		{"mod", mod},
		{"swap", swap},
		{NULL, NULL}
	};
	int a = 0;
	static stack_t *stack = NULL;

	while (i[a].opcode != NULL)
	{
		if (strcmp(i[a].opcode, opNFunc[0]) == 0)
		{
			i[a].f(&stack, numLines);
			break;
		}
		a++;
	}
}
