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
# include "ft_printf/ft_printf.h"
# include "ft_libft/libft.h"

//	node is the number
typedef struct s_node
{
	long			value;
	long			indx;
	struct s_node	*next;
	struct s_node	*prev;

}					t_stack;

void	free_stack(t_stack **stack);
void	print_stack(t_stack **stack);
void	push_stack(t_stack **stack, t_stack *new);

int		is_valid_number(char *str);
int		is_valid_integer_value(char *str);
int		check_repeat_stack(t_stack **stack);

char	*arguments_union(char **argv);

t_stack	*create_node(long value, long indx);

#endif /*PUSH_SWAP_H*/