/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:27:34 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/10 16:59:01 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (0);
	
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	stack_a = NULL;
	stack_b = NULL;
	if (!init_stack(argc, argv, stack_a))
		return (0);
	while (*stack_a)
	{
		ft_printf("nbr = %i, index = %i", (*stack_a)->nbr, (*stack_a)->index);
		*stack_a = (*stack_a)->next;
	}
	return (1);
}

