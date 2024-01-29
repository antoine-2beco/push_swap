/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:15:11 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/29 10:25:56 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

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

int		error(int ret, char *str, t_stack **stack_a, t_stack **stack_b);
int		push_swap(int argc, char *argv[]);

// stacks_utils
int		get_stack_len(t_stack **stack);
int		free_stack(t_stack **stack);
int		reinit_stack_index(t_stack	**stack);
int		init_stack(int argc, char *argv[], t_stack **stack);

// operations
int		swap_node(t_stack **stack, char stack_name);
int		push_node(t_stack **stack_p, t_stack **stack_r, char stack_name_r);
int		rotate_node(t_stack **stack, char stack_name);
int		reverse_rotate_node(t_stack **stack, char stack_name);

// perations_shortcuts
int		d_swap_node(t_stack **stack_a, t_stack **stack_b);
int		d_rotate_node(t_stack **stack_a, t_stack **stack_b);
int		d_reverse_rotate_node(t_stack **stack_a, t_stack **stack_b);

// sort
int		sort_3_nodes(t_stack **stack, char stack_name);
int		init_target_node(t_stack **stack_a, t_stack **stack_b);
int		init_push_cost(t_stack **stack);
int		sort_push_node(t_stack **stack_p, char stack_p_name,
			t_stack **stack_r, char stack_r_name);
int		sort_push_back_node(t_stack **stack_a,
			t_stack **stack_b);

// sort_utils
int		put_node_on_top(t_stack **stack, char stack_name, t_stack **node);
t_stack	*get_max_node(t_stack **stack);
t_stack	*get_min_node(t_stack **stack);
int		is_sorted(t_stack **stack);

#endif