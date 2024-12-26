#include "push_swap.h"

typedef struct s_best_move
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;

	int	stack_push;
	int	count;
}	t_best_move;

void stack_ra_best_move(t_stack *stack_a, t_stack *stack_b, t_best_move *bm, int sens)
{
	t_elem *top_need = NULL;
	t_best_move	tmp_bm;
	int	min_rb;
	int	min_rrb;

	tmp_bm.ra = 0;
	tmp_bm.rra = 0;
	tmp_bm.rb = -1;
	tmp_bm.rrb = -1;

	while (TRUE)
	{
		// if (stack_a->size > 50 && find_next_by_index(stack_a, tmp_bm.ra)->value > 450)
		// 	tmp_bm.ra++;

		if (sens == 1)
		{
			if (find_prev_by_index(stack_a, tmp_bm.ra)->value > stack_b->max->value || find_prev_by_index(stack_a, tmp_bm.ra)->value < stack_b->min->value)
				top_need = stack_b->max;
			else
				top_need = find_prev_elem(stack_b, find_prev_by_index(stack_a, tmp_bm.ra)->value);
		}
		else
		{
			if (find_prev_by_index(stack_a, tmp_bm.ra)->value > stack_b->max->value || find_prev_by_index(stack_a, tmp_bm.ra)->value < stack_b->min->value)
				top_need = stack_b->min;
			else
				top_need = find_next_elem(stack_b, find_prev_by_index(stack_a, tmp_bm.ra)->value);
		}
		min_rb = itterate_prev_to_elem(stack_b, top_need);
		min_rrb = itterate_next_to_elem(stack_b, top_need);
		
		// ft_printf("RA prev_value: %d min_rb: %d min_rrb: %d\n", find_prev_by_index(stack_a, tmp_bm.rra)->value, min_rb, min_rrb);

		tmp_bm.count = (tmp_bm.ra <= min_rb ? min_rb : tmp_bm.ra);
		if (bm->stack_push == 0 || tmp_bm.count < bm->count)
		{
			bm->ra = tmp_bm.ra;
			bm->rra = tmp_bm.rra;
			bm->rb = min_rb;
			bm->rrb = 0;
			bm->stack_push = sens;
			bm->count = tmp_bm.count;
		}
		tmp_bm.count = tmp_bm.ra + min_rrb;
		if (tmp_bm.count < bm->count)
		{
			bm->ra = tmp_bm.ra;
			bm->rra = tmp_bm.rra;
			bm->rb = 0;
			bm->rrb = min_rrb;
			bm->stack_push = sens;
			bm->count = tmp_bm.count;
		}

		// if (tmp_bm.ra > tmp_bm.rb || tmp_bm.ra > tmp_bm.rrb)
		if (tmp_bm.ra >= 200 || stack_a->size == 1)
			break ;
		tmp_bm.ra++;
	}
}

void stack_rra_best_move(t_stack *stack_a, t_stack *stack_b, t_best_move *bm, int sens)
{
	t_elem *top_need = NULL;
	t_best_move	tmp_bm;
	int	min_rb;
	int	min_rrb;

	tmp_bm.ra = 0;
	tmp_bm.rra = 0;
	tmp_bm.rb = -1;
	tmp_bm.rrb = -1;

	while (TRUE)
	{
		// if (stack_a->size > 50 && find_next_by_index(stack_a, tmp_bm.rra)->value > 450)
		// 	tmp_bm.rra++;
		if (sens == 1)
		{
			if (find_next_by_index(stack_a, tmp_bm.rra)->value > stack_b->max->value || find_next_by_index(stack_a, tmp_bm.rra)->value < stack_b->min->value)
				top_need = stack_b->max;
			else
				top_need = find_prev_elem(stack_b, find_next_by_index(stack_a, tmp_bm.rra)->value);
		}
		else
		{
			if (find_next_by_index(stack_a, tmp_bm.rra)->value > stack_b->max->value || find_next_by_index(stack_a, tmp_bm.rra)->value < stack_b->min->value)
				top_need = stack_b->min;
			else
				top_need = find_next_elem(stack_b, find_next_by_index(stack_a, tmp_bm.rra)->value);
		}
		min_rb = itterate_prev_to_elem(stack_b, top_need);
		min_rrb = itterate_next_to_elem(stack_b, top_need);
		
		// ft_printf("RRA prev_value: %d min_rb: %d min_rrb: %d\n", find_prev_by_index(stack_a, tmp_bm.rra)->value, min_rb, min_rrb);

		tmp_bm.count = (tmp_bm.rra <= min_rrb ? min_rrb : tmp_bm.rra);
		if (bm->stack_push == 0 || tmp_bm.count < bm->count)
		{
			bm->ra = 0;
			bm->rra = tmp_bm.rra;
			bm->rb = 0;
			bm->rrb = min_rrb;
			bm->stack_push = sens;
			bm->count = tmp_bm.count;
		}
		tmp_bm.count = tmp_bm.rra + min_rb;
		if (tmp_bm.count < bm->count)
		{
			bm->ra = 0;
			bm->rra = tmp_bm.rra;
			bm->rb = min_rb;
			bm->rrb = 0;
			bm->stack_push = sens;
			bm->count = tmp_bm.count;
		}

		// if (tmp_bm.rra > tmp_bm.rb || tmp_bm.rra > tmp_bm.rrb)
		if (tmp_bm.rra >= 200 || stack_a->size == 1)
			break ;
		tmp_bm.rra++;
	}
}

