#include "monty.h"

/**
 * print_stack - check the code
 * @h: double linked list
 * Description: print
 * Return: Always EXIT_SUCCESS.
 */

int print_stack(const stack_t *h)
{
	stack_t *tmp;

	tmp = (stack_t *) h;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
