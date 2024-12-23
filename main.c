#include "push_swap.h"

int	*cmp_int_tab(int *tab1, int *tab2, int size)
{
	int	*cmp;
	int	i;
	int	j;

	cmp = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab1[i] == tab2[j])
			{
				cmp[i] = j - i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (cmp);
}

void	update_cmp(t_push_swap *ps)
{
	int	size = ps->a->size;
	int	*cmp = ps->cmp;
	int	i = 0;
	int	j = ps->b->top;
	int	k;

	while (i <= ps->a->top)
	{
		k = 0;
		while (k < size)
		{
			if (ps->a->data[i] == ps->sorted[k])
			{
				cmp[i] = k - i;
				break ;
			}
			k++;
		}
		i++;
	}
	while (j >= 0)
	{
		k = 0;
		while (k < size)
		{
			if (ps->b->data[j] == ps->sorted[k])
			{
				cmp[i] = k - i;
				break ;
			}
			k++;
		}
		i++;
		j--;
	}
}

void	rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
}

void	print_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
	ft_printf("\n");
}

int	get_min_num_pos(int *tab, int size)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = tab[0];
	pos = 0;
	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			pos = i;
		}
		i++;
	}
	return ((size - 1) - pos);
}

int	get_distance_of_2_num(int nb1, int nb2)
{
	return ((nb1 - nb2) < 0 ? (nb1 - nb2) * -1 : nb1 - nb2);
}

