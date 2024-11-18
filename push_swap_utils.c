/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:42:42 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/07 15:42:44 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	- Invalid charcters: is_alpha
	- Double signs:	++ || --
	- mix num sign num
	// TO DO 
	repeated argvs
	int min and max 
*/
int	check_argument(char *argument_to_check)
{
	int		i;
	int		in_num;
	int		in_sign;

	i = 0;
	in_num = 0;
	in_sign = 0;
	while (argument_to_check[i])
	{
		if (argument_to_check[i] == 32)
		{
			in_num = 0;
			in_sign = 0;
		}
		else if (ft_isalpha(argument_to_check[i]))
			return (-1);
		else if ((argument_to_check[i] == '+' || argument_to_check[i] == '-'))
		{
			if (in_sign == 1 || in_num == 1)
				return (-1);
			in_sign = 1;
		}
		else if (ft_isdigit(argument_to_check[i]))
		{
			in_num = 1;
			in_sign = 0;
		}
		i++;
	}
	return (0);
}

char	*arguments_union(char **argv)
{
	int		i;
	char	*union_str;

	i = 1;
	union_str = malloc(1);
	while (argv[i])
	{
		union_str = ft_strjoin(union_str, " ");
		union_str = ft_strjoin(union_str, argv[i]);
		i++;
	}
	return (union_str);
}
