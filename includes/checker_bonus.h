/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:26:32 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/19 18:40:12 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

// sort_utils.c
int		is_sorted(t_stack **stack);

// stacks_utils
int		get_stack_len(t_stack **stack);
int		free_stack(t_stack **stack);
int		reinit_stack_index(t_stack	**stack);
int		init_stack(int argc, char *argv[], t_stack **stack);

#endif