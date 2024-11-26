/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:47:44 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/25 14:47:45 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shifts all the elements of the stack up by one position. 
	The first element becomes the last. */
void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*first;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		ft_printf(2, "Error: cannot rotate invalid size of stack\n");
		exit(1);
	}
	first = *stack;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	*stack = (*stack)->next;
	temp->next = first;
	first->next = NULL;
}

/* Rotate stack A */
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf(1, "ra\n");
}

/*  Rotate stack B */
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf(1, "rb\n");
}

/* Executes rotate A and rotate B */
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf(1, "rr\n");
}
