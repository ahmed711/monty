#include "monty.h"

/**
 * push_to_stack - check the code
 * @head: double linked list array
 * @n: int
 * @ln: line number
 * Return: Always EXIT_SUCCESS.
 */

int push_to_stack(stack_t **head, unsigned int ln, char *n)
{
	stack_t *new_node, *tmp;

	if (!atoi(n))
	{
		fprintf(stderr, "%s%d%s", "L", ln, ": usage: push integer\n");
		return (EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (EXIT_FAILURE);
	new_node->n = atoi(n);
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!head || !(*head))
	{
		*head = new_node;
		return (EXIT_SUCCESS);
	}

	tmp = *head;
	tmp->prev = new_node;
	*head = new_node;
	new_node->next = tmp;

	return (EXIT_SUCCESS);
}
