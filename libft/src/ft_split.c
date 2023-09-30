/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:07:39 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:45:29 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	is_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	nb_str(char *s, char c)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	if (s[i])
	{
		if (!is_sep(s[i], c))
		{
			i++;
			nb++;
		}
		while (s[i + 1])
		{
			if (is_sep(s[i], c) && !is_sep(s[i + 1], c))
				nb++;
			i++;
		}
	}
	return (nb);
}

static int	len(char *s, unsigned int i, char c)
{
	int	len;

	len = 0;
	while (!is_sep(s[i], c) && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static void	free_tab(char **tab, int until)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < until)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char			**strs;
	unsigned int	start;
	int				nb_strs;
	int				i;

	i = 0;
	if (!s)
		return (NULL);
	nb_strs = nb_str((char *)s, c);
	start = 0;
	strs = (char **)malloc(sizeof(char *) * (nb_strs + 1));
	if (!strs)
		return (NULL);
	while (nb_strs--)
	{
		while (is_sep(s[start], c))
			start++;
		strs[i] = ft_substr(s, start, len((char *)s, start, c));
		start += len((char *)s, start, c);
		if (!strs[i])
			free_tab(strs, i);
		i++;
	}
	strs[i] = 0;
	return (strs);
}

// int	main(void)
// {
// 	char	str[] = "lorem ipsum dolor sit amet,
//			consectetur adipiscing elit. Sed non risus. Suspendisse
//			lectus tortor,
//			dignissim sit amet, adipiscing nec, ultricies sed,
//			dolor. Cras elementum ultricies diam. Maecenas ligula massa,
//			varius a, semper congue, euismod non, mi.";
// 	char	**strs = ft_split(str, 'z');
// 	int	i = 0;
// 	while (i < nb_str(str, 'z'))
// 	{
// 		printf("%s\n", strs[i]);
// 		i++;
// 	}
// }
