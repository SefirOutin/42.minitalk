/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:44:48 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:45:35 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;

	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (char *)s, ft_strlen(s) + 1);
	return (dest);
}

// int	main()
// {
// 	printf("%s", ft_strdup("je suis"));
// 	return 0;
// }