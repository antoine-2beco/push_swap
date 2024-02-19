/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:15:11 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/19 19:07:43 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		error(int ret, t_stack **stack_a, t_stack **stack_b);
int		verify_args(char **args);

// stacks_utils
int		get_stack_len(t_stack **stack);
int		free_stack(t_stack **stack);
int		reinit_stack_index(t_stack	**stack);
int		init_stack(int argc, char *argv[], t_stack **stack);

// operations
int		swap_node(t_stack **stack, char stack_name, int print);
int		push_node(t_stack **stack_p, t_stack **stack_r, char stack_name_r,
			int print);
int		rotate_node(t_stack **stack, char stack_name, int print);
int		reverse_rotate_node(t_stack **stack, char stack_name, int print);

// operations_shortcuts
int		d_rotate_node(t_stack **stack_a, t_stack **stack_b, int print);
int		d_reverse_rotate_node(t_stack **stack_a, t_stack **stack_b, int print);
int		d_swap_node(t_stack **stack_a, t_stack **stack_b, int print);

// sort
int		init_target_node(t_stack **stack_a, t_stack **stack_b);
int		init_push_cost(t_stack **stack_a, t_stack **stack_b);
int		sort_push_node(t_stack **stack_a, t_stack **stack_b);
int		sort_push_back_node(t_stack **stack_a, t_stack **stack_b);

// sort_utils
t_stack	*get_max_node(t_stack **stack);
t_stack	*get_min_node(t_stack **stack);
int		is_sorted(t_stack **stack);

// sort_operations
int		sort_3_nodes(t_stack **stack, char stack_name);
int		put_nodes_on_top(t_stack **stack_a, t_stack **stack_b,
			t_stack **node_a, t_stack **node_b);
int		put_node_on_top(t_stack **stack, char stack_name, t_stack **node);

#endif
