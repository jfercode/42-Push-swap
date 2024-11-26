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

#include "push_swap.h"

// Function to add (or push) a node onto the stack
void	push_stack(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!stack || !new)
		return ;
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
		return (-1);
	temp = *stack;
	temp_value = temp->value;
	*stack = temp->next;
	free (temp);
	return (temp_value);
}
