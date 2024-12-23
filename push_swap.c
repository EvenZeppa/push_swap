#include "push_swap.h"

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

void	rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
}

int	main()
{
	int	unsorted_data[] = {8, 3, 5, 1, 9, 2, 4, 7, 6, 10};


	int	data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	size = sizeof(data) / sizeof(data[0]);

	rev_int_tab(unsorted_data, size);
	rev_int_tab(data, size);

	t_push_swap	ps;
	ps.a = create_stack(size);
	ps.b = create_stack(size);

	flood_stack(ps.a, unsorted_data, size);
	// flood_stack(ps.a, data, size);

	print_ps(&ps);

	return (0);
}