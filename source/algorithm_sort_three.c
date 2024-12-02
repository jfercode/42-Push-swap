/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:25:14 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/30 17:30:07 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*Simple alogrithm to sort three values*/
void	sort_three(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = find_max(stack);
	if (biggest_node == *stack)
		ra(stack);
	else if (biggest_node == (*stack)->next)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}
