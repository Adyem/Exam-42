/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvangene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:30:01 by bvangene          #+#    #+#             */
/*   Updated: 2023/07/27 15:53:55 by bvangene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	ascii[256];

	i = 0;
	while (i < 256)
	{
		ascii[i] = 0;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (ascii[(int)s1[i]] == 0)
		{
			write (1, &s1[i], 1);
			ascii[(int)s1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (ascii[(int)s2[i]] == 0)
		{
			write (1, &s2[i], 1);
			ascii[(int)s2[i]] = 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write (1, "\n", 1);
	return (0);
}
