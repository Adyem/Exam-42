/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvangene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:44:44 by bvangene          #+#    #+#             */
/*   Updated: 2023/07/27 10:25:29 by bvangene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_write_number(int number)
{
	char	c;

	if (number > 9)
		ft_write_number(number / 10);
	c = '0' + number % 10;
	ft_putchar (c);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if ((i % 5 == 0) && (i % 3 == 0))
			write (1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else
			ft_write_number(i);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
