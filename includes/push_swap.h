/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:15:11 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/17 13:55:53 by ade-beco         ###   ########.fr       */
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

// sort_operations
t_stack		*swap(t_stack **stack, char stack_name);

#endif