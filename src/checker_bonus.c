/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:21:33 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/26 14:58:00 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
		if (!args[i][0] || arg > INT32_MAX || arg < INT32_MIN)
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

static int	get_operation(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "pa", 2) && ft_strlen(line) == 3)
		push_node(stack_b, stack_a, 'a', 0);
	else if (!ft_strncmp(line, "pb", 2) && ft_strlen(line) == 3)
		push_node(stack_a, stack_b, 'b', 0);
	else if (!ft_strncmp(line, "sa", 2) && ft_strlen(line) == 3)
		swap_node(stack_a, 'a', 0);
	else if (!ft_strncmp(line, "sb", 2) && ft_strlen(line) == 3)
		swap_node(stack_b, 'b', 0);
	else if (!ft_strncmp(line, "ss", 2) && ft_strlen(line) == 3)
		d_swap_node(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "ra", 2) && ft_strlen(line) == 3)
		rotate_node(stack_a, 'a', 0);
	else if (!ft_strncmp(line, "rb", 2) && ft_strlen(line) == 3)
		rotate_node(stack_b, 'b', 0);
	else if (!ft_strncmp(line, "rr", 2) && ft_strlen(line) == 3)
		d_rotate_node(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "rra", 3) && ft_strlen(line) == 4)
		reverse_rotate_node(stack_a, 'a', 0);
	else if (!ft_strncmp(line, "rrb", 3) && ft_strlen(line) == 4)
		reverse_rotate_node(stack_b, 'b', 0);
	else if (!ft_strncmp(line, "rrr", 3) && ft_strlen(line) == 4)
		d_reverse_rotate_node(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

static int	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	if (!line)
		return (0);
	while (line)
	{
		if (!get_operation(stack_a, stack_b, line))
			return (0);
		free (line);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return (0);
	}
	free (line);
	line = NULL;
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
	if (!sort_stacks(&stack_a, &stack_b))
		return (error(0, &stack_a, &stack_b));
	if (get_stack_len(&stack_a) != 1
		&& (!is_sorted(&stack_a) || get_stack_len(&stack_b) != 0))
	{
		ft_printf("KO\n");
		if (stack_a)
			free_stack(&stack_a);
		if (stack_b)
			free_stack(&stack_b);
		return (0);
	}
	ft_printf("OK\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (1);
}
