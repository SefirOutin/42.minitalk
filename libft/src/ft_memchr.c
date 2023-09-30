/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:12:22 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:44:40 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;

	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*src == (unsigned char)c)
			return (src);
		i++;
		src++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	//char *s = ft_memchr("The memchr() function  scans ", 's', 20);
// 	//printf("%s\n", s);
// 	//char	*t = memchr("The  memchr()  function  scans  ", 's', 20);
// 	//printf("%s", t);
// 	char	s[] = {0, 1, 2, 3, 4, 5};
// 	char	t[] = {0, 1, 2, 3, 4, 5};
// 	int	i = 0;
// 	ft_memchr(s, 2 + 256, 3);
// 	printf("le mien\n");
// 	while (i < 5)
// 	{
// 		printf("%d\n", s[i]);
// 		i++;
// 	}
// 	memchr(t, 2 + 256, 3);
// 	printf("l'autre\n");
// 	while (i < 5)
// 	{
// 		printf("%d\n", t[i]);
// 		i++;
// 	}
// 	return (0);
// }