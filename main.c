#include "monty.h"
char **opNFunc = NULL;
/**
 * main - handle the Monty language
 * @argc: argument count
 * @argv: argument vector(an array with all args)
 * Return: exit status
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	ssize_t read;
	char *lineptr = NULL;
	size_t len = 0;
	unsigned int numOfLines = 1;

	(void)opNFunc;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&lineptr, &len, fp)) != -1)
	{
		if (read == 0 || (lineptr[0] == '\n' || lineptr[0] == '\t'))
			continue;
		if (lineptr[0] == '#')
			continue;
		numOfLines++;
		if (lineptr[read - 1] == '\n' || lineptr[read - 1] == '$')
			lineptr[read - 1] = '\0';
		handle_lines(&lineptr, numOfLines);
	}
	if (read == -1 && !feof(fp))
		exit(EXIT_FAILURE);
	fclose(fp);
	if (lineptr)
		free(lineptr);
	return (EXIT_SUCCESS);
}
