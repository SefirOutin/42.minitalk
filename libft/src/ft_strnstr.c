/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:56:11 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:46:08 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;
	size_t	j;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	if (!l[i])
		return (b);
	if (!len)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (b[i + j] == l[j] && j + i < len)
		{
			if (l[j + 1] == '\0')
				return (b + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

// int	main()
// {
// 	char b[0xF] = "nyan !";
// 	printf("%s", strnstr(((void*)0), b, 0));
// 	printf("%s\n", ft_strnstr(((void*)0), b, 0));
// 	return 0;
// }