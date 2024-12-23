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