void	ft_qsort_int(int **tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if ((*tab)[i] > (*tab)[j])
			{
				tmp = (*tab)[i];
				(*tab)[i] = (*tab)[j];
				(*tab)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	qsort_ps(t_push_swap *ps)
{
	int			pivot;
	int			div;
	
	div = 2;
	pivot = ps->a->size / div;
	while (ps->a->size - pivot >= -1)
	{
		while (ps->a->top > ps->a->size - pivot)
		{
			if (ps->a->data[ps->a->top] < pivot)
				pb(ps);
			else
				ra(ps);
			if (ps->b->top > 0 && ps->b->data[ps->b->top] < ps->b->data[ps->b->top - 1])
			{
				if (ps->a->top && ps->a->data[ps->a->top] > ps->a->data[ps->a->top - 1])
					ss(ps);
				else
					sb(ps);
			}
		}
		if (div > ps->a->size)
			pivot++;
		else
		{
			div *= 2;
			pivot += (int)(ps->a->size / div);
		}
	}
	// div = 2;
	// pivot = ps->b->size / div;
	// while (pivot >= -1)
	// {
	// 	while (ps->b->top > pivot)
	// 	{
	// 		if (ps->b->data[ps->b->top] > pivot)
	// 			pa(ps);
	// 		else
	// 			rb(ps);
	// 	}
	// 	if (div > ps->b->size)
	// 		pivot--;
	// 	else
	// 	{
	// 		div *= 2;
	// 		pivot -= (int)(ps->b->size / div);
	// 	}
	// }
}

#define SA 0
#define SB 1
#define SS 2
#define PA 3
#define PB 4
#define RA 5
#define RB 6
#define RR 7
#define RRA 8
#define RRB 9
#define RRR 10



int	get_best_score(t_push_swap *ps)
{
	int		*cmp = ps->cmp;
	int		scores[11] = {0};
	int		score_max_i = -1;
	char	*last = ft_strdup("");

	if (ps->ops.count > 0)
		last = ps->ops.ops[ps->ops.count - 1];
	
	scores[SA] = (ft_strcmp(last, "sa") && ps->a->top > 1 && ps->a->data[ps->a->top] > ps->a->data[ps->a->top - 1] ? 1 : 0);
	scores[SB] = (ft_strcmp(last, "sb") && ps->b->top > 1 && ps->b->data[ps->b->top] < ps->b->data[ps->b->top - 1] ? 1 : 0);
	scores[SS] = (ft_strcmp(last, "ss") ? scores[SA] + scores[SB] : 0);
	scores[PA] = 0;
	scores[PB] = 0;
	scores[RA] = (ft_strcmp(last, "ra") && ps->a->top > 1 && cmp[ps->a->top] < 0 && (cmp[ps->a->top] + (ps->a->top + 1)) <= ((ps->a->top + 1) / 2) ? 3 : 0);
	scores[RB] = (ft_strcmp(last, "rrb") && ps->b->top > 1 && cmp[ps->a->top + 1] > 0 && ((ps->b->top + 1) - cmp[ps->a->top + 1]) <= ((ps->b->top + 1) / 2) ? 3 : 0);
	scores[RR] = (ft_strcmp(last, "rr") ? scores[RA] + scores[RB] - 1 : 0);
	scores[RRA] = (ft_strcmp(last, "rra") && ps->a->top > 1 && cmp[0] > 0 && ((ps->a->top + 1) - cmp[0]) < ((ps->a->top + 1) / 2) ? 3 : 0);
	scores[RRB] = (ft_strcmp(last, "rb") && ps->b->top > 1 && cmp[ps->a->top + ps->b->top + 1] < 0 && ((ps->b->top + 1) + cmp[ps->a->top + ps->b->top + 1]) <= ((ps->b->top + 1) / 2) ? 3 : 0);
	scores[RRR] = (ft_strcmp(last, "rrr") ? scores[RRA] + scores[RRB] - 1 : 0);

	for (int i = 0; i < 11; i++)
	{
		if (scores[i] > 0 && (score_max_i == -1 || scores[i] > scores[score_max_i]))
			score_max_i = i;
	}
	// ft_printf("Scores: SA=%d SB=%d SS=%d PA=%d PB=%d RA=%d RB=%d RR=%d RRA=%d RRB=%d RRR=%d\n", scores[SA], scores[SB], scores[SS], scores[PA], scores[PB], scores[RA], scores[RB], scores[RR], scores[RRA], scores[RRB], scores[RRR]);
	return (score_max_i);
}

void	sort(t_push_swap *ps)
{
	int		best_score;

	for (int i = 0; i < 1000; i++)
	{
		// print_int_tab(ps->cmp, ps->a->size);
		// print_ps(ps);
		best_score = get_best_score(ps);
		
		switch (best_score)
		{
		case SA:
			sa(ps);
			break;
		case SB:
			sb(ps);
			break;
		case SS:
			ss(ps);
			break;
		case PA:
			pa(ps);
			break;
		case PB:
			pb(ps);
			break;
		case RA:
			ra(ps);
			break;
		case RB:
			rb(ps);
			break;
		case RR:
			rr(ps);
			break;
		case RRA:
			rra(ps);
			break;
		case RRB:
			rrb(ps);
			break;
		case RRR:
			rrr(ps);
			break;
		default:
			if (i > 500)
				pa(ps);
			else
				pb(ps);
			break;
		}
		
		update_cmp(ps);
	}
	
	// qsort_ps(ps);
}

// void	sort(t_push_swap *ps)
// {
// 	int	min_pos;

// 	while (ps->a->top > 0)
// 	{
// 		min_pos = get_min_num_pos(ps->a->data, &ps->a->data[ps->a->top] - &ps->a->data[0] + 1);
// 		while (min_pos > 0)
// 		{
// 			ra(ps);
// 			min_pos--;
// 		}
// 		pb(ps);
// 	}
// 	while (ps->b->top >= 0)
// 		pa(ps);
// }

int	main()
{
	int unsorted_data[] = {444, 337, 425, 412, 307, 498, 250, 357, 423, 291, 224, 119, 284, 198, 379, 347, 434, 303, 79, 110, 474, 46, 26, 9, 387, 38, 216, 211, 433, 356, 292, 36, 390, 96, 31, 463, 41, 457, 208, 235, 255, 6, 210, 177, 70, 476, 127, 74, 226, 317, 20, 484, 481, 289, 147, 159, 225, 100, 133, 325, 107, 398, 82, 86, 491, 322, 343, 68, 231, 410, 389, 152, 69, 497, 254, 301, 270, 23, 408, 108, 185, 213, 340, 229, 85, 482, 359, 376, 181, 448, 19, 271, 219, 238, 288, 195, 164, 426, 458, 452, 263, 443, 80, 447, 115, 467, 234, 324, 259, 350, 265, 230, 103, 327, 35, 88, 436, 338, 358, 267, 493, 16, 415, 132, 197, 456, 87, 237, 191, 105, 203, 71, 21, 480, 5, 131, 44, 137, 383, 220, 439, 315, 462, 490, 83, 377, 392, 278, 101, 7, 331, 369, 11, 473, 53, 245, 416, 174, 477, 99, 48, 489, 451, 406, 61, 146, 404, 438, 170, 499, 305, 113, 45, 94, 346, 302, 382, 39, 25, 363, 400, 349, 341, 50, 335, 15, 351, 268, 14, 378, 283, 354, 459, 215, 112, 440, 183, 214, 1, 49, 273, 247, 58, 201, 422, 189, 461, 52, 334, 385, 59, 266, 468, 388, 276, 411, 228, 249, 18, 274, 300, 374, 450, 10, 180, 402, 84, 336, 401, 409, 282, 332, 218, 470, 244, 391, 348, 453, 279, 299, 188, 285, 157, 428, 496, 63, 91, 89, 414, 420, 352, 495, 93, 179, 22, 330, 114, 109, 431, 154, 246, 345, 260, 206, 51, 393, 151, 381, 286, 373, 465, 207, 186, 162, 290, 134, 403, 140, 294, 257, 272, 47, 429, 217, 111, 30, 368, 371, 187, 37, 469, 3, 355, 43, 155, 454, 365, 407, 78, 242, 397, 312, 65, 296, 102, 4, 318, 55, 430, 321, 212, 367, 54, 421, 98, 153, 275, 178, 449, 464, 42, 360, 143, 241, 309, 333, 342, 56, 441, 418, 328, 167, 90, 310, 172, 262, 204, 166, 33, 384, 72, 293, 168, 142, 243, 479, 17, 67, 221, 326, 232, 76, 261, 483, 135, 130, 311, 145, 81, 148, 77, 500, 319, 277, 128, 125, 380, 75, 287, 399, 158, 34, 24, 248, 297, 417, 240, 320, 141, 64, 394, 176, 253, 478, 129, 308, 227, 175, 121, 339, 256, 304, 118, 161, 163, 492, 126, 488, 432, 298, 32, 97, 460, 344, 413, 396, 375, 313, 27, 165, 73, 364, 233, 486, 419, 446, 455, 370, 386, 124, 196, 106, 395, 92, 205, 117, 138, 424, 445, 223, 13, 314, 123, 437, 160, 116, 62, 8, 104, 199, 136, 264, 306, 372, 209, 40, 139, 362, 427, 361, 202, 251, 323, 466, 329, 366, 316, 236, 60, 222, 442, 169, 252, 193, 156, 485, 12, 182, 471, 435, 173, 194, 171, 122, 66, 190, 144, 184, 405, 149, 258, 28, 487, 475, 239, 472, 150, 192, 295, 494, 2, 57, 95, 280, 281, 29, 269, 353, 200, 120};
	// int	unsorted_data[] = {4, 3, 8, 10, 1, 9, 7, 5, 2, 6};
	// int	unsorted_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	size = sizeof(unsorted_data) / sizeof(unsorted_data[0]);


	// int	size = sizeof(data) / sizeof(data[0]);

	rev_int_tab(unsorted_data, size);
	// rev_int_tab(data, size);

	t_push_swap	ps;
	ps.a = create_stack(size);
	ps.b = create_stack(size);
	ps.sorted = ft_memcpy(malloc(sizeof(int) * size), unsorted_data, sizeof(int) * size);
	ps.cmp = malloc(sizeof(int) * size);
	ft_qsort_int(&ps.sorted, size);
	rev_int_tab(ps.sorted, size);
	flood_stack(ps.a, unsorted_data, size);
	ps.cmp = cmp_int_tab(ps.a->data, ps.sorted, ps.a->size);
	init_operations(&ps.ops);

	// qsort(ps.sorted, size, sizeof(int), (int (*)(const void *, const void *))ft_strcmp);
	// rev_int_tab(ps.sorted, size);

	// flood_stack(ps.a, data, size);

	// print_ps(&ps);
	sort(&ps);
	// print_ps(&ps);

	// print_operations(&ps.ops);
	// ft_printf("Number of operations: %d\n", ps.ops.count);
	// ft_printf("Indexes movements: ");

	print_ps(&ps);
	print_operations(&ps.ops);
	// print_operation_recurence(&ps.ops);
	// print_int_tab(ps.sorted, size);
	// print_int_tab(ps.sorted, ps.a->size);
	// print_int_tab(ps.cmp, ps.a->size);

	free_operations(&ps.ops);
	free_stack(ps.a);
	free_stack(ps.b);
	free(ps.cmp);

	return (0);
}