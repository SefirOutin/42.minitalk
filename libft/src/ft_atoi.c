/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:14:51 by soutin            #+#    #+#             */
/*   Updated: 2023/05/18 17:00:10 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *nptr)
{
	int	number;
	int	sign;
	int	nbs;

	nbs = 0;
	number = 0;
	sign = 1;
	while ((*nptr > 8 && *nptr <= 13) || *nptr == 32)
		nptr++;
	while (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			sign *= -1;
		nbs++;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		number = number * 10 + (*nptr - 48);
		nptr++;
	}
	if (nbs > 1)
		return (0);
	return (number * sign);
}

/*
int	main(int c, char **v)
{
	(void)c;
	printf("%d\n", ft_atoi(v[1]));
	printf("%d", atoi(v[1]));
	return 0;
}*/