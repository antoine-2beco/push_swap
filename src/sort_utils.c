/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:55:19 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/22 15:05:46 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

t_stack	*get_max_node(t_stack **stack)
{
	t_stack *temp;
	t_stack *max_node;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		if (i < temp->nbr)
			max_node = temp;
		temp = temp->next;
	}
	return (max_node);
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
