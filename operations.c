#include "push_swap.h"

void	init_operations(t_operations *ops)
{
	ops->ops = malloc(sizeof(char *) * 10);
	ops->count = 0;
	ops->capacity = 10;
}

void	add_operation(t_operations *ops, char *op)
{
	if (ops->count == ops->capacity)
	{
		ops->capacity *= 2;
		ops->ops = ft_realloc(ops->ops, sizeof(char *) * ops->capacity);
	}
	ops->ops[ops->count] = op;
	ops->count++;
}

void	free_operations(t_operations *ops)
{
	int	i;

	i = 0;
	while (i < ops->count)
	{
		free(ops->ops[i]);
		i++;
	}
	free(ops->ops);
}