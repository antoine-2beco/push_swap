/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:27:34 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/29 10:25:11 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	error(int ret, char *str, t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("-----------------------------------\n");
	ft_printf("%s\n", str);
	ft_printf("-----------------------------------\n");
	free_stack(stack_a);
	free_stack(stack_b);
	return (ret);
}

int	sort_stacks(t_stack **stack_a, t_stack **stack_b, int stack_a_len)
{
	t_stack	*temp;

	if (is_sorted(stack_a))
		return (1);
	if (stack_a_len <= 3)
		return (sort_3_nodes(stack_a, 'a'));
	push_node(stack_a, stack_b, 'b');
	push_node(stack_a, stack_b, 'b');
	while (get_stack_len(stack_a) > 3)
	{
		init_target_node(stack_a, stack_b);
		init_push_cost(stack_a);
		sort_push_node(stack_a, 'a', stack_b, 'b');
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
		return (error(0, "argc < 2\n", &stack_a, &stack_b));
	if (!init_stack(argc, argv, &stack_a))
		return (error(0, "init_stack return NULL\n", &stack_a, &stack_b));
	if (!sort_stacks(&stack_a, &stack_b, get_stack_len(&stack_a)))
		return (error(0, "sort_stacks return NULL\n", &stack_a, &stack_b));
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (1);
}
