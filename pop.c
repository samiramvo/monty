#include "monty.h"
/**
 * fpop - prints the top
 * @head: stack head
 * @counter: line number
 * Return: no return
 */

void fpop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
