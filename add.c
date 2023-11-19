#include "monty.h"

/**
 * add - check the code
 * @head: double linked list array
 * @ln: line number
 * Return: Always EXIT_SUCCESS.
 */

int add(stack_t **head, unsigned int ln)
{
	if (!head || !head[0] || !head[0]->next)
	{
		fprintf(stderr, "%s%d%s", "L", ln, ": can't add, stack too short\n");
		return (EXIT_FAILURE);
	}

	(head[0]->next)->n += head[0]->n;
	pop(head, ln);

	return (EXIT_SUCCESS);
}
