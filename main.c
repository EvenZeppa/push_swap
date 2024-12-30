#include "push_swap.h"

void	ps_qsort(t_push_swap *ps)
{
	int	median_a;
	int	median_b;
	int	s_size;

	median_a = (ps->a->min->value + ps->a->max->value) / 2;
	median_b = ps->a->min->value + (median_a - ps->a->min->value) / 2;
	s_size = ps->a->size / 2;
	while (ps->a->size > s_size)
	{
		if (ps->a->top->value > median_a)
		{
			if (ps->b->top && ps->b->top->value < median_b)
				rr(ps);
			else
				ra(ps);
		}
		else
		{
			if (ps->b->top && ps->b->top->value < median_b)
				rb(ps);
			pb(ps);
		}
	}
}

typedef struct s_move
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;

	int	count;
}	t_move;

void	do_move_r(t_push_swap *ps, t_move *bm)
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
}

void	do_move_rr(t_push_swap *ps, t_move *bm)
{
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
}

void	move_elem_r(t_push_swap *ps, t_elem *elem, t_move *move)
{
	t_move	tmp;
	t_elem	*tmp_elem;

	tmp.rrb = 0;
	tmp.rra = 0;
	tmp.rb = itterate_prev_to_elem(ps->b, elem);
	if (elem->value > ps->a->max->value || elem->value < ps->a->min->value)
		tmp_elem = ps->a->min;
	else
		tmp_elem = find_next_elem(ps->a, elem->value);
	tmp.ra = itterate_prev_to_elem(ps->a, tmp_elem);
	tmp.count = tmp.rb > tmp.ra ? tmp.rb : tmp.ra;
	if (tmp.rb + itterate_next_to_elem(ps->a, tmp_elem) < tmp.count)
	{
		tmp.rra = itterate_next_to_elem(ps->a, tmp_elem);
		tmp.count = tmp.rb + tmp.rra;
		tmp.ra = 0;
	}
	if (move->count == -1 || tmp.count < move->count)
		*move = tmp;
}

void	move_elem_rr(t_push_swap *ps, t_elem *elem, t_move *move)
{
	t_move	tmp;
	t_elem	*tmp_elem;

	tmp.rb = 0;
	tmp.ra = 0;
	tmp.rrb = itterate_next_to_elem(ps->b, elem);
	if (elem->value > ps->a->max->value || elem->value < ps->a->min->value)
		tmp_elem = ps->a->min;
	else
		tmp_elem = find_next_elem(ps->a, elem->value);
	tmp.rra = itterate_next_to_elem(ps->a, tmp_elem);
	tmp.count = tmp.rrb > tmp.rra ? tmp.rrb : tmp.rra;
	if (tmp.rrb + itterate_prev_to_elem(ps->a, tmp_elem) < tmp.count)
	{
		tmp.ra = itterate_prev_to_elem(ps->a, tmp_elem);
		tmp.count = tmp.rrb + tmp.ra;
		tmp.rra = 0;
	}
	if (move->count == -1 || tmp.count < move->count)
		*move = tmp;
}

void	ps_turkish_sort(t_push_swap *ps)
{
	t_move	bm;
	t_move	tmp_m;
	t_elem	*current;

	while (ps->b->size)
	{
		bm.count = -1;
		move_elem_r(ps, ps->b->top, &bm);
		move_elem_rr(ps, ps->b->top, &bm);
		current = ps->b->top->next;
		while (current && current != ps->b->top)
		{
			tmp_m.count = -1;
			move_elem_r(ps, current, &tmp_m);
			move_elem_rr(ps, current, &tmp_m);
			if (tmp_m.count < bm.count)
				bm = tmp_m;
			current = current->next;
		}
		do_move_r(ps, &bm);
		do_move_rr(ps, &bm);
		pa(ps);
	}
}

void	solve(t_push_swap *ps)
{
	while (ps->a->size > 2)
	{
		ps_qsort(ps);
	}
	ps_turkish_sort(ps);
	if (ps->a->top->value > ps->a->size / 2)
		while (ps->a->top != ps->a->min)
			ra(ps);
	else
		while (ps->a->top != ps->a->min)
			rra(ps);
	// breakpoint(ps, ME_PS, ME_OP_COUNT, ME_END);
}

int	*generate_random_array(int size)
{
	int	*array;
	int	i, j, temp;
	static int r = 0;

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
	// int min_ops = -1;
	// int max_ops = -1;

	while (TRUE)
	{
		t_push_swap	*ps;

		int size = 1700;
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

		print_operations(ps->ops, ps->op_count);

		// if (min_ops == -1 || ps->op_count < min_ops)
		// 	min_ops = ps->op_count;
		// if (max_ops == -1 || ps->op_count > max_ops)
		// 	max_ops = ps->op_count;

		// ft_printf("Operations: %d, Min: %d, Max: %d\n", ps->op_count, min_ops, max_ops);
		// if (ps->op_count > 5000)
		// 	exit(0);
		breakpoint(ps, ME_OP_COUNT, ME_END);

		free_stack(ps->a);
		free_stack(ps->b);
		free(ps->ops);
		free(ps);
		free(data);
		break ;
	}
	return (0);
}