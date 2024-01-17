/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:27:34 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/17 16:53:20 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	*error(void *ret, char *str)
{
	ft_printf("-----------------------------------\n");
	ft_printf("%s", str);
	ft_printf("-----------------------------------\n");
	return (ret);
}

int	push_swap(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);

	if (!init_stack(argc, argv, &stack_a))
		return (*(int *)error(0, "init_stack return NULL\n"));
	print_stack(&stack_a, 'a');
	push_node(&stack_b, &stack_a, 'b');
	push_node(&stack_b, &stack_a, 'b');
	push_node(&stack_b, &stack_a, 'b');
	push_node(&stack_b, &stack_a, 'b');
	print_stack(&stack_a, 'a');
	print_stack(&stack_b, 'b');
	rotate_rotate_node(&stack_a, &stack_b);
	reinit_stack_index(&stack_a, &stack_b);
	print_stack(&stack_a, 'a');
	print_stack(&stack_b, 'b');\
	return (1);
}

int	main(int argc, char *argv[])
{
	ft_printf("return = %i", push_swap(argc, argv));
	//system("leaks a.out");
}
