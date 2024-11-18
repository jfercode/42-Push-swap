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

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || strlen(str) == 0)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (is_valid_integer_value(str));
}

int	is_valid_integer_value(char *str)
{
	long	num;

	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
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
