/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_shortcuts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:56:27 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/15 16:01:14 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	d_rotate_node(t_stack **stack_a, t_stack **stack_b)
{
	rotate_node(stack_a, 'a', 0);
	rotate_node(stack_b, 'b', 0);
	ft_printf("rr\n");
	return (1);
}

int	d_reverse_rotate_node(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_node(stack_a, 'a', 0);
	reverse_rotate_node(stack_b, 'b', 0);
	ft_printf("rrr\n");
	return (1);
}
