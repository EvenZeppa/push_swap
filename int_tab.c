#include "push_swap.h"

int	ft_is_int(char *str)
{
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		result = result * 10 + (*str + '0');
		if (result * sign < INT_MIN || result * sign > INT_MAX)
			return (0);
		str++;
	}
	return (1);
}

int	int_tab_min_index(int *tab, int size)
{
	int	min;
	int	index;
	int	i;

	min = tab[0];
	index = 0;
	i = 1;
	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	int_tab_next_index(int *tab, int size, int value)
{
	int	index;
	int	i;

	index = -1;
	i = 0;
	while (i < size)
	{
		if (index == -1 && tab[i] > value)
			index = i;
		if (index != -1 && tab[i] > value && tab[i] < tab[index])
			index = i;
		i++;
	}
	return (index);
}

int	int_tab_count_value(int *tab, int size, int value)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] == value)
			count++;
		i++;
	}
	return (count);
}
