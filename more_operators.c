#include "monty.h"

/**
 * sub - Substracts top two elements of stack.
 * @head: Adress of head pointer of stack.
 * @line_number: Line of monty file.
 */

void sub(stack_t **head, unsigned int line_number)
{
	if (head)
	{
		if (*head && (*head)->next)
		{
			((*head)->next)->n -= (*head)->n;
			pop(head, line_number);
		}
		else
		{
			free_stack(head);
			fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
			status = 1;
		}
	}
}

/**
 * division - Divides second top elements of stack by the top element.
 * @head: Adress of head pointer of stack.
 * @line_number: Line of monty file.
 */

void division(stack_t **head, unsigned int line_number)
{
	if (head)
	{
		if (*head && (*head)->next)
		{
			if ((*head)->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line_number);
				status = 1;
				return;
			}
			((*head)->next)->n /= (*head)->n;
			pop(head, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
			status = 1;
		}
	}
}

/**
 * mul - Multiplies top two elements of stack.
 * @head: Adress of head pointer of stack.
 * @line_number: Line of monty file.
 */

void mul(stack_t **head, unsigned int line_number)
{
	if (head)
	{
		if (*head && (*head)->next)
		{
			((*head)->next)->n *= (*head)->n;
			pop(head, line_number);
		}
		else
		{
			free_stack(head);
			fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
			status = 1;
		}
	}
}

/**
 * mod - Mod of second top element of stack by top element.
 * @head: Adress of head pointer of stack.
 * @line_number: Line of monty file.
 */

void mod(stack_t **head, unsigned int line_number)
{
	if (head)
	{
		if (*head && (*head)->next)
		{
			if ((*head)->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line_number);
				status = 1;
				return;
			}
			((*head)->next)->n %= (*head)->n;
			pop(head, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
			status = 1;
		}
	}
}

/**
 * pchar - Prints char at top of the stack.
 * @head: Adress of head pointer to stack.
 * @line_number: Line of monty file.
 */

void pchar(stack_t **head, unsigned int line_number)
{
	if (head)
	{
		if (*head && (*head)->n)
		{
			if ((*head)->n < 0 || (*head)->n > 127)
			{
				fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
				status = 1;
				return;
			}
			printf("%c\n", (*head)->n);
		}
		else
		{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			status = 1;
		}
	}
}
