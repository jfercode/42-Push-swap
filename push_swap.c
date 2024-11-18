/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:22:42 by jaferna2          #+#    #+#             */
/*   Updated: 2024/11/06 12:22:43 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	*argv_union;
	char	**arr_arguments;

	(void) argc;
	i = 1;
	printf("Checking arguments...\n");
	argv_union = arguments_union(argv);
	arr_arguments = ft_split(argv_union, 32);
	while (*arr_arguments)
	{
		printf("%s\n", *arr_arguments);
		if (check_argument(*arr_arguments) == -1)
		{
			ft_printf("Error\n");
			break ;
		}
		arr_arguments++;
	}

	return (0);
}
