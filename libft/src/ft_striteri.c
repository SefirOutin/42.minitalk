/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:44:19 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:45:40 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (*s)
	{
		(*f)(i, s);
		i++;
		s++;
	}
}

// void	iter(unsigned int i, char * s) 
// {
// 	*s += i;
// }

// int		main()
// {
// 	char s[] = "0000000000";
// 	ft_striteri(s, iter);
// 	printf("%s", s);
// }