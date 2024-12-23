#include "push_swap.h"

void	init_operations(t_operations *ops)
{
	ops->ops = malloc(sizeof(char *) * 10);
	if (!ops->ops)
		return ;
	ops->count = 0;
	ops->capacity = 10;
}

void	add_operation(t_operations *ops, char *op)
{
	if (ops->count == ops->capacity)
	{
		ops->capacity *= 2;
		ops->ops = realloc(ops->ops, sizeof(char *) * ops->capacity);
	}
	ops->ops[ops->count] = ft_strdup(op);
	ops->count++;
}

void	pop_operation(t_operations *ops)
{
	if (ops->count > 0)
	{
		free(ops->ops[ops->count - 1]);
		ops->count--;
	}
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

void	print_operations(t_operations *ops)
{
	int	i;

	i = 0;
	while (i < ops->count)
	{
		ft_printf("%s\n", ops->ops[i]);
		i++;
	}
}