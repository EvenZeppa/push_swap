/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 16:54:24 by ezeppa            #+#    #+#             */
/*   Updated: 2025-01-27 16:54:24 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	prepare_args_and_size(char *args[], int *size, char ***split_args)
{
	if (*size == 1)
	{
		*split_args = ft_split(args[0], ' ');
		if (!*split_args)
			return (0);
		args = *split_args;
		*size = 0;
		while (args[*size])
			(*size)++;
	}
	return (1);
}

int	*allocate_and_fill_data(char *args[], int size)
{
	int	*data;
	int	i;

	data = malloc(sizeof(int) * size);
	if (!data)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!ft_is_int(args[i]))
		{
			free(data);
			return (NULL);
		}
		data[i] = ft_atoi(args[i]);
		i++;
	}
	return (data);
}

int	*init_data(char *args[], int *size)
{
	int		*data;
	char	**split_args;
	int		i;

	split_args = NULL;
	if (!prepare_args_and_size(args, size, &split_args))
		return (NULL);
	data = allocate_and_fill_data(args, *size);
	if (!data && split_args)
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

	formatted = malloc(sizeof(int) * size);
	if (!size || !formatted)
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
		if (tmp == -1)
			tmp = i;
		if (int_tab_count_value(data, size, data[tmp]) != 1)
			return (free(data), free(formatted), NULL);
		i++;
	}
	return (free(data), formatted);
}
