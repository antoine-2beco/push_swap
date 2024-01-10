/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:49:20 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/10 16:56:25 by ade-beco         ###   ########.fr       */
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
		temp->nbr = 0;
		temp->index = 0;
		temp->push_cost = 0;
		temp->above_median = NULL;
		temp->cheapest = NULL;
		temp->target = NULL;
		temp->prev = NULL;
		temp->next = NULL;
		free (temp);
		temp = NULL;
		*stack = temp;
	}
	return (1);
}

static t_stack	*new_node(int nbr, int index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->nbr = nbr;
	node->index = index;
	node->push_cost = 0;
	node->above_median = NULL;
	node->cheapest = NULL;
	node->target = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static int	add_node(t_stack **stack, char *arg, int i)
{
	t_stack	*node;

	node = new_node(ft_atoi(arg), i);
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
		args = *(ft_split(argv[1], ' '));
	else
	{
		argv++;
		args = *argv;
	}
	while (args[++i])
	{
		if (!add_node(stack, &args[i], i))
			return (0);
	}
	if (argc == 2)
		free(args);
	return (1);
}
