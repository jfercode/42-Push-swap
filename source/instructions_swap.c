/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:37:20 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/29 11:19:07 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/* If there are 2 or more numbers, swap the first 2 elements 
	at the top of the stack */
void	swap(t_stack **stack)
{
	long	aux_value;
	t_stack	*first;
	t_stack	*second;

	if (stack_size(stack) >= 2)
	{
		first = *stack;
		second = (*stack)->next;
		aux_value = first->value;
		first->value = second->value;
		second->value = aux_value;
	}
	else
	{
		ft_printf(2, "Error: Invalid size of stack can´t swap elements");
		exit(1);
	}
}

/* Swap stack A. */
void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf(1, "sa\n");
}

/* Swap stack B. */
void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf(1, "sb\n");
}

/* Swap both stack at the same time. */
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf(1, "sb\n");
}
