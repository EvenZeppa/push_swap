#include "push_swap.h"

// Put breakpoint in the code to print the state of the push_swap structure
void	breakpoint(t_push_swap *ps, ...)
{
	va_list	args;
	int		metric;

	va_start(args, ps);
	while ((metric = va_arg(args, int)))
	{
		switch (metric)
		{
			case ME_PS:
				print_ps(ps);
				break;
			case ME_SORTED:
				print_int_tab(ps->sorted, ps->size);
				break;
			case ME_CMP:
				print_int_tab(ps->cmp, ps->size);
				break;
			case ME_OPS:
				print_operations(&ps->ops);
				break;
			case ME_OP_OCCS:
				print_operation_recurence(&ps->ops);
				break;
			case ME_OP_COUNT:
				ft_printf("Operation count: %d\n", ps->ops.count);
				break;
			default:
				break;
		}
	}
	va_end(args);
	// Wait until the user presses a key
	ft_printf("Press any key to continue...\n");
	getchar();
}
