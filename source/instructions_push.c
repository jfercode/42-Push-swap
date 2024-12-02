/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:02:05 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/29 11:18:27 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Takes the first element on top of a stack and puts it on the other */
void	push(t_stack **stack_a, t_stack **stack_b)
{
	long		value;

	value = pop_stack(stack_b);
	push_stack(stack_a, create_node(value));
}

/* If B is not empty it takes the first element on top of B and puts it on A */
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
	{
		ft_printf(2, "Error: Stack B is empty, cannot push to A.\n");
		exit(1);
	}
	push(stack_a, stack_b);
	ft_printf(1, "pa\n");
}

/* If A is not empty, it takes the first element on top of A and puts it on B */
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
	{
		ft_printf(2, "Error: Stack A is empty, cannot push to B.\n");
		exit(1);
	}
	push(stack_b, stack_a);
	ft_printf(1, "pb\n");
}
