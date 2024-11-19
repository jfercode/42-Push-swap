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
	t_stack	*to_free;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	while (temp != NULL)
	{
		to_free = *stack;
		temp = temp->next;
		free(to_free);
	}
	*stack = NULL;
}

int	check_repeat_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*aux;
	long	temp_value;

	temp = *stack;
	aux = *stack;
	while (aux->next != NULL)
	{
		temp = aux;
		temp_value = aux->value;
		while (temp->next != NULL)
		{
			if (temp->value == temp_value)
				return (0);
			temp = temp->next;
		}
		aux = aux->next;
	}
	return (1);
}

void	print_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
	{
		ft_printf("NULL stack\n");
		return ;
	}
	temp = *stack;
	while (temp != NULL)
	{
		ft_printf("Value: %d, Index: %d\n", temp->value, temp->indx);
		temp = temp->next;
	}
}