void	do_best_move(t_push_swap *ps, t_best_move *bm)
{
	while (bm->ra > 0 || bm->rb > 0)
	{
		if (bm->ra > 0 && bm->rb > 0)
		{
			rr(ps);
			bm->ra--;
			bm->rb--;
		}
		else if (bm->ra > 0)
		{
			ra(ps);
			bm->ra--;
		}
		else
		{
			rb(ps);
			bm->rb--;
		}
	}
	while (bm->rra > 0 || bm->rrb > 0)
	{
		if (bm->rra > 0 && bm->rrb > 0)
		{
			rrr(ps);
			bm->rra--;
			bm->rrb--;
		}
		else if (bm->rra > 0)
		{
			rra(ps);
			bm->rra--;
		}
		else
		{
			rrb(ps);
			bm->rrb--;
		}
	}

	if (bm->stack_push == 1)
		pb(ps);
	else
		pa(ps);
}

void	do_rbest_move(t_push_swap *ps, t_best_move *bm)
{
	while (bm->ra > 0 || bm->rb > 0)
	{
		if (bm->ra > 0 && bm->rb > 0)
		{
			rr(ps);
			bm->ra--;
			bm->rb--;
		}
		else if (bm->ra > 0)
		{
			rb(ps);
			bm->ra--;
		}
		else
		{
			ra(ps);
			bm->rb--;
		}
	}
	while (bm->rra > 0 || bm->rrb > 0)
	{
		if (bm->rra > 0 && bm->rrb > 0)
		{
			rrr(ps);
			bm->rra--;
			bm->rrb--;
		}
		else if (bm->rra > 0)
		{
			rrb(ps);
			bm->rra--;
		}
		else
		{
			rra(ps);
			bm->rrb--;
		}
	}

	if (bm->stack_push == 1)
		pb(ps);
	else
		pa(ps);
}

void solve(t_push_swap *ps)
{
	t_best_move bm;

	while (ps->a->size > 250)
	{
		if (ps->a->top->value > 250)
			pb(ps);
		else
			ra(ps);
	}
	while (ps->b->size > 2)
		pa(ps);

	// breakpoint(ps, ME_PS, ME_END);

	while (ps->a->size > 0)
	{
		bm.ra = -1;
		bm.rra = -1;
		bm.rb = -1;
		bm.rrb = -1;
		bm.stack_push = 0;

		stack_ra_best_move(ps->a, ps->b, &bm, 1);
		stack_rra_best_move(ps->a, ps->b, &bm, 1);

		// ft_printf("ra: %d rra: %d rb: %d rrb: %d\n", bm.ra, bm.rra, bm.rb, bm.rrb);

		do_best_move(ps, &bm);

		// if (!(ps->b->top < find_next_by_index(ps->b, 1) && ps->b->top > find_prev_by_index(ps->b, 1)))
			// breakpoint(ps, ME_PS, ME_END);
	}
	// breakpoint(ps, ME_PS, ME_END);
	// while (ps->a->size > 2)
	// 	pb(ps);
	// pa(ps);
	// pa(ps);
	// if (ps->a->top->value > ps->a->top->prev->value)
	// 	sa(ps);
	// while (ps->b->size > 0)
	// {
	// 	bm.ra = -1;
	// 	bm.rra = -1;
	// 	bm.rb = -1;
	// 	bm.rrb = -1;
	// 	bm.stack_push = 0;

	// 	stack_ra_best_move(ps->b, ps->a, &bm, 2);
	// 	stack_rra_best_move(ps->b, ps->a, &bm, 2);
	// 	// breakpoint(ps, ME_PS, ME_END);

	// 	// ft_printf("ra: %d rra: %d rb: %d rrb: %d\n", bm.ra, bm.rra, bm.rb, bm.rrb);

	// 	do_rbest_move(ps, &bm);

	// 	// if (!(ps->b->top < find_next_by_index(ps->b, 1) && ps->b->top > find_prev_by_index(ps->b, 1)))
	// 		// breakpoint(ps, ME_PS, ME_END);
	// }
	// if (ps->a->top->value > ps->a->size / 2)
	// 	while (find_min_elem(ps->a) != ps->a->top)
	// 		rra(ps);
	// else
	// 	while (find_min_elem(ps->a) != ps->a->top)
	// 		ra(ps);
	if (ps->b->top->value > ps->b->size / 2)
		while (find_max_elem(ps->b) != ps->b->top)
			rrb(ps);
	else
		while (find_max_elem(ps->b) != ps->b->top)
			rb(ps);
	while (ps->b->size > 0)
		pa(ps);
	
	// breakpoint(ps, ME_PS, ME_OP_OCCS, ME_OP_COUNT, ME_END);
	// breakpoint(ps, ME_OP_COUNT, ME_END);
}

// Generates an array of numbers between 1 and 500 in random order
int	*generate_random_array(int size)
{
	int	*array;
	int	i, j, temp;
	static int r = 0;

	if (size > 500)
		return (NULL);

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = i + 1;

	srand(time(NULL) + r++);
	for (i = size - 1; i > 0; i--)
	{
		j = rand() % (i + 1);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}

	return (array);
}

int	main()
{
	while (TRUE)
	{
		t_push_swap	*ps;
		// int	data[] = {8, 3, 5, 10, 2, 4, 6, 1, 7, 9};
		int size = 500;
		int	*data = generate_random_array(size);

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
		flood_stack(ps->a, data, size);
		
		solve(ps);

		ft_printf("%d\n", ps->op_count);
		if (ps->op_count > 5500)
		{
			exit(1);
		}

		free_stack(ps->a);
		free_stack(ps->b);
		free(ps);
		free(data);
	}
	return (0);
}