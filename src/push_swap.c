/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:27:34 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/20 10:27:58 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error(int ret, t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("Error\n");
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	return (ret);
}

int	verify_args(char **args)
{
	int				i;
	int				j;
	long long int	arg;

	i = -1;
	while (args[++i])
	{
		j = -1;
		arg = ft_atoi(args[i]);
		if (arg > INT32_MAX || arg < INT32_MIN)
			return (0);
		while (args[i][++j])
		{
			if (!ft_isdigit(args[i][j]) && args[i][j] != '-'
				&& args[i][j] != '+')
				return (0);
		}
		j = -1;
		while (args[++j])
		{
			if ((int)ft_atoi(args[j]) == arg && j != i)
				return (0);
		}
	}
	return (1);
}

static int	sort_stacks(t_stack **stack_a, t_stack **stack_b, int stack_a_len)
{
	t_stack	*temp;

	if (is_sorted(stack_a))
		return (1);
	if (stack_a_len <= 3)
		return (sort_3_nodes(stack_a, 'a'));
	push_node(stack_a, stack_b, 'b', 1);
	push_node(stack_a, stack_b, 'b', 1);
	while (get_stack_len(stack_a) > 3)
	{
		init_target_node(stack_a, stack_b);
		init_push_cost(stack_a, stack_b);
		sort_push_node(stack_a, stack_b);
	}
	sort_3_nodes(stack_a, 'a');
	while (get_stack_len(stack_b) > 0)
		sort_push_back_node(stack_a, stack_b);
	temp = get_min_node(stack_a);
	put_node_on_top(stack_a, 'a', &temp);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!init_stack(argc, argv, &stack_a))
		return (error(0, &stack_a, &stack_b));
	if (!sort_stacks(&stack_a, &stack_b, get_stack_len(&stack_a)))
		return (error(0, &stack_a, &stack_b));
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (1);
}
