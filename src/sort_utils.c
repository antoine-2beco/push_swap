/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:55:19 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/18 13:03:55 by ade-beco         ###   ########.fr       */
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
	while (temp->next)
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

int	is_sorted(t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = *stack;
	if (!temp || !temp->next)
		return (0);
	while (temp->next)
	{
		j = temp->nbr;
		if (j < i)
			return (0);
		i = j;
		temp = temp->next;
	}
	return (1);
}

// two same args