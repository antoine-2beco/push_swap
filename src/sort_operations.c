/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:57:35 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/17 17:00:49 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	swap_node(t_stack **stack, char stack_name)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!(*stack) || !((*stack)->next))
		return (0);
	first_node = *stack;
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
	*stack = second_node;
	ft_printf("s%c\n", stack_name);
	return (1);
}

int	push_node(t_stack **stack_p, t_stack **stack_r, char stack_name_p)
{
	t_stack	*first_node_p;
	t_stack	*first_node_r;
	t_stack	*second_node_r;

	if (!*stack_r)
		return (0);
	first_node_r = *stack_r;
	second_node_r = first_node_r->next;
	first_node_r->next = NULL;
	if (*stack_p)
	{
		first_node_p = *stack_p;
		first_node_r->next = first_node_p;
		first_node_p->prev = first_node_r;
	}
	first_node_r->prev = NULL;
	second_node_r->prev = NULL;
	*stack_p = first_node_r;
	*stack_r = second_node_r;
	ft_printf("p%c\n", stack_name_p);
	return (1);
}

int	rotate_node(t_stack **stack, char stack_name)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	if (!(*stack) || !((*stack)->next))
		return (0);
	first_node = *stack;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = first_node;
	first_node->prev = last_node;
	second_node = first_node->next;
	second_node->prev = NULL;
	first_node->next = NULL;
	*stack = second_node;
	ft_printf("r%c\n", stack_name);
	return (1);
}
