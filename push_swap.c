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
	int		*stack;

	(void) argc;
	i = 1;

	stack = argument_to_array(argv);
	while (stack)
	{
		ft_printf("Param %d: %s\n", i ,stack[i]);
		i++;
	}
	return (0);
}
