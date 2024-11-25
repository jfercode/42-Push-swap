/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:37:20 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/19 15:37:22 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack	**stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_size(stack) >= 2)
	{
		first = *stack;
		second = first->next;
	}
}
