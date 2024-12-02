/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:41:13 by jaferna2          #+#    #+#             */
/*   Updated: 2024/12/01 12:26:37 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Create a new node
t_stack	*create_node(long value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->indx = 0;
	new_node->push_cost = 0;
	new_node->above_median = 0;
	new_node->is_cheapest = 0;
	new_node->next = (NULL);
	new_node->target = (NULL);
	return (new_node);
}

// Free stacks 
void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*stack = NULL;
}

// Cheak for repeated elements in the stack
int	check_repeat_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*aux;
	long	temp_value;

	aux = *stack;
	while (aux->next != NULL)
	{
		temp_value = aux->value;
		temp = aux->next;
		while (temp != NULL)
		{
			if (temp_value == temp->value)
				return (free_stack(stack), 0);
			temp = temp->next;
		}
		aux = aux->next;
	}
	return (1);
}

// Count the total of elements in the stack
int	stack_size(t_stack **stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	if (!stack || !*stack)
		return (0);
	temp = *stack;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

// Print in shell the stack
void	print_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
	{
		ft_printf(2, "Error: NULL stack\n");
		return ;
	}
	temp = *stack;
	while (*stack != NULL)
	{
		ft_printf(1, "Value: %d || ", (*stack)->value);
		ft_printf(1, "Indx: %d || ", (*stack)->indx);
		ft_printf(1, "Push cost: %d || ", (*stack)->push_cost);
		if ((*stack)->above_median == 1)
			ft_printf(1, "Is_Above_Median || ");
		if ((*stack)->is_cheapest)
			ft_printf(1, "Is_cheapest || ");
		if ((*stack)->next)
			ft_printf(1, "Next-> %p || ", (*stack)->next);
		if ((*stack)->target)
			ft_printf(1, "Target-> %p", (*stack)->target);
		ft_printf(1, "\n");
		(*stack) = (*stack)->next;
	}
	*stack = temp;
}
