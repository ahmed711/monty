#include "monty.h"

/**
 * pint - check the code
 * @head: double linked list array
 * @ln: line number
 * Return: Always EXIT_SUCCESS.
 */

int pint(stack_t **head, unsigned int ln)
{
	if (!head || !head[0])
	{
		fprintf(stderr, "%s%d%s", "L", ln, ": can't pint, stack empty\n");
		return (EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", head[0]->n);
		return (EXIT_SUCCESS);
	}
}
