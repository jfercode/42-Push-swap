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

int	check_argument(char *argument_to_check)
{
	int		i;

	i = 0;
	if (argument_to_check[i] == '\0')
		return (-1);
	while ((argument_to_check[i] >= 9 && argument_to_check[i] <= 13) 
		|| argument_to_check[i] == 32)
		i++;
	if (argument_to_check[i] == '-' || argument_to_check[i] == '+')
		i++;
	while (argument_to_check[i])
	{
		if (!isdigit(argument_to_check[i]))
			return (-1);
		i++;
	}
	return (0);

}

int	*argument_to_array(char **arguments)
{
	int	i;

	i = 0;
	// 1- TEST THE ARRAY GIVEN
	if (!arguments)
		ft_printf("BAD");
	while (*arguments[i])
	{
		if (check_argument(arguments[i]) == 0)
			ft_printf("%s\n", *arguments[i++]);
	}
	return (NULL);
}
