#include "push_swap.h"

// Creates a new element with the given value
t_elem	*create_elem(int value)
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

// Frees the memory allocated for the element
void	free_elem(t_elem *elem)
{
	if (elem)
	{
		unlink_elem(elem);
		free(elem);
	}
}

// Links two elements together
void	link_elem(t_elem *elem1, t_elem *elem2)
{
	if (!elem1 || !elem2)
		return ;
	if (!elem1->prev && !elem1->next)
	{
		elem1->prev = elem2;
		elem1->next = elem2;
		elem2->prev = elem1;
		elem2->next = elem1;
		return ;
	}
	elem2->prev = elem1;
	elem2->next = elem1->next;

	elem1->next->prev = elem2;
	elem1->next = elem2;
}

// Unlinks an element from its neighbors
void	unlink_elem(t_elem *elem)
{
	if (elem)
	{
		if (elem->prev && elem->prev->prev == elem)
		{
			elem->prev->next = NULL;
			elem->prev->prev = NULL;
		}
		else 
		{
			if (elem->prev)
				elem->prev->next = elem->next;
			if (elem->next)
				elem->next->prev = elem->prev;
		}
		elem->prev = NULL;
		elem->next = NULL;
	}
}