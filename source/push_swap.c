/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:22:42 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/30 12:37:08 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Function that check the arguments
static int	check_arguments(char **argv)
{
	int		i;

	i = 0;
	if (!argv[i])
		return (ft_printf(2, "Error: No arguments provided\n"), 0);
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
		{
			ft_printf(2, "Error: incorrect arguments\n");
			return (0);
		}
		i++;
	}
	return (1);
}

// Fill stacks with a splitted arguments
static	t_stack	*fill_stack(char **arr_arguments)
{
	int		i;
	t_stack	*stack;
	t_stack	*new_node;

	i = 0;
	stack = NULL;
	if (!arr_arguments)
		return (ft_printf(2, "Error: No arguments to fill stack\n"), NULL);
	while (arr_arguments[i])
	{
		new_node = create_node(ft_atol(arr_arguments[i]));
		push_stack(&stack, new_node);
		i++;
	}
	return (stack);
}

// Free all memory
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

// Determinates all possible cases and aplies the correct algoritm
static void	order_stacks(t_stack **stack_a, t_stack **stack_b)
{
	long	stack_s;

	(void) stack_b;
	stack_s = stack_size(stack_a);
	if (stack_s == 2)
		sa(stack_a);
	else if (stack_s == 3)
		sort_three(stack_a);
	else
		sort_stack(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	char	*argv_union;
	char	**arr_arguments;
	t_stack	*stack_a;
	t_stack	*stack_b;

	argv_union = NULL;
	arr_arguments = NULL;
	if (argc == 1)
	 	return (0);
	argv_union = arguments_union(argv);
	arr_arguments = ft_split(argv_union, 32);
	stack_a = NULL;
	stack_b = NULL;
	if (!check_arguments(arr_arguments))
		return (free_all_memory(argv_union, arr_arguments, stack_a, stack_b), 0);
	stack_a = fill_stack(arr_arguments);
	if (!check_repeat_stack(&stack_a))
		return (ft_printf(2, "Error: Repeated elements\n"), 0);
	if (!check_stack_order_status(&stack_a))
		order_stacks(&stack_a, &stack_b);
	free_all_memory(argv_union, arr_arguments, stack_a, stack_b);
	return (0);
}
