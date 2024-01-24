/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:49:20 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/24 14:14:34 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	get_stack_len(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 1;
	temp = *stack;
	if (!temp)
		return (0);
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return (error(0, "stack is NULL in free_stack"));
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

int	reinit_stack_index(t_stack	**stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	if (!temp)
		return (0);
	while (temp)
	{
		temp->index = i++;
		temp = temp->next;
	}
	return (1);
}

static int	add_node(t_stack **stack, int nbr, int index)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return (error(0, "stack is NULL in add_node\n"));
	node = malloc(sizeof(t_stack));
	if (!node)
		return (error(0, "node malloc failed in add_node\n"));
	node->nbr = nbr;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	node->push_cost = 0;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = node;
		node->prev = last_node;
	}
	return (1);
}

int	init_stack(int argc, char *argv[], t_stack **stack)
{
	char	**args;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = ++argv;
	while (args[++i])
	{
		k = ft_atoi(args[i]);
		while (args[++j])
			if (ft_atoi(args[j]) == k && j != i)
				return (error(0, "Two or many same numbers\n"));
		if (!add_node(stack, k, i))
			return (error(0, "add_node return NULL\n"));
		j = -1;
	}
	if (argc == 2)
		free(args);
	return (1);
}
