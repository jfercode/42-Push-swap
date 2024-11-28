/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:39:23 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/28 09:55:08 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// // Initializes the nodes for sorted 
// static void	init_stacks_nodes(t_stack **stack_a, t_stack **stack_b)
// {
// 	current_indx(stack_a);
// 	current_indx(stack_b);
// 	set_target_a(stack_a, stack_b);
// 	cost_analysis(stack_a, stack_b);
// 	set_cheapest(stack_a);
// }

// // Initializes the nodes from stack_b to be sorted 
// static void	init_nodes_b(t_stack **stack_a, t_stack **stack_b)
// {
// 	current_indx(stack_a);
// 	current_indx(stack_b);
// 	set_target_b(stack_b, stack_a);
// }

// Algorithm to order a stack with two elements
void	order_2_numbers(t_stack **stack_to_order)
{
	t_stack	*temp;

	if (!stack_to_order || !*stack_to_order)
	{
		ft_printf(2, "Error: Cannot order stack\n");
		return ;
	}
	temp = *stack_to_order;
	sa(stack_to_order);
}

// Algorithm to order a stack with three elements
void	order_3_numbers(t_stack **stack_a)
{
	if (((*stack_a)->value > (*stack_a)->next->value)
		&& ((*stack_a)->value > (*stack_a)->next->next->value))
		ra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	if ((*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		rra(stack_a);
		sa(stack_a);
	}
}

// --TO DO solve error in this-- // 
//	Implementation of turkish algorithm for sorting a stack
void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_size(stack_a);
	if (len_a-- > 3 && !check_stack_order_status(stack_a))
	 	pb(stack_a, stack_b);
	if (len_a-- > 3 && !check_stack_order_status(stack_a))
	 	pb(stack_a, stack_b);
	// while (len_a-- > 3 && !check_stack_order_status(stack_a))
	// {
	// 	init_stacks_nodes(stack_a, stack_b);
	// 	move_a_to_b(stack_a, stack_b);
	// }
	// order_3_numbers(stack_a);
	// while (*stack_b)
	// {
	// 	init_nodes_b(stack_a, stack_b);
	// 	move_b_to_a(stack_a, stack_b);
	// }
	// current_indx(stack_a);
}
