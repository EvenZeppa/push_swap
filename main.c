#include "push_swap.h"

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

void	print_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
	ft_printf("\n");
}

int	get_min_num_pos(int *tab, int size)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = tab[0];
	pos = 0;
	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			pos = i;
		}
		i++;
	}
	return ((size - 1) - pos);
}

void	sort(t_push_swap *ps)
{
	int	min_pos;

	while (ps->a->top >= 0)
	{
		min_pos = get_min_num_pos(ps->a->data, &ps->a->data[ps->a->top] - &ps->a->data[0] + 1);
		while (min_pos > 0)
		{
			ra(ps);
			min_pos--;
		}
		pb(ps);
	}
	while (ps->b->top >= 0)
		pa(ps);
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
	ps.sorted = ft_memcpy(malloc(sizeof(int) * size), unsorted_data, sizeof(int) * size);
	init_operations(&ps.ops);

	flood_stack(ps.a, unsorted_data, size);
	// flood_stack(ps.a, data, size);

	sort(&ps);
	// print_ps(&ps);
	print_operations(&ps.ops);
	ft_printf("Number of operations: %d\n", ps.ops.count);


	// pb(&ps);
	// pb(&ps);
	// pb(&ps);
	
	// sa(&ps);
	// ss(&ps);

	// qsort(ps.sorted, size, sizeof(int), (int (*)(const void *, const void *))ft_strcmp);

	// print_ps(&ps);
	// print_operations(&ps.ops);
	// print_int_tab(ps.sorted, size);

	return (0);
}