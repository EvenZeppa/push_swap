#include "push_swap.h"

// int	*generate_random_array(int size)
// {
// 	int	*array;
// 	int	i, j, temp;
// 	static int r = 0;

// 	array = malloc(sizeof(int) * size);
// 	if (!array)
// 		return (NULL);

// 	for (i = 0; i < size; i++)
// 		array[i] = i + 1;

// 	srand(time(NULL) + r++);
// 	for (i = size - 1; i > 0; i--)
// 	{
// 		j = rand() % (i + 1);
// 		temp = array[i];
// 		array[i] = array[j];
// 		array[j] = temp;
// 	}

// 	return (array);
// }

t_push_swap	*init_ps(void)
{
	t_push_swap	*ps;

	ps = malloc(sizeof(t_push_swap));
	if (!ps)
		return (NULL);
	ps->op_count = 0;
	ps->op_capacity = 10;
	ps->ops = NULL;
	ps->a = create_stack();
	ps->b = create_stack();
	if (!ps->a || !ps->b)
	{
		free_stack(ps->a);
		free_stack(ps->b);
		free(ps);
		return (NULL);
	}
	return (ps);
}

int *init_data(char *args[], int *size)
{
	int *data;
	int i;
	char **split_args;

	split_args = NULL;
	if ((*size) == 1)
	{
		split_args = ft_split(args[0], ' ');
		args = split_args;
		i = 0;
		while (args[i])
			i++;
		(*size) = i;
	}
	data = malloc(sizeof(int) * (*size));
	if (!data)
		return (NULL);
	i = 0;
	while (i < (*size))
	{
		if (!ft_is_int(args[i]))
			return (free(data), NULL);
		data[i] = ft_atoi(args[i]);
		i++;
	}
	if (split_args)
	{
		i = 0;
		while (split_args[i])
			free(split_args[i++]);
		free(split_args);
	}
	return (data);
}

int	*formatted_data(int *data, int size)
{
	int	*formatted;
	int	nb;
	int	tmp;
	int	i;

	if (size == 0)
		return (data);
	formatted = malloc(sizeof(int) * size);
	if (!formatted)
		return (free(data), NULL);
	nb = 1;
	tmp = int_tab_min_index(data, size);
	formatted[tmp] = nb++;
	i = 0;
	while (i < size - 1)
	{
		tmp = int_tab_next_index(data, size, data[tmp]);
		if (tmp != -1)
			formatted[tmp] = nb++;
		if (int_tab_count_value(data, size, data[tmp]) != 1)
			return (free(data), free(formatted), NULL);
		i++;
	}
	return (free(data), formatted);
}

int	main(int argc, char *argv[])
{
	t_push_swap	*ps;
	int			*data;
	int			size;

	if (argc == 1)
		return (1);
	ps = init_ps();
	if (!ps)
		return (ft_printf("Error\n"), 1);
	size = argc - 1;
	data = init_data(&argv[1], &size);
	if (!data)
		return (free(ps), ft_printf("Error\n"), 1);
	data = formatted_data(data, size);
	if (!data)
		return (free(ps), ft_printf("Error\n"), 1);
	flood_stack(ps->a, data, size);
	solve(ps);
	print_operations(ps->ops, ps->op_count);
	free_stack(ps->a);
	free_stack(ps->b);
	free(ps->ops);
	free(ps);
	free(data);
	return (0);
}
