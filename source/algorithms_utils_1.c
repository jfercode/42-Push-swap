/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:36:21 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/01 12:35:24 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Sets and refresh the current position for each node in a stack 
void	current_indx(t_stack **stack)
{
	long	indx;
	long	median;
	t_stack	*temp;

	if (!stack || !*stack)
    	return ;
	indx = 0;
	temp = *stack;
	median = stack_size(stack) / 2;
	while (temp)
	{
		(temp)->indx = indx;
		if (indx <= median)
			(temp)->above_median = 1;
		else
			(temp)->above_median = 0;
		temp = (temp)->next;
		++indx;
	}
}

// Sets the target for each node from stack_a in the stack_b
static void	set_target_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	t_stack	*target_node;
	long	best_match_indx;

	while (*stack_a)
	{
		best_match_indx = LONG_MIN;
		temp_b = *stack_b;
		while (temp_b)
		{
			if ((temp_b->value < (*stack_a)->value) 
				&& (temp_b->value > best_match_indx))
			{
				best_match_indx = temp_b->value;
				target_node = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (best_match_indx == LONG_MIN)
			(*stack_a)->target = find_max(stack_b);
		else
			(*stack_a)->target = target_node;
		*stack_a = (*stack_a)->next;
	}
}

// Calculates the push cost for determinates the cheapest node 
static void	cost_analysis(t_stack **stack_a, t_stack **stack_b)
{
	long	len_a;
	long	len_b;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	while (*stack_a)
	{
		(*stack_a)->push_cost = (*stack_a)->indx;
		if ((!(*stack_a)->above_median))
			(*stack_a)->push_cost = len_a -((*stack_a)->indx);
		if ((*stack_a)->target->above_median)
			(*stack_a)->push_cost += (*stack_a)->target->indx;
		else
			(*stack_a)->push_cost += len_b - ((*stack_a)->target->indx);
		*stack_a = (*stack_a)->next; 
	}
	
}

// Determinates what is the cheapest node (depending on the push cost) 
void	set_cheapest_node(t_stack	**stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!*stack)
		return ;
	cheapest_value = LONG_MAX;
	while (*stack)
	{
		if ((*stack)->push_cost < cheapest_value)
		{
			cheapest_value = (*stack)->value;
			cheapest_node = *stack;
		}
		*stack = (*stack)->next;
	}
	cheapest_node->is_cheapest = 1;
}

// Prepare the nodes in both stacks for future operations
void	init_nodes_a(t_stack **stack_a, t_stack **stack_b)
{
	current_indx(stack_a);
	current_indx(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis(stack_a, stack_b);
	set_cheapest_node(stack_a);
}