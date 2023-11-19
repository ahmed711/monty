#include "monty.h"

/**
 * swap - check the code
 * @head: double linked list array
 * @ln: line number
 * Return: Always EXIT_SUCCESS.
 */

int swap(stack_t **head, unsigned int ln)
{
	int tmp;

	if (!head || !head[0] || !head[0]->next)
	{
		fprintf(stderr, "%s%d%s", "L", ln, ": can't swap, stack too short\n");
		return (EXIT_FAILURE);
	}

	tmp = head[0]->n;
	head[0]->n = (head[0]->next)->n;
	(head[0]->next)->n = tmp;

	return (EXIT_SUCCESS);
}
