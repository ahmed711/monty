#include "monty.h"

/**
 * checks - check
 * @ac: number of arguments
 * @filename: name of the file
 * Return: errors or success
 */

int checks(int ac, char *filename)
{
	FILE *fn;

	if (ac != 2)
	{
		fprintf(stderr, "%s", "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fn = fopen(filename, "r");
	if (fn == NULL)
	{
		fprintf(stderr, "%s%s%s", "Error: Can't open file ", filename, "\n");
		exit(EXIT_FAILURE);
	}
	fclose(fn);
	return (EXIT_SUCCESS);
}

/**
 * main - stat example
 * @ac: number of args
 * @av: args
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	size_t len = 0, i, output;
	char *line = NULL;
	char **args = NULL;
	FILE *fp;
	stack_t *stack = NULL;

	if (checks(ac, av[1]) != 0)
		exit(EXIT_FAILURE);

	fp = fopen(av[1], "r");
	for (i = 1; getline(&line, &len, fp) != -1; i++)
	{
		line[strlen(line) - 1] = '\0';
		args = strtow(line);
		if (args == NULL)
			continue;
		output = get_inst_func(args, i, &stack);
		if (output == EXIT_FAILURE)
			break;
	}
	free(line);
	free_stack(stack);
	fclose(fp);
	return (output);
}
