/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvangene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:09:48 by bvangene          #+#    #+#             */
/*   Updated: 2023/07/27 16:25:27 by bvangene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int	i;
	int printed[256];
	int present_in_s2[256];

	i = 0;
	while (i < 256)
	{
		printed[i] = 0;
		present_in_s2[i] = 0;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		present_in_s2[(int)s2[i]] = 1;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!printed[(int)s1[i]] && present_in_s2[(int)s1[i]])
		{
			write(1, &s1[i], 1);
			printed[(int)s1[i]] = 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
