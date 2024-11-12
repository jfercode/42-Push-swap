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
		if (argument_to_check[i] == ' ')
		{
			in_num = 0;
			in_sign = 0;
		}
		if (ft_isalpha(argument_to_check[i]))
			return (-1);
		if ((argument_to_check[i] == '+' || argument_to_check[i] == '-'))
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
		else
			return (-1);
		i++;
	}
	return (0);
}

/**
 * @brief  Obtain the arguments in one single strings
 * @param  arguments_union all the arguments
 * @return returns a string with all the arguments given
 */
char	*arguments_union(char **arguments_union)
{
	int		i;
	char	*temp_un;

	i = 1;
	temp_un = malloc(1);
	while (arguments_union[i])
	{
		temp_un = ft_strjoin(temp_un, arguments_union[i]);
		temp_un = ft_strjoin(temp_un, " ");
		i++;
	}
	return (temp_un);
}