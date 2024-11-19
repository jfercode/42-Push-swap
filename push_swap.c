/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:22:42 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/06 12:22:43 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	*argv_union;
	char	**arr_arguments;
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void) argc;

	/*****Checking arguments***** */

	if (argc > 1)
	{
		i = 0;
		printf("Checking arguments");
		argv_union = arguments_union(argv);
		arr_arguments = ft_split(argv_union, 32);
		while (arr_arguments[i])
		{
			ft_printf(". ");
			if (!is_valid_number(arr_arguments[i]))
			{
				ft_printf("Error\n");
				return (0);
				break ;
			}
			i++;
		}
		ft_printf("\nArguments correct\n");

		/*******Prepare stacks*******/ // TO Do: prepare both stacks a with all values and b null

		stack_a = NULL;
		stack_b = NULL;
		print_stack(&stack_a);
		print_stack(&stack_b);
		i = 0;
		ft_printf("Filling stack a ");
		while (arr_arguments[i])
		{
			ft_printf(". ");
			push_stack(&stack_a, create_node(ft_atoi(arr_arguments[i]), i));
			i++;
		}
		ft_printf("Done\n");
		print_stack(&stack_a);
		print_stack(&stack_b);

		/*****Checking repeat arguments***** */

		if (!check_repeat_stack(&stack_a))
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (0);
}
