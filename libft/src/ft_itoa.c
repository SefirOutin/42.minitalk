/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:46:52 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:44:13 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	nb_malloc(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	rev_tab(char *nb)
{
	char	buf;
	int		len;
	int		i;

	len = ft_strlen(nb) - 1;
	i = 0;
	if (nb[i] == 45)
		i++;
	while (i < len)
	{
		buf = nb[i];
		nb[i] = nb[len];
		nb[len] = buf;
		i++;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	long int		nbr;

	i = 0;
	nbr = n;
	str = malloc((nb_malloc(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		nbr *= -1;
		str[i] = 45;
		i++;
	}
	while (i < nb_malloc(n))
	{
		str[i] = nbr % 10 + 48;
		nbr /= 10;
		i++;
	}
	str[i] = '\0';
	rev_tab(str);
	return (str);
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(2147483648LL));
// }