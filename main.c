/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 16:43:14 by ezeppa            #+#    #+#             */
/*   Updated: 2025-01-27 16:43:14 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_push_swap *ps)
{
	if (ps->a->size <= 5)
	{
		if (ps->a->size == 1)
			return ;
		if (ps->a->size == 2 && ps->a->top->value > ps->a->top->next->value)
			sa(ps);
		else if (ps->a->size == 3)
			ps_sort_3(ps);
		else if (ps->a->size == 4)
			ps_sort_4(ps);
		else if (ps->a->size == 5)
			ps_sort_5(ps);
		return ;
	}
	if (!stack_is_sorted(ps->a))
		while (ps->a->size > 2)
			ps_qsort(ps);
	ps_turkish_sort(ps);
	if (ps->a->top->value > ps->a->size / 2)
		while (ps->a->top != ps->a->min)
			ra(ps);
	else
		while (ps->a->top != ps->a->min)
			rra(ps);
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
		return (free_stack(ps->a), free_stack(ps->b), free(ps)
			, ft_printf("Error\n"), 1);
	data = formatted_data(data, size);
	if (!data)
		return (free_stack(ps->a), free_stack(ps->b), free(ps)
			, ft_printf("Error\n"), 1);
	flood_stack(ps->a, data, size);
	solve(ps);
	print_operations(ps->ops, ps->op_count);
	free_stack(ps->a);
	free_stack(ps->b);
	return (free(ps->ops), free(ps), free(data), 0);
}
