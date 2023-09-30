/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:30:12 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:44:46 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned int	i;
	unsigned char	*d;
	unsigned char	*s;

	d = dest;
	s = (unsigned char *)src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i++ < size)
	{
		*d++ = *s++;
	}
	return (dest);
}
/*
int	main()
{
	char src [] = "non-void function does not return a value";
	char dest [50] = "";
	ft_memcpy(dest, src, 20);
	printf("%s", dest);
}*/
