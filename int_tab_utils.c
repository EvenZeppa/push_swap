#include "push_swap.h"

// Reverses the order of elements in an integer array
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

// Compares two integer arrays and returns an array of differences in indices
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

// Sorts an array of integers using a simple bubble sort algorithm
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

// Prints the elements of an integer array
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