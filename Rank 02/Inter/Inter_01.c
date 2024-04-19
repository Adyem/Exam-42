/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adyem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:30:08 by adyem             #+#    #+#             */
/*   Updated: 2024/02/08 12:39:22 by adyem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_number(char *s1, char *s2, int i, int j)
{
	int x;

	x = 0;
	while (i > x)
	{
		if (s1[x] == s1[i])
			return (0);
		x++;
	}
	x = 0;
	while (j > x)
	{
		if (s2[x] == s2[j])
		{
			return (0);
		}
		x++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				if (check_number(argv[1], argv[2], i, j) == 1)
					write (1, &argv[1][i], 1);
			j++;
		}
		i++;
	}
	write (1, "\n", 1);
	return (0);
}
