/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:39:23 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/27 11:39:24 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Algorithm to order a stack with two elements
void	order_2_numbers(t_stack **stack_to_order)
{
	t_stack	*temp;

	if (!stack_to_order || !*stack_to_order)
	{
		ft_printf(2, "Error: Cannot order stack");
		return ;
	}
	temp = *stack_to_order;
	sa(stack_to_order);
}

// Algorithm to order a stack with three elements
void	order_3_numbers(t_stack **stack_a)
{
	if (((*stack_a)->value > (*stack_a)->next->value) && 
		((*stack_a)->value > (*stack_a)->next->next->value))
		ra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	if ((*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		rra(stack_a);
		sa(stack_a);
	}
}
