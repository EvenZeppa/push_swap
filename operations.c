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

static int	build_recurrence(char **recurence, char **ops, int count)
{
	int	i;

	*recurence = ft_strdup(ops[0]);
	i = 1;
	while (i < count && ft_strcmp(ops[0], ops[i]) != 0 && ft_strcmp(ops[i], ops[i - 1]) != 0)
	{
		*recurence = ft_strjoin(*recurence, "\n");
		*recurence = ft_strjoin(*recurence, ops[i]);
		i++;
	}
	return (i);
}

int	get_recurence_index(char **recurences, char *current_recurence)
{
	int	i;

	i = 0;
	while (recurences[i] && ft_strcmp(recurences[i], current_recurence) != 0)
		i++;
	return (i);
}

void	print_operation_recurence(t_operations *ops)
{
	char	**recurences;
	int		*nb_recurences;
	char	*current_recurence;
	int		recurence_index;
	int		i;

	recurences = malloc(sizeof(char *) * 512);
	if (!recurences)
		return ;
	nb_recurences = malloc(sizeof(int) * 512);
	if (!nb_recurences)
	{
		free(recurences);
		return ;
	}
	recurences[0] = NULL;
	i = 0;
	while (i < ops->count)
	{
		i += build_recurrence(&current_recurence, &ops->ops[i], ops->count - i);
		recurence_index = get_recurence_index(recurences, current_recurence);
		if (!recurences[recurence_index])
		{
			recurences[recurence_index] = ft_strdup(current_recurence);
			nb_recurences[recurence_index] = 0;
		}
		nb_recurences[recurence_index]++;
	}

	ft_printf(
		"--------------------------------------\n"
		"|        Operation Recurences        |\n"
		"--------------------------------------\n"
	);
	i = 0;
	while (recurences[i])
	{
		ft_printf("%s\n%d\n\n", recurences[i], nb_recurences[i]);
		i++;
	}

	i = 0;
	while (recurences[i])
	{
		free(recurences[i]);
		i++;
	}
	free(current_recurence);
	free(recurences);
	free(nb_recurences);
}