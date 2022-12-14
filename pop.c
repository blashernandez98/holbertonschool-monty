#include "monty.h"

/**
 * pop - Removes top element of stack.
 * @head: Adress of head pointer.
 * @line_number: Monty line from which function was called.
 */

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *cursor = NULL;

	if (head && *head)
	{
		cursor = (*head)->next;
		free(*head);
		*head = cursor;
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		status = 1;
	}
}
