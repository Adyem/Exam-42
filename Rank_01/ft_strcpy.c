/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvangene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:46:46 by bvangene          #+#    #+#             */
/*   Updated: 2023/07/27 11:52:11 by bvangene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	main(int argc, char **argv)
{
	char	c[50];

	if (argc != 2)
	{
		printf ("ERROR!");
		return (0);
	}
	ft_strcpy(c, argv[1]);
	printf("%s", c);
	return (1);
}
