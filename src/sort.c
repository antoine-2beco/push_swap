/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:04:48 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/22 15:05:57 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	sort_3_nodes(t_stack **stack, char stack_name)
{
	t_stack	*temp;
	t_stack	*max_node;

	max_node = *stack;
	temp = (*stack)->next;
	while (temp)
	{
		if (temp->nbr > max_node->nbr)
			max_node = temp;
		temp = temp->next;
	}
	if (max_node->index == 1)
		reverse_rotate_node(stack, stack_name);
	if (max_node->index == 0)
		rotate_node(stack, stack_name);
	if (!is_sorted(stack))
		swap_node(stack, stack_name);
	return (1);
}

int	init_target_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		target_val;

	temp_a = *stack_a;
	while (temp_a)
	{
		target_val = 0;
		temp_b = *stack_b;
		temp_a->target = get_max_node(stack_b);
		while (temp_b)
		{
			if ((temp_a->nbr - temp_b->nbr) > 0
				&& (!target_val || target_val > (temp_a->nbr - temp_b->nbr)))
			{
				target_val = (temp_a->nbr - temp_b->nbr);
				temp_a->target = temp_b;
			}
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
	return (1);
}