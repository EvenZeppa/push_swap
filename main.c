#include "push_swap.h"

typedef struct s_best_move
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
}	t_best_move;

int	get_tab_max(int *tab, int size)
{
	int	max;
	int	i;

	max = tab[0];
	i = 1;
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	get_tab_min(int *tab, int size)
{
	int	min;
	int	i;

	min = tab[0];
	i = 1;
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int	nb_r_to_insert(int *data, int insert, int size)
{
	int	count = 0;

	if (insert > get_tab_max(data, size) || insert < get_tab_min(data, size))
		while (data[(size - 1) - count] != get_tab_max(data, size))
			count++;
	else
	{
		if (insert > data[size - 1] && insert < data[0])
			return (0);
		while (!(insert < data[(size - 1) - count] && insert > data[size - 2 - count]))
			count++;
		count++;
	}
	return (count);
}

int nb_rr_to_insert(int *data, int insert, int size)
{
	int	count = 0;

	if (insert > get_tab_max(data, size) || insert < get_tab_min(data, size))
		while (data[count] != get_tab_min(data, size))
			count++;
	else
	{
		if (insert > data[size - 1] && insert < data[0])
			return (0);
		while (!(insert > data[count] && insert < data[count + 1]))
			count++;
		count++;
	}
	return (count);
}

// int get_minus_ra(t_push_swap *ps, t_best_move *best_move)
// {
// 	int min_ra = -1;
// 	int min_rb = -1;
// 	int min_rrb = -1;
// 	int tmp_ra = 0;
// 	int tmp_rb;
// 	int tmp_rrb;

// 	while (TRUE)
// 	{
// 		tmp_rb = nb_r_to_insert(ps->b->data, ps->a->data[ps->a->top - tmp_ra], ps->b->top + 1);
// 		if (min_rb == -1 || tmp_ra + tmp_rb < min_rb)
// 		{
// 			min_ra = tmp_ra;
// 			min_rb = tmp_rb;
// 		}
// 		tmp_rrb = nb_rr_to_insert(ps->b->data, ps->a->data[ps->a->top - tmp_ra], ps->b->top + 1);
// 		if (min_rrb == -1 || tmp_ra + tmp_rrb < min_rrb)
// 		{
// 			min_ra = tmp_ra;
// 			min_rrb = tmp_rrb;
// 		}
// 		if (tmp_ra >= min_rrb || tmp_ra >= min_rb)
// 			return (best_move->ra = min_ra, best_move->ra_rb = min_rb, best_move->ra_rrb = min_rrb, min_ra);
// 		tmp_ra++;
// 	}
// }

// int get_minus_rra(t_push_swap *ps, t_best_move *best_move)
// {
// 	int min_rra = 0;
// 	int min_rb;
// 	int min_rrb;
// 	int tmp_rra = 0;
// 	int tmp_rb;
// 	int tmp_rrb;

// 	min_rb = nb_r_to_insert(ps->b->data, ps->a->data[ps->a->top], ps->b->top + 1);
// 	min_rrb = nb_rr_to_insert(ps->b->data, ps->a->data[ps->a->top], ps->b->top + 1);
// 	while (TRUE)
// 	{
// 		tmp_rb = nb_r_to_insert(ps->b->data, ps->a->data[tmp_rra], ps->b->top + 1);
// 		if (tmp_rra + 1 + tmp_rb < min_rb)
// 		{
// 			min_rra = tmp_rra + 1;
// 			min_rb = tmp_rb;
// 		}
// 		tmp_rrb = nb_rr_to_insert(ps->b->data, ps->a->data[tmp_rra], ps->b->top + 1);
// 		if (tmp_rra + 1 + tmp_rrb < min_rrb)
// 		{
// 			min_rra = tmp_rra + 1;
// 			min_rrb = tmp_rrb;
// 		}
// 		if (tmp_rra >= min_rrb || tmp_rra >= min_rb)
// 			return (best_move->rra = min_rra, best_move->rra_rrb = min_rrb, best_move->rra_rb = min_rb, min_rra);
// 		tmp_rra++;
// 	}
// }

void update_best_move(t_push_swap *ps, t_best_move *best_move)
{
	int tmp_ra = 0;
	int tmp_rb;
	int tmp_rra = 0;
	int tmp_rrb;

	best_move->ra = -1;
	best_move->rb = -1;
	best_move->rra = -1;
	best_move->rrb = -1;

	while (TRUE)
	{
		while (ps->a->top + 1 >= ps->size / 2 && ps->a->data[ps->a->top - tmp_ra] > ps->size / 2)
			tmp_ra++;
		tmp_rb = nb_r_to_insert(ps->b->data, ps->a->data[ps->a->top - tmp_ra], ps->b->top + 1);
		tmp_rrb = nb_rr_to_insert(ps->b->data, ps->a->data[ps->a->top - tmp_ra], ps->b->top + 1);
	
		if ((best_move->rb == -1 && best_move->rrb == -1)
			|| tmp_ra + tmp_rb < best_move->ra + best_move->rb 
			|| tmp_ra + tmp_rb < best_move->ra + best_move->rrb)
		{
			best_move->rrb = -1;
			best_move->ra = tmp_ra;
			best_move->rb = tmp_rb;
		}
		if (tmp_ra + tmp_rrb < best_move->ra + best_move->rrb 
			|| tmp_ra + tmp_rrb < best_move->rb + best_move->ra)
		{
			best_move->rb = -1;
			best_move->ra = tmp_ra;
			best_move->rrb = tmp_rrb;
		}
		if (tmp_ra == 200 || ps->a->top - tmp_ra < 0)
			break ;
		tmp_ra++;
	}
	tmp_rra = 0;
	int tmp_max = best_move->ra + (best_move->rb == -1 ? best_move->rrb : best_move->rb);
	while (TRUE)
	{
		while (ps->a->top + 1 >= ps->size / 2 && ps->a->data[tmp_rra] > ps->size / 2)
			tmp_rra++;
		tmp_rb = nb_r_to_insert(ps->b->data, ps->a->data[tmp_rra], ps->b->top + 1);
		tmp_rrb = nb_rr_to_insert(ps->b->data, ps->a->data[tmp_rra], ps->b->top + 1);
	
		tmp_rra++;
		if (tmp_rra + tmp_rb < tmp_max 
			|| tmp_rra + tmp_rb < best_move->rra + best_move->rrb
			|| tmp_rra + tmp_rb < best_move->rra + best_move->rb)
		{
			tmp_max = -1;
			best_move->ra = -1;
			best_move->rrb = -1;
			best_move->rra = tmp_rra;
			best_move->rb = tmp_rb;
		}
		if (tmp_rra + tmp_rrb < tmp_max
			|| tmp_rra + tmp_rrb < best_move->rra + best_move->rrb
			|| tmp_rra + tmp_rrb < best_move->rra + best_move->rb)
		{
			tmp_max = -1;
			best_move->ra = -1;
			best_move->rb = -1;
			best_move->rra = tmp_rra;
			best_move->rrb = tmp_rrb;
		}
		if (tmp_ra == 200 || ps->a->top - tmp_ra < 0)
			break ;
	}
}

void	sort(t_push_swap *ps)
{
	t_best_move	best_move;
	// qsort_ps_a(ps, ps->size / 2);
	// while (ps->b->top >= 0)
	// 	pa(ps);
	// breakpoint(ps, ME_PS, ME_OP_COUNT, ME_END);
	pb(ps);
	pb(ps);
	if (ps->b->data[0] > ps->b->data[1])
		sb(ps);
	while (ps->a->top >= 0)
	{
		update_best_move(ps, &best_move);

		// ft_printf("ra: %d, rb: %d, rra: %d, rrb: %d\n", best_move.ra, best_move.rb, best_move.rra, best_move.rrb);	
		// breakpoint(ps, ME_PS, ME_END);

		while (best_move.ra-- > 0)
			ra(ps);
		while (best_move.rra-- > 0)
			rra(ps);
		// if (ps->a->data[ps->a->top] == 238)
		// 	breakpoint(ps, ME_PS, ME_END);
		if (best_move.rrb == -1)
			while (best_move.rb-- > 0)
				rb(ps);
		else
			while (best_move.rrb-- > 0)
				rrb(ps);
		pb(ps);
	}
	while (ps->b->data[0] != get_tab_min(ps->b->data, ps->b->top + 1))
		rb(ps);
	while (ps->b->top >= 0)
		pa(ps);
	// breakpoint(ps, ME_PS, ME_OP_COUNT, ME_OP_OCCS, ME_END);
	breakpoint(ps, ME_PS, ME_OP_COUNT, ME_END);
}

// Generates an array of numbers between 1 and 500 in random order
int	*generate_random_array(int size)
{
	int	*array;
	int	i, j, temp;

	if (size > 500)
		return (NULL);

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = i + 1;

	srand(time(NULL));
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
	int unsorted_data[] = {444, 337, 425, 412, 307, 498, 250, 357, 423, 291, 224, 119, 284, 198, 379, 347, 434, 303, 79, 110, 474, 46, 26, 9, 387, 38, 216, 211, 433, 356, 292, 36, 390, 96, 31, 463, 41, 457, 208, 235, 255, 6, 210, 177, 70, 476, 127, 74, 226, 317, 20, 484, 481, 289, 147, 159, 225, 100, 133, 325, 107, 398, 82, 86, 491, 322, 343, 68, 231, 410, 389, 152, 69, 497, 254, 301, 270, 23, 408, 108, 185, 213, 340, 229, 85, 482, 359, 376, 181, 448, 19, 271, 219, 238, 288, 195, 164, 426, 458, 452, 263, 443, 80, 447, 115, 467, 234, 324, 259, 350, 265, 230, 103, 327, 35, 88, 436, 338, 358, 267, 493, 16, 415, 132, 197, 456, 87, 237, 191, 105, 203, 71, 21, 480, 5, 131, 44, 137, 383, 220, 439, 315, 462, 490, 83, 377, 392, 278, 101, 7, 331, 369, 11, 473, 53, 245, 416, 174, 477, 99, 48, 489, 451, 406, 61, 146, 404, 438, 170, 499, 305, 113, 45, 94, 346, 302, 382, 39, 25, 363, 400, 349, 341, 50, 335, 15, 351, 268, 14, 378, 283, 354, 459, 215, 112, 440, 183, 214, 1, 49, 273, 247, 58, 201, 422, 189, 461, 52, 334, 385, 59, 266, 468, 388, 276, 411, 228, 249, 18, 274, 300, 374, 450, 10, 180, 402, 84, 336, 401, 409, 282, 332, 218, 470, 244, 391, 348, 453, 279, 299, 188, 285, 157, 428, 496, 63, 91, 89, 414, 420, 352, 495, 93, 179, 22, 330, 114, 109, 431, 154, 246, 345, 260, 206, 51, 393, 151, 381, 286, 373, 465, 207, 186, 162, 290, 134, 403, 140, 294, 257, 272, 47, 429, 217, 111, 30, 368, 371, 187, 37, 469, 3, 355, 43, 155, 454, 365, 407, 78, 242, 397, 312, 65, 296, 102, 4, 318, 55, 430, 321, 212, 367, 54, 421, 98, 153, 275, 178, 449, 464, 42, 360, 143, 241, 309, 333, 342, 56, 441, 418, 328, 167, 90, 310, 172, 262, 204, 166, 33, 384, 72, 293, 168, 142, 243, 479, 17, 67, 221, 326, 232, 76, 261, 483, 135, 130, 311, 145, 81, 148, 77, 500, 319, 277, 128, 125, 380, 75, 287, 399, 158, 34, 24, 248, 297, 417, 240, 320, 141, 64, 394, 176, 253, 478, 129, 308, 227, 175, 121, 339, 256, 304, 118, 161, 163, 492, 126, 488, 432, 298, 32, 97, 460, 344, 413, 396, 375, 313, 27, 165, 73, 364, 233, 486, 419, 446, 455, 370, 386, 124, 196, 106, 395, 92, 205, 117, 138, 424, 445, 223, 13, 314, 123, 437, 160, 116, 62, 8, 104, 199, 136, 264, 306, 372, 209, 40, 139, 362, 427, 361, 202, 251, 323, 466, 329, 366, 316, 236, 60, 222, 442, 169, 252, 193, 156, 485, 12, 182, 471, 435, 173, 194, 171, 122, 66, 190, 144, 184, 405, 149, 258, 28, 487, 475, 239, 472, 150, 192, 295, 494, 2, 57, 95, 280, 281, 29, 269, 353, 200, 120};
	// int	unsorted_data[] = {4, 15, 3, 12, 8, 10, 2, 11, 9, 7, 13, 5, 1, 14, 6};
	int	size = 500;
	// int	*unsorted_data = generate_random_array(size);

	// int	size = sizeof(unsorted_data) / sizeof(unsorted_data[0]);
	rev_int_tab(unsorted_data, size);

	t_push_swap	ps;
	init_push_swap(&ps, unsorted_data, size);

	sort(&ps);

	free_push_swap(&ps);

	return (0);
}