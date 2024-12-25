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
void print_operation_occurences(int *ops, int op_count)
{
	int	i;
	int	occurences[11] = {0};

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

// Prints the stacks
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
			case ME_OP_OCCS:
				print_operation_occurences(ps->ops, ps->op_count);
				break;
			case ME_OP_COUNT:
				ft_printf("Operation count: %d\n", ps->op_count);
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