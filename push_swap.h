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
# include "libft/libft.h"

//	node is the number
typedef struct s_node
{
	int				value;
	int				indx;
	struct s_node	*next;
}					t_node;

// the both stacks 
typedef struct s_stack
{
	t_node	*top;
	int		size;
}					t_stack;

int		is_valid_number(char *str);
int		is_valid_integer_value(char *str);
char	*arguments_union(char **argv);

#endif /*PUSH _SWAP_H*/