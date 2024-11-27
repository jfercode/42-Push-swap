/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:41:13 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/25 14:20:10 by jaferna2         ###   ########.fr       */
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
		*stack = new;
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
	long	temp_value;

	if (!stack)
	{
		ft_printf(2, "Error: Non or empty stack providen\n");
		return(-1);
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		temp_value = temp->value;
		if (temp_value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}