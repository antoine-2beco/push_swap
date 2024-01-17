/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:13:28 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/17 14:02:02 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

t_stack	*swap(t_stack **stack, char stack_name)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!*stack)
		return (*stack);
	first_node = *stack;
	if (!first_node->next)
		return (*stack);
	second_node = first_node->next;
	second_node->prev = NULL;
	first_node->prev = second_node;
	first_node->next = NULL;
	if (second_node->next)
	{
		first_node->next = second_node->next;
		(second_node->next)->prev = first_node;
	}
	second_node->next = first_node;
	ft_printf("s%c\n",stack_name);
	return (second_node);
}
