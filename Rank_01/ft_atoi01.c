/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvangene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:59:10 by bvangene          #+#    #+#             */
/*   Updated: 2023/07/27 15:30:38 by bvangene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || ((str[i] >= '\t') && (str[i] <= '\r')))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ((str[i] >= '0') && (str[i] <= '9')))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	printf ("%d\n", ft_atoi(argv[1]));
	return (0);
}
