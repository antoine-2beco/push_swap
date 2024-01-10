/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:49:20 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/10 14:50:03 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return (0);
	while (*stack)
	{
		temp = (*stack)->next;
		node->nbr = NULL;
		node->index = NULL;
		node->push_cost = NULL;
		node->above_median = NULL;
		node->cheapest = NULL;
		node->*target = NULL;
		node->*prev = NULL;
		node->*next = NULL;
		free (node);
		node = NULL;
		*stack = temp;
	}
	return (1);
}

static int	new_node(int nbr, int index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->nbr = nbr;
	node->index = index;
	node->push_cost = NULL;
	node->above_median = NULL;
	node->cheapest = NULL;
	node->*target = NULL;
	node->*prev = NULL;
	node->*next = NULL;
	return (1);
}

static int	add_node(t_stack **stack)
{
	t_stack	*node;

	node = new_node(ft_atoi(argv[i]), i);
	if (!stack || !node)
		return (0);
	if (*stack)
	{
		while ((*stack)->next)
			*stack = (*stack)->next;
		node->prev = *stack;
		(*stack)->next = node; 
	}
	else
		*stack = node;
	return (1);
}

int	init_stack(int argc, char *argv[], t_stack **stack)
{
	char	*args;
	int		i;

	i = -1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		*argv++;
		args = argv;
	}
	while (args[++i])
	{
		if (!add_node(&stack))
			return (0);
	}
	if (argc == 2)
		free(args);
	return (1);
}
