/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:39:23 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/01 12:36:27 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//	Obtain the cheapest node
static t_stack	*get_cheapest(t_stack **stack)
{
	t_stack	*cheapest;
	
	cheapest = *stack;
	while (*stack)
	{
		if ((*stack)->is_cheapest)
			cheapest = *stack;
		*stack = (*stack)->next;
	}
	return (cheapest);
}

// Moves nodes from stack a to b
static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(stack_a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target, 'b');
	pb(stack_a, stack_b);
}
// Moves nodes from stack b to a
static void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b);
}

// Executes all moves to bring min value node on top
static void	min_on_top(t_stack **stack)
{
	t_stack	*min_value_node;

	min_value_node = find_min(stack);
	while ((*stack)->value != min_value_node->value)
	{
		if (min_value_node->above_median)
			ra(stack);
		else
			rra(stack);
	}
}

/* Implementation of Turk algorithm */
void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	len_a = stack_size(stack_a);
	if (len_a-- > 3 && !check_stack_order_status(stack_a))
		pb(stack_a, stack_b);
	if (len_a-- > 3 && !check_stack_order_status(stack_a))
		pb(stack_a, stack_b);
	while (len_a-- > 3 && !check_stack_order_status(stack_a))
	{
		init_nodes_a(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(stack_a, stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_indx(stack_a);
	min_on_top(stack_a);
}