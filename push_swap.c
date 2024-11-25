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

/*****Checking arguments***** */

static int	check_arguments(char **argv)
{
	int		i;

	i = 1;
	if (!argv[i])
		return (ft_printf("Error: No arguments provided\n"), 0);
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
		{
			ft_printf("Error: incorrect arguments\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/*******Prepare stacks*******/

static	t_stack	*fill_stack(char **arr_arguments)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = NULL;
	if (!arr_arguments)
		return (ft_printf("Error: No arguments to fill stack\n"), NULL);
	while (arr_arguments[i])
	{
		push_stack(&stack, create_node(ft_atoi(arr_arguments[i]), i));
		i++;
	}
	return (stack);
}
/*******Free memory*******/

static void	free_all_memory(char *argv_union, char **arr_arguments,
								t_stack *stack_a, t_stack *stack_b)
{
	char	**temp;

	temp = arr_arguments;
	if (argv_union != NULL)
		free(argv_union);
	if (arr_arguments != NULL)
	{
		while (*temp)
		{
			free(*temp);
			temp++;
		}
	}
	free (arr_arguments);
	if (stack_a != NULL)
		free_stack(&stack_a);
	if (stack_b != NULL)
		free_stack(&stack_b);
}

int	main(int argc, char *argv[])
{
	char	*argv_union;
	char	**arr_arguments;
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void) argc;
	argv_union = NULL;
	arr_arguments = NULL;
	argv_union = arguments_union(argv);
	arr_arguments = ft_split(argv_union, 32);
	stack_a = NULL;
	stack_b = NULL;
	if (!check_arguments(argv))
		return (0);
	stack_a = fill_stack(arr_arguments);
	if (!check_repeat_stack(&stack_a))
		return (ft_printf("Error: Repeated elements\n"), 0);
	free_all_memory(argv_union, arr_arguments, stack_a, stack_b);
	return (0);
}
