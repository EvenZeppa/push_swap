/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metric.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 16:43:23 by ezeppa            #+#    #+#             */
/*   Updated: 2025-01-27 16:43:23 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Prints the operations
void	print_operations(int *ops, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_printf("%s\n", OP_STR(ops[i]));
		i++;
	}
}

// Prints the operation occurences
void	print_operation_occurences(int *ops, int op_count)
{
	int	i;
	int	occurences[11];

	ft_bzero(occurences, sizeof(occurences));
	i = 0;
	while (i < op_count)
	{
		occurences[ops[i]]++;
		i++;
	}
	ft_printf(
		"--------------------------------------\n"
		"|     Operation Occurences           |\n"
		"--------------------------------------\n"
		);
	i = 0;
	while (i < 11)
	{
		ft_printf("|   %-13s -> %-13d   |\n", OP_STR(i), occurences[i]);
		i++;
	}
	ft_printf("--------------------------------------\n");
}

void	print_line_ps(t_push_swap *ps, int i)
{
	t_elem	*elem_a;
	t_elem	*elem_b;

	elem_a = ps->a->top;
	elem_b = ps->b->top;
	while (i > 0)
	{
		if (i <= ps->a->size && elem_a)
		{
			ft_printf("|   % -12d  |", elem_a->value);
			elem_a = elem_a->prev;
		}
		else
			ft_printf("|                 |");
		if (i <= ps->b->size && elem_b)
		{
			ft_printf("|   % -12d  |\n", elem_b->value);
			elem_b = elem_b->prev;
		}
		else
			ft_printf("|                 |\n");
		i--;
	}
}

// Prints the stacks
void	print_ps(t_push_swap *ps)
{
	int		i;

	if (ps->a->size > ps->b->size)
		i = ps->a->size;
	else
		i = ps->b->size;
	ft_printf(
		"--------------------------------------\n"
		"|     Stack A     ||     Stack B     |\n"
		"--------------------------------------\n"
		);
	print_line_ps(ps, i);
	ft_printf("--------------------------------------\n");
}

void	breakpoint(t_push_swap *ps, ...)
{
	va_list	args;
	int		metric;
	char	buf[1];

	va_start(args, ps);
	metric = va_arg(args, int);
	while (metric != ME_END)
	{
		if (metric == ME_PS)
			print_ps(ps);
		else if (metric == ME_OPS)
			print_operations(ps->ops, ps->op_count);
		else if (metric == ME_OP_OCCS)
			print_operation_occurences(ps->ops, ps->op_count);
		else if (metric == ME_OP_COUNT)
			ft_printf("Operation count: %d\n", ps->op_count);
		else
			break ;
		metric = va_arg(args, int);
	}
	va_end(args);
	ft_printf("Press any key to continue...\n");
	read(STDIN_FILENO, buf, 1);
}
