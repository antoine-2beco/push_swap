/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:15:11 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/17 16:53:39 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

// Illegal
#include <stdio.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void		*error(void *ret, char *str);

// stacks_utils
int			init_stack(int argc, char *argv[], t_stack **stack);
int			free_stack(t_stack **stack);
int			reinit_stack_index(t_stack	**stack_a, t_stack	**stack_b);


int			print_stack(t_stack **stack, char stack_name);

// sort_operations
int			swap_node(t_stack **stack, char stack_name);
int			swap_swap_node(t_stack **stack_a, t_stack **stack_b);
int			push_node(t_stack **stack_p, t_stack **stack_r, char stack_name_p);
int			rotate_node(t_stack **stack, char stack_name);
int 		rotate_rotate_node(t_stack **stack_a, t_stack **stack_b);


#endif