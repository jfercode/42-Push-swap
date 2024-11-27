/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:04:27 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/06 12:04:28 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Include section
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../source/ft_libft/include/libft.h"
# include "../source/ft_printf/include/ft_printf.h"

//	Represents a node in a stack data structure
typedef struct s_node
{
	long			value;
	struct s_node	*next;
	struct s_node	*target;

}					t_stack;

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rotate(t_stack **stack);
void	rev_rot(t_stack **stack);
void	free_stack(t_stack **stack);
void	print_stack(t_stack **stack);
void	push_stack(t_stack **stack, t_stack *new);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	order_2_numbers(t_stack **stack_to_order);
void	order_3_numbers(t_stack **stack_to_order);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_a, t_stack **stack_b);

int		is_valid_number(char *str);
int		stack_size(t_stack **stack);
int		is_valid_integer_value(char *str);
int		check_repeat_stack(t_stack **stack);
int		check_stack_order_status(t_stack **stack);

long	pop_stack(t_stack **stack);

char	*arguments_union(char **argv);

t_stack	*create_node(long value);

#endif /*PUSH_SWAP_H*/