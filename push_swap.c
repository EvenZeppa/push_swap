#include "push_swap.h"

// Initializes the push_swap structure with the given stack
void	init_push_swap(t_push_swap *ps, int *stack, int size)
{
	ps->size = size;
	ps->a = create_stack(size);
	ps->b = create_stack(size);
	ps->sorted = ft_memcpy(malloc(sizeof(int) * size), stack, sizeof(int) * size);
	ps->cmp = malloc(sizeof(int) * size);
	ft_qsort_int(&ps->sorted, size);
	rev_int_tab(ps->sorted, size);
	flood_stack(ps->a, stack, size);
	ps->cmp = cmp_int_tab(ps->a->data, ps->sorted, ps->size);
	init_operations(&ps->ops);
}

// Frees the memory allocated for the push_swap structure
void	free_push_swap(t_push_swap *ps)
{
	free_operations(&ps->ops);
	free_stack(ps->a);
	free_stack(ps->b);
	free(ps->cmp);
}

// Updates the comparison array in the push_swap structure
void	update_cmp(t_push_swap *ps)
{
	int	size = ps->size;
	int	*cmp = ps->cmp;
	int	i = 0;
	int	j = ps->b->top;
	int	k;

	while (i <= ps->a->top)
	{
		k = 0;
		while (k < size)
		{
			if (ps->a->data[i] == ps->sorted[k])
			{
				cmp[i] = k - i;
				break ;
			}
			k++;
		}
		i++;
	}
	while (j >= 0)
	{
		k = 0;
		while (k < size)
		{
			if (ps->b->data[j] == ps->sorted[k])
			{
				cmp[i] = k - i;
				break ;
			}
			k++;
		}
		i++;
		j--;
	}
}

// Prints the current state of the push_swap stacks
void	print_ps(t_push_swap *ps)
{
	int	i;

	i = (ps->a->top > ps->b->top) ? ps->a->top : ps->b->top;

	ft_printf(
		"--------------------------------------\n"
		"|     Stack A     ||     Stack B     |\n"
		"--------------------------------------\n"
	);

	while (i >= 0)
	{
		if (i <= ps->a->top)
			ft_printf("|   % -12d  |", ps->a->data[i]);
		else
			ft_printf("|                 |");
		if (i <= ps->b->top)
			ft_printf("|   % -12d  |\n", ps->b->data[i]);
		else
			ft_printf("|                 |\n");
		i--;
	}

	ft_printf("--------------------------------------\n");
}