/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:57:35 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/01 12:10:27 by ade-beco         ###   ########.fr       */
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
	reinit_stack_index(stack);
	ft_printf("s%c\n", stack_name);
	return (1);
}

int	push_node(t_stack **stack_p, t_stack **stack_r, char stack_name_r)
{
	t_stack	*first_node_p;
	t_stack	*first_node_r;
	t_stack	*second_node_r;

	if (!*stack_p)
		return (0);
	first_node_r = *stack_p;
	second_node_r = NULL;
	second_node_r = first_node_r->next;
	first_node_r->next = NULL;
	if (*stack_r)
	{
		first_node_p = *stack_r;
		first_node_r->next = first_node_p;
		first_node_p->prev = first_node_r;
	}
	first_node_r->prev = NULL;
	if (second_node_r)
		second_node_r->prev = NULL;
	*stack_r = first_node_r;
	*stack_p = second_node_r;
	reinit_stack_index(stack_r);
	reinit_stack_index(stack_p);
	ft_printf("p%c\n", stack_name_r);
	return (1);
}

int	rotate_node(t_stack **stack, char stack_name, int print)
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
	reinit_stack_index(stack);
	if (print)
		ft_printf("r%c\n", stack_name);
	return (1);
}

int	reverse_rotate_node(t_stack **stack, char stack_name, int print)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*before_last_node;

	if (!(*stack) || !((*stack)->next))
		return (0);
	first_node = *stack;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	before_last_node = last_node->prev;
	first_node->prev = last_node;
	last_node->prev = NULL;
	last_node->next = first_node;
	before_last_node->next = NULL;
	*stack = last_node;
	reinit_stack_index(stack);
	if (print)
		ft_printf("rr%c\n", stack_name);
	return (1);
}
