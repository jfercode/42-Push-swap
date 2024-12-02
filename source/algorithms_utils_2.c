/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:44:50 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/01 12:30:20 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Executes rotates in both stacks until cheapest node is head of stack a
void	rotate_both(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest_node)
{
	while ((*stack_b) != cheapest_node->target
		&& *stack_a != cheapest_node)
		rr(stack_a, stack_b);
	current_indx(stack_a);
	current_indx(stack_b);
}

// Executes rev_rot in both stacks until cheapest node is head of stack a
void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest_node)
{
	while ((*stack_b) != cheapest_node->target
		&& *stack_a != cheapest_node)
		rrr(stack_a, stack_b);
	current_indx(stack_a);
	current_indx(stack_b);
}

// Prepare the stack with rot and rr until node we want is on top
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_n)
{ 
	while (*stack != top_node)
	{
		if (stack_n == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_n == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

// Sets the target for each node from stack_b in the stack_a
static void	set_target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*target_node;
	long	best_match_indx;

	temp_b = *stack_b;
	while (temp_b)
	{
		best_match_indx = LONG_MAX;
		target_node = NULL;
		temp_a = *stack_a;
		while (temp_a)
		{
			if ((temp_a->value > temp_b->value)
				&& (temp_a->value < best_match_indx))
			{
				best_match_indx = temp_a->value;
				target_node = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (best_match_indx == LONG_MAX)
			temp_b->target = find_min(stack_a);
		else
			temp_b->target = target_node;
		temp_b = temp_b->next;
	}
}

// Prepare the nodes in both stacks for future operations
void	init_nodes_b(t_stack **stack_a, t_stack **stack_b)
{
	current_indx(stack_a);
	current_indx(stack_b);
	set_target_b(stack_a, stack_b);
}
