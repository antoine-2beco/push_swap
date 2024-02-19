/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:04:48 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/19 10:48:05 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_target_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		i;

	temp_a = *stack_a;
	while (temp_a)
	{
		i = 0;
		temp_b = *stack_b;
		temp_a->target = get_max_node(stack_b);
		while (temp_b)
		{
			if ((temp_a->nbr > temp_b->nbr)
				&& (!i++ || (temp_a->target)->nbr < temp_b->nbr))
				temp_a->target = temp_b;
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
	return (1);
}

static int	count_push_cost(int a, int b, int push_cost)
{
	while (a < 0 && b < 0)
	{
		push_cost++;
		a++;
		b++;
	}
	while (a > 0 && b > 0)
	{
		push_cost++;
		a--;
		b--;
	}
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	return (push_cost + a + b);
}

int	init_push_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*target;
	int		push_cost;
	int		a;
	int		b;

	temp = *stack_a;
	while (temp)
	{
		target = temp->target;
		push_cost = 1;
		a = temp->index;
		if (temp->index > ((get_stack_len(stack_a) - temp->index)))
			a = 0 - ((get_stack_len(stack_a) - temp->index));
		b = target->index;
		if (target->index > ((get_stack_len(stack_b) - target->index)))
			b = 0 - ((get_stack_len(stack_b) - target->index));
		temp->push_cost = count_push_cost(a, b, push_cost);
		temp = temp->next;
	}
	return (1);
}

int	sort_push_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*min_cost_node;

	temp = (*stack_a)->next;
	min_cost_node = *stack_a;
	while (temp)
	{
		if (min_cost_node->push_cost > temp->push_cost)
			min_cost_node = temp;
		temp = temp->next;
	}
	put_nodes_on_top(stack_a, stack_b, &min_cost_node, &min_cost_node->target);
	push_node(stack_a, stack_b, 'b', 1);
	return (1);
}

int	sort_push_back_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		i;

	i = 0;
	temp_a = *stack_a;
	temp_b = *stack_b;
	temp_b->target = get_min_node(stack_a);
	while (temp_a)
	{
		if ((temp_b->nbr < temp_a->nbr)
			&& (!i++ || ((temp_b->target)->nbr > temp_a->nbr)))
			temp_b->target = temp_a;
		temp_a = temp_a->next;
	}
	put_node_on_top(stack_a, 'a', &temp_b->target);
	push_node(stack_b, stack_a, 'a', 1);
	return (1);
}
