/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:55:19 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/15 16:01:07 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	t_stack		*temp;
	long		i;
	int			j;

	temp = *stack;
	if (!temp || !temp->next)
		return (0);
	i = temp->nbr;
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
