/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:58:51 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/19 19:12:09 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_3_nodes(t_stack **stack, char stack_name)
{
	t_stack	*m_node;

	m_node = get_max_node(stack);
	if (m_node->index == 1)
		reverse_rotate_node(stack, stack_name, 1);
	if (m_node->index == 0)
		rotate_node(stack, stack_name, 1);
	if (!is_sorted(stack))
		swap_node(stack, stack_name, 1);
	return (1);
}

int	put_nodes_on_top(t_stack **stack_a, t_stack **stack_b,
	t_stack **node_a, t_stack **node_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = (*node_a)->index;
	if ((*node_a)->index > (get_stack_len(stack_a) - (*node_a)->index))
		cost_a = 0 - ((get_stack_len(stack_a) - (*node_a)->index));
	cost_b = (*node_b)->index;
	if ((*node_b)->index > (get_stack_len(stack_b) - (*node_b)->index))
		cost_b = 0 - ((get_stack_len(stack_b) - (*node_b)->index));
	while (cost_a < 0 && cost_b < 0)
	{
		d_reverse_rotate_node(stack_a, stack_b, 1);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0 && cost_b > 0)
	{
		d_rotate_node(stack_a, stack_b, 1);
		cost_a--;
		cost_b--;
	}
	put_node_on_top(stack_a, 'a', node_a);
	put_node_on_top(stack_b, 'b', node_b);
	return (1);
}

int	put_node_on_top(t_stack **stack, char stack_name, t_stack **node)
{
	int	max_index;
	int	i;

	max_index = get_stack_len(stack) - 1;
	i = 0;
	if ((*node)->index > ((max_index - (*node)->index) + 1))
	{
		i = ((max_index - (*node)->index) + 1);
		while (i-- > 0)
			reverse_rotate_node(stack, stack_name, 1);
	}
	else
	{
		i = (*node)->index;
		while (i-- > 0)
			rotate_node(stack, stack_name, 1);
	}
	return (1);
}
