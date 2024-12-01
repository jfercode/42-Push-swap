/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:41:13 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/01 12:16:59 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Function to add (or push) a node onto the stack
void	push_stack(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!stack || !new)
	{
		(ft_printf(1, "Error: Cannot push the stack\n"));
		exit(1);
	}
	if (!*stack)
	{
		*stack = new;
	}
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

// Function to pop a value from the stack
long	pop_stack(t_stack **stack)
{
	t_stack	*temp;
	long	temp_value;

	if (!stack)
		return (ft_printf(1, "Error: Cannot pop the stack\n"), -1);
	temp = *stack;
	temp_value = temp->value;
	*stack = temp->next;
	free (temp);
	return (temp_value);
}

// Function that checks if the stack is ordered or not
int		check_stack_order_status(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
	{
		ft_printf(2, "Error: Non or empty stack providen\n");
		return(-1);
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

//	Find the node in a stack with the lowest value	
t_stack	*find_min(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*min_node;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	min_node = temp;
	while (temp)
	{
		if(temp->value < min_node->value)
			min_node = temp;
		temp = temp->next;
	}
	return (min_node);
}

//	Find the node in a stack with the biggest value	
t_stack	*find_max(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*max_node;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	max_node = temp;
	while (temp)
	{
		if(temp->value > max_node->value)
			max_node = temp;
		temp = temp->next;
	}
	return (max_node);
}