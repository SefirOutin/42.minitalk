/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:49:42 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:44:54 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *p, int v, size_t size)
{
	unsigned int	i;
	unsigned char	*s;

	i = 0;
	s = p;
	while (i++ < size)
		*s++ = (unsigned char)v;
	return (p);
}
/*
int	main()
{
	char str[] = "almost every programmer should know memset!";

	ft_memset(str + 6, '$', 6);
	printf("%s", str);
	memset(str + 6, '[', 6);
	printf("%s", str);
	return 0;
}*/
