/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adyem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:06:08 by adyem             #+#    #+#             */
/*   Updated: 2024/02/08 16:09:36 by adyem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	verify_char(char *s, char c, int index)
{
	int	i;

	i = 0;
	while (index > i)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int len;

	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (verify_char(argv[1], argv[1][i], i) == 1)
			write (1, &argv[1][i], 1);
		i++;
	}
	len = i;
	i = 0;
	while (argv[2][i])
	{
		if (verify_char(argv[2], argv[2][i], i) == 1)
			if (verify_char(argv[1], argv[2][i], len) == 1)
				write (1, &argv[2][i], 1);
		i++;
	}
	write (1, "\n", 1);
	return (0);
}
