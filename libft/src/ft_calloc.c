/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:38:26 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:43:55 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*d;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	d = malloc((nmemb) * size);
	if (!d)
		return (NULL);
	ft_memset(d, 0, nmemb * size);
	return (d);
}

// int	main(void)
// {
// 	ft_calloc(SIZE_MAX, SIZE_MAX);
// 	return (0);
// }