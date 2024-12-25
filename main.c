#include "push_swap.h"

int	main()
{
	t_push_swap	*ps;
	int	data[] = {8, 3, 5, 10, 2, 4, 6, 1, 7, 9};

	ps = malloc(sizeof(t_push_swap));
	if (!ps)
		return (1);
	ps->op_count = 0;
	ps->op_capacity = 10;
	ps->ops = malloc(ps->op_capacity * sizeof(int));

	ps->a = create_stack();
	ps->b = create_stack();
	if (!ps->a || !ps->b)
	{
		free_stack(ps->a);
		free_stack(ps->b);
		free(ps);
		return (1);
	}
	flood_stack(ps->a, data, 10);

	rra(ps);
	sa(ps);
	pb(ps);
	pb(ps);
	rrr(ps);

	breakpoint(ps, ME_PS, ME_OPS, ME_END);

	free_stack(ps->a);
	free_stack(ps->b);
	free(ps);
	return (0);
}