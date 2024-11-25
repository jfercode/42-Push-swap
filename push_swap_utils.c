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
	long	check_num;

	num = ft_atoi(str);
	check_num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	else if (num != check_num)
		return (0);
	return (1);
}

char	*arguments_union(char **argv)
{
	int		i;
	char	*union_str;
	char	*temp_str;

	i = 1;
	union_str = ft_calloc(1, 1);
	if (!union_str)
		return (NULL);
	union_str[0] = '\0';
	while (argv[i])
	{
		temp_str = ft_strjoin(union_str, " ");
		if (!temp_str)
			return (free(union_str), NULL);
		free(union_str);
		union_str = temp_str;
		temp_str = ft_strjoin(union_str, argv[i]);
		if (!temp_str)
			return (free(union_str), NULL);
		free(union_str);
		union_str = temp_str;
		i++;
	}
	return (union_str);
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
