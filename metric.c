#include "push_swap.h"

void	print_operations(int *ops, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		switch (ops[i])
		{
			case OP_SA:
				ft_printf("sa\n");
				break;
			case OP_SB:
				ft_printf("sb\n");
				break;
			case OP_SS:
				ft_printf("ss\n");
				break;
			case OP_PA:
				ft_printf("pa\n");
				break;
			case OP_PB:
				ft_printf("pb\n");
				break;
			case OP_RA:
				ft_printf("ra\n");
				break;
			case OP_RB:
				ft_printf("rb\n");
				break;
			case OP_RR:
				ft_printf("rr\n");
				break;
			case OP_RRA:
				ft_printf("rra\n");
				break;
			case OP_RRB:
				ft_printf("rrb\n");
				break;
			case OP_RRR:
				ft_printf("rrr\n");
				break;
			default:
				break;
		}
		i++;
	}
}

void	print_ps(t_push_swap *ps)
{
	int	i;
	t_elem	*elem_a;
	t_elem	*elem_b;

	i = (ps->a->size > ps->b->size) ? ps->a->size : ps->b->size;

	ft_printf(
		"--------------------------------------\n"
		"|     Stack A     ||     Stack B     |\n"
		"--------------------------------------\n"
	);

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

	ft_printf("--------------------------------------\n");
}

void	breakpoint(t_push_swap *ps, ...)
{
	va_list	args;
	int		metric;

	va_start(args, ps);
	while ((metric = va_arg(args, int)))
	{
		switch (metric)
		{
			case ME_PS:
				print_ps(ps);
				break;
			case ME_OPS:
				print_operations(ps->ops, ps->op_count);
				break;
			// case ME_OP_OCCS:
			// 	print_operation_recurence(&ps->ops);
			// 	break;
			// case ME_OP_COUNT:
			// 	ft_printf("Operation count: %d\n", ps->ops.count);
				break;
			default:
				break;
		}
	}
	va_end(args);
	// Wait until the user presses a key
	ft_printf("Press any key to continue...\n");
	getchar();
}