/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:57:44 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:46:14 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[end]))
		end--;
	new = ft_substr(s1, start, end - start + 1);
	return (new);
}

/*int	main(void)
{
	char	*s1 = "lorem \n ipsum \t dolor \n sit \t amet";
	printf("%s\n\n\n", s1);
	printf("%s\n", ft_strtrim(s1, " "));
	return (0);
}*/