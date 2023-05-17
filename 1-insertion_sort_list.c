#include "sort.h"

void
insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *previusnode;

	if (!list)
		return;

	current = *list;
	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			previusnode = temp->prev;
			if (temp->next)
				temp->next->prev = previusnode;
			if (previusnode->prev)
				previusnode->prev->next = temp;
			else
				*list = temp;

			previusnode->next = temp->next;
			temp->prev = previusnode->prev;
			temp->next = previusnode;
			previusnode->prev = temp;


			print_list(*list);
		}
		current = current->next;
	}
}