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
	char	*arg;
	(void) argc;

	arg = arguments_union(argv);
	printf ("All in one: %s\n", arg);
	printf("Checking arguments...\n");
	if (check_argument(arg))
		ft_printf("Correct\n");
	else
		ft_printf("Error\n");
	return (0);
}
