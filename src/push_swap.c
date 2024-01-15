/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:27:34 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/15 13:24:19 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	*error(void *ret, char *str)
{
	ft_printf("-----------------------------------\n");
	ft_printf("%s", str);
	ft_printf("-----------------------------------\n");
	return (ret);
}

int	push_swap(int argc, char *argv[])
{
	t_stack	*stack_a;
	int		i;
	//t_stack	**stack_b;

	i = 0;
	ft_printf("argc = %i\n", argc);
	if (argc < 2)
		return (0);

	if (!init_stack(argc, argv, &stack_a))
		return (*(int *)error(0, "init_stack return NULL\n"));
	ft_printf("---\n");
	while (i++ <= 2)
	{
		ft_printf("nbr = %i, index = %i, push_cost = %i\n", (stack_a)->nbr, (stack_a)->index, (stack_a)->push_cost);
		stack_a = (stack_a)->prev;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	ft_printf("return = %i", push_swap(argc, argv));
}
