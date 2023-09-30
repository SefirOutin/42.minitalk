/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:17:40 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:44:50 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*s;
	unsigned char	*d;
	long			n;

	n = count;
	s = (unsigned char *)src;
	d = dest;
	if (dest > src && (dest < src + n))
	{
		while (n--)
			d[n] = s[n];
	}
	else
		d = ft_memcpy(dest, src, count);
	return (dest);
}
/*
int	main()
{
	char str2[50] = "I am going from Delhi to Gorakhpur";
	printf( "Function:\tmemcpy with overlap\n" );
    printf( "Orignal :\t%s\n",str2);
    printf( "Source:\t\t%s\n", str2 + 5 );
    printf( "Destination:\t%s\n", str2 + 11 );
    ft_memmove( str2 + 11, str2 + 5, 29 );
    printf( "Result:\t\t%s\n", str2 );
    printf( "Length:\t\t%lu characters\n\n", strlen( str2 ) );
	
}
*/