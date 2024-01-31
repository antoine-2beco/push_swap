/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:49:20 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/31 17:19:50 by ade-beco         ###   ########.fr       */
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

	if (!stack || !*stack)
		return (0);
	while (*stack)
	{
		temp = NULL;
		if ((*stack)->next)
			temp = (*stack)->next;
		(*stack)->nbr = 0;
		(*stack)->index = 0;
		(*stack)->push_cost = 0;
		(*stack)->target = NULL;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		free (*stack);
		*stack = NULL;
		*stack = temp;
	}
	*stack = NULL;
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
		return (0);
	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
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
	int		ret;

	i = -1;
	ret = 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = ++argv;
	if (!*args || !verify_args(args))
		ret = 0;
	while (args[++i] && ret == 1)
		if (!add_node(stack, ft_atoi(args[i]), i))
			ret = 0;
	if (argc == 2)
		free(args);
	return (ret);
}
