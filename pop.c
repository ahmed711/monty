#include "monty.h"

/**
 * pop - check the code
 * @head: double linked list array
 * @ln: line number
 * Return: Always EXIT_SUCCESS.
 */

int pop(stack_t **head, unsigned int ln)
{
	stack_t *tmp;

	if (!head || !head[0])
	{
		fprintf(stderr, "%s%d%s", "L", ln, ": can't pop an empty stack\n");
		return (EXIT_FAILURE);
	}
	tmp = head[0];
	free(head[0]);
	head[0] = tmp->next;

	return (EXIT_SUCCESS);
}
