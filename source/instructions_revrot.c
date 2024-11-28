/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_revrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:47:44 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/26 09:49:12 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/* Shifts all the elements of the stack one position downwards. 
	The last element becomes the first.*/
void	rev_rot(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		ft_printf(2, "Error: Cannot reverse rotate cannot\n");
		exit(1);
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		second_last = temp;
		temp = temp->next;
	}
	last = temp;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

/* Reverse rotate A */
void	rra(t_stack **stack_a)
{
	rev_rot(stack_a);
	current_indx(stack_a);
	ft_printf(1, "rra\n");
}

/* Reverse rotate B */
void	rrb(t_stack **stack_b)
{
	rev_rot(stack_b);
	current_indx(stack_b);
	ft_printf(1, "rrb\n");
}

/* Executes reverse rotate A and reverse rotate B */
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rot(stack_a);
	rev_rot(stack_b);
	current_indx(stack_a);
	current_indx(stack_b);
	ft_printf(1, "rrr\n");
}
