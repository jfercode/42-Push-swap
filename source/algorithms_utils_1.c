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
		temp->indx = indx;
		if (indx <= median)
			temp->above_median = 1;
		else
			temp->above_median = 0;
		temp = temp->next;
		++indx;
	}
}

// Sets the target for each node from stack_a in the stack_b
static void	set_target_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*target_node;
	long	best_match;

	temp_a = *stack_a;
	while (temp_a)
	{
		best_match = LONG_MIN;
		temp_b = *stack_b;
		while (temp_b)
		{
			if ((temp_b->value < temp_a->value) && (temp_b->value > best_match))
			{
				best_match = temp_b->value;
				target_node = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (best_match == LONG_MIN)
			temp_a->target = find_max(stack_b);
		else
			temp_a->target = target_node;
		temp_a = temp_a->next;
	}
}

// Calculates the push cost for determinates the cheapest node 
static void	cost_analysis(t_stack **stack_a, t_stack **stack_b)
{
	long	len_a;
	long	len_b;
	t_stack	*temp_a;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	temp_a = *stack_a;
	while (temp_a)
	{
		temp_a->push_cost = temp_a->indx;
		if ((!temp_a->above_median))
			temp_a->push_cost = len_a -(temp_a->indx);
		if (temp_a->target->above_median)
			temp_a->push_cost += temp_a->target->indx;
		else
			temp_a->push_cost += len_b - (temp_a->target->indx);
		temp_a = temp_a->next;
	}
}

// Determinates what is the cheapest node (depending on the push cost) 
void	set_cheapest_node(t_stack	**stack)
{
	long	cheapest_value;
	t_stack	*temp;
	t_stack	*cheapest_node;

	if (!*stack)
		return ;
	cheapest_value = LONG_MAX;
	temp = *stack;
	while (temp)
	{
		if (temp->push_cost < cheapest_value)
		{
			cheapest_value = temp->push_cost;
			cheapest_node = temp;
		}
		temp = temp->next;
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
