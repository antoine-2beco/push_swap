/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_shortcuts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:56:27 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/19 19:05:54 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	d_rotate_node(t_stack **stack_a, t_stack **stack_b, int print)
{
	rotate_node(stack_a, 'a', 0);
	rotate_node(stack_b, 'b', 0);
	if (print)
		ft_printf("rr\n");
	return (1);
}

int	d_reverse_rotate_node(t_stack **stack_a, t_stack **stack_b, int print)
{
	reverse_rotate_node(stack_a, 'a', 0);
	reverse_rotate_node(stack_b, 'b', 0);
	if (print)
		ft_printf("rrr\n");
	return (1);
}

int	d_swap_node(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap_node(stack_a, 'a', 0);
	swap_node(stack_b, 'b', 0);
	if (print)
		ft_printf("ss\n");
	return (1);
}
