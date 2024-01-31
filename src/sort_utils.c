/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:55:19 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/31 16:59:17 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	put_nodes_on_top(t_stack **stack_a, t_stack **stack_b,
	t_stack **node_a, t_stack **node_b)
{
	int	cost_a;
	int	cost_b;

	if ((*node_a)->index > ((get_stack_len(stack_a) - (*node_a)->index) + 1))
		cost_a = 0 - ((get_stack_len(stack_a) - (*node_a)->index) + 1);
	else
		cost_a = (*node_a)->index;
	if ((*node_b)->index > ((get_stack_len(stack_b) - (*node_b)->index) + 1))
		cost_b = 0 - ((get_stack_len(stack_b) - (*node_b)->index) + 1);
	else
		cost_b = (*node_b)->index;
	while (cost_a++ < 0 && cost_b++ < 0)
		d_reverse_rotate_node(stack_a, stack_b);
	while (cost_a-- > 0 && cost_b-- > 0)
		d_rotate_node(stack_a, stack_b);
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

t_stack	*get_max_node(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*max_node;

	temp = (*stack)->next;
	max_node = *stack;
	while (temp)
	{
		if (max_node->nbr < temp->nbr)
			max_node = temp;
		temp = temp->next;
	}
	return (max_node);
}

t_stack	*get_min_node(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*min_node;

	temp = (*stack)->next;
	min_node = *stack;
	while (temp)
	{
		if (min_node->nbr > temp->nbr)
			min_node = temp;
		temp = temp->next;
	}
	return (min_node);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		j;

	i = INT32_MIN;
	temp = *stack;
	if (!temp || !temp->next)
		return (0);
	while (temp)
	{
		j = temp->nbr;
		if (j < i)
			return (0);
		i = j;
		temp = temp->next;
	}
	return (1);
}
