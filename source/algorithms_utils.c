/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:00:43 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/28 10:00:44 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	Assigns an index and determines whether each element in a stack
	is above or below the median based on its position.	*/
void	current_indx(t_stack **stack)
{
	long		i;
	long		median;
	t_stack		*temp;

	i = 0;
	if (!stack || !*stack)
		return ;
	median = stack_size(stack) / 2;
	temp = *stack;
	while (temp)
	{
		temp->indx = i;
		if(i <= median)
			temp->above_median = 1;
		else
			temp->above_median = 0;
		temp = temp->next;
		++i;
	}
}
/*	Assigns a target node from the `stack_to_target(b)` 
	to each node in `stack_to_set(a)`.	*/
void	set_target_a(t_stack **stack_to_set, t_stack **stack_to_target)
{
	long	best_match_indx;
	t_stack	*current_b;
	t_stack	*target_node;

	while (*stack_to_set)
	{
		best_match_indx = LONG_MIN;
		current_b = *stack_to_target;
		while (current_b)
		{
			if (current_b->value < (*stack_to_set)->value 
				&& current_b->value > best_match_indx)
			{
				best_match_indx = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_indx == LONG_MIN)
			(*stack_to_set)->target = find_max(stack_to_target);
		else
			(*stack_to_set)->target = target_node;
		*stack_to_set = (*stack_to_set)->next;
	}
}

// Calculates the push_cost from each node from stack_a 
void	cost_analysis(t_stack **stack_a, t_stack **stack_b)
{
	long	len_a;
	long	len_b;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	while (*stack_a)
	{
		(*stack_a)->push_cost = (*stack_a)->indx;
		if (!(*stack_a)->above_median)
			(*stack_a)->push_cost = len_a - (*stack_a)->indx;
		if ((*stack_a)->target->above_median)
			(*stack_a)->push_cost += (*stack_a)->target->indx;
		else
			(*stack_a)->push_cost += len_b - ((*stack_a)->target->indx);
		*stack_a = (*stack_a)->next; 
	}
}

// set_cheapest (its deppend directly from the push_cost) node from a stack
void	set_cheapest(t_stack **stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (*stack)
	{
		if ((*stack)->push_cost < cheapest_value)
		{
			cheapest_value = (*stack)->push_cost;
			cheapest_node = *stack;
		}
		*stack = (*stack)->next;
	}
	cheapest_node->cheapest = 1;
}

// get_cheapest (its deppend directly from the push_cost) node from a stack
t_stack	*get_cheapest(t_stack **stack)
{
	t_stack	*cheapest_node;

	if (!stack)
		return (NULL);
	cheapest_node = *stack;
	while (*stack)
	{
		if ((*stack)->cheapest == 1)
		{
			cheapest_node = *stack;
			return(cheapest_node);
		}
		*stack = (*stack)->next;
	}
	return (cheapest_node);
}