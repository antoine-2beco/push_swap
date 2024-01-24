/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:04:48 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/24 15:19:50 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

// mode 0 == ascending || mode 1 == descending
int	sort_3_nodes(t_stack **stack, char stack_name, int mode)
{
	t_stack	*m_node;

	if (mode == 0)
		m_node = get_max_node(stack);
	else
		m_node = get_min_node(stack);
	if (m_node->index == 1)
		reverse_rotate_node(stack, stack_name);
	if (m_node->index == 0)
		rotate_node(stack, stack_name);
	if (m_node->nbr == (((*stack)->next)->next)->nbr)
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

int	init_push_cost(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*target;
	int		max_index;
	int		push_cost;

	temp = *stack;
	max_index = get_stack_len(&temp);
	while (temp)
	{
		target = temp->target;
		push_cost = temp->index;
		if (push_cost > (max_index - push_cost))
			push_cost = (max_index - push_cost);
		push_cost += (1 + target->index);
		temp->push_cost = push_cost;
		temp = temp->next;
	}
	return (1);
}

int	push_min_cost_node(t_stack **stack_p, char stack_p_name,
	t_stack **stack_r, char stack_r_name)
{
	t_stack	*temp;
	t_stack	*min_cost_node;

	temp = (*stack_p)->next;
	min_cost_node = *stack_p;
	while (temp)
	{
		if (min_cost_node->push_cost > temp->push_cost)
			min_cost_node = temp;
		temp = temp->next;
	}
	put_node_on_top(stack_p, stack_p_name, &min_cost_node);
	put_node_on_top(stack_r, stack_r_name, &min_cost_node->target);
	push_node(stack_p, stack_r, stack_r_name);
	return (1);
}