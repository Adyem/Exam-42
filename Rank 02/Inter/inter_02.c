/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvangene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:40:47 by bvangene          #+#    #+#             */
/*   Updated: 2024/02/09 13:47:08 by bvangene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int	i;
	int seen[256] = {0};
	int printed[256] = {0};

	i = 0;
	while (s2[i])
	{
		seen[(int)s2[i]] = 1;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (!printed[(int)s1[i]] && seen[(int)s1[i]])
		{
			write (1, &s1[i], 1);
			printed[(int)s1[i]] = 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter (argv[1], argv[2]);
	write (1, "\n", 1);
	return (0);
}
