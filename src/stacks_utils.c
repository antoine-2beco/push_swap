/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:49:20 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/15 13:26:40 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return (*(int *)error(0, "stack is NULL in free_stack"));
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

//static t_stack	*new_node(int nbr, int index)
//{
//	t_stack	*new_node;
//
//	new_node = malloc(sizeof(t_stack));
//	if (!new_node)
//		return (error(0, "node is NULL in new_nde\n"));
//	new_node->nbr = nbr;
//	new_node->index = index;
//	new_node->push_cost = 0;
//	new_node->above_median = NULL;
//	new_node->cheapest = NULL;
//	new_node->target = NULL;
//	new_node->prev = NULL;
//	new_node->next = NULL;
//	return (new_node);
//}

static t_stack	*get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static int	add_node(t_stack **stack, int nbr, int index)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return (*(int *)error(0, "stack is NULL in add_node\n"));
	node = malloc(sizeof(t_stack));
	if (!node)
		return (*(int *)error(0, "node malloc failed in add_node\n"));
	node->nbr = nbr;
	node->index = index;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return (1);
}

int	init_stack(int argc, char *argv[], t_stack **stack)
{
	char	**args;
	int		i;

	i = -1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		argv++;
		args = argv;
	}
	while (args[++i])
	{
		ft_printf("arg[%i]\n", i);
		if (!add_node(stack, ft_atoi(args[i]), i))
			return (*(int *)error(0, "add_node return NULL\n"));
	}
	if (argc == 2)
		free(args);
	return (1);
}


//ft_printf("11 %p : nbr = %i, index = %i, push_cost = %i, prev = %p, next = %p\n", *stack, (*stack)->nbr, (*stack)->index, (*stack)->push_cost,(*stack)->prev, (*stack)->next);