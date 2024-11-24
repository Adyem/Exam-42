/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvangene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:18:00 by bvangene          #+#    #+#             */
/*   Updated: 2023/07/27 20:19:07 by adyem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	ascii[256];

	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	while (i < 256)
	{
		ascii[i] = 0;
		i++;
	}
	i = 0;
	while (argv[1][i])
	{
		if (ascii[(int)argv[1][i]] == 0)
		{
			write (1, &argv[1][i], 1);
			ascii[(int)argv[1][i]] = 1;
		}
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		if (ascii[(int)argv[2][i]] == 0)
		{
			write (1, &argv[2][i], 1);
			ascii[(int)argv[2][i]] = 1;
		}
		i++;
	}
	write (1, "\n", 1);
	return (0);
}
