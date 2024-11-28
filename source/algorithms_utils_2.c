/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:46:09 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/28 11:46:19 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	prep_for_push(t_stack **stack, t_stack *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
	
}
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest_node;

	cheapest_node = get_cheapest(stack_a);
	printf("CHeapest node value: %ld\n", cheapest_node->value);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rr(stack_a, stack_b);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
		rrr(stack_a, stack_b);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target, 'b');
	pb(stack_a, stack_b);
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b);
}

void	min_on_top(t_stack **stack)
{
	while ((*stack)->value != find_min(stack)->value)
	{
		if (find_min(stack)->above_median)
			ra(stack);
		else
			rra(stack);
	}
}
/*	Assigns a target node from the `stack_to_target(a)` 
	to each node in `stack_to_set(b)`.	*/
void	set_target_b(t_stack **stack_to_set, t_stack **stack_to_target)
{
	long	best_match_indx;
	t_stack	*current_a;
	t_stack	*target_node;

	while (*stack_to_set)
	{
		best_match_indx = LONG_MAX;
		current_a = *stack_to_target;
		while (current_a)
		{
			if (current_a->value > (*stack_to_set)->value 
				&& current_a->value < best_match_indx)
			{
				best_match_indx = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_indx == LONG_MAX)
			(*stack_to_set)->target = find_min(stack_to_target);
		else
			(*stack_to_set)->target = target_node;
		*stack_to_set = (*stack_to_set)->next;
	}
}
