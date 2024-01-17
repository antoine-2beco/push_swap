/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_shortcuts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:56:27 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/17 17:12:08 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	d_swap_node(t_stack **stack_a, t_stack **stack_b)
{
	swap_node(stack_a, 'a');
	swap_node(stack_b, 'b');
	return (1);
}

int	d_rotate_node(t_stack **stack_a, t_stack **stack_b)
{
	rotate_node(stack_a, 'a');
	rotate_node(stack_b, 'b');
	return (1);
}

int	d_reverse_rotate_node(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_node(stack_a, 'a');
	reverse_rotate_node(stack_b, 'b');
	return (1);
}
