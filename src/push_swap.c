/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:27:34 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/18 13:06:46 by ade-beco         ###   ########.fr       */
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

static int	print_stack(t_stack **stack, char stack_name)
{
	t_stack	*temp;

	temp = *stack;
	if (!temp)
		return (0);
	ft_printf("=== stack_%c ===\n", stack_name);
	while (temp)
	{
		printf("%p : nbr = %i, index = %i, push_cost = %i, prev = %p, next = %p\n", temp, temp->nbr, temp->index, temp->push_cost,temp->prev, temp->next);
		temp = temp->next;
	}
	return (1);
}

int	sort_stacks(t_stack **stack_a, t_stack **stack_b, int stack_a_len)
{
	if (is_sorted(stack_a))
		return (1);
	if (stack_a_len == 3)
		return (sort_3_nodes(stack_a, 'a'));
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	return (0);
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
	if (sort_stacks(&stack_a, &stack_b, get_stack_len(&stack_a)))
		return (1);
	return (0);
}
