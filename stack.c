/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:41:13 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/19 10:41:15 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(long value, long indx)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->indx = indx;
	new_node->next = (NULL);
	new_node->prev = (NULL);
	return (new_node);
}

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

int	stack_size(t_stack **stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	if (!stack || !*stack)
		return (0);
	temp = *stack;
	while (temp->next != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
