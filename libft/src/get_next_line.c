/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:07:50 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:46:28 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*ft_join(char *line, char *buffer)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc((ft_strlen(line) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!new || !buffer)
		return (NULL);
	if (line)
	{
		while (line[i])
		{
			new[i] = line[i];
			i++;
		}
	}
	while (*buffer)
	{
		new[i++] = *buffer;
		buffer++;
	}
	new[i] = '\0';
	if (line)
		free(line);
	return (new);
}

static int	in_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	trim_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	line[i] = '\0';
}

static void	trim_buffer(char *buffer, long nb)
{
	int		i;
	int		l;
	char	tmp;

	l = 0;
	i = 0;
	(void)nb;
	if (!buffer)
		return ;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	while (buffer[++i] && (nb || in_line(buffer)))
	{
		tmp = buffer[i];
		buffer[l] = tmp;
		l++;
	}
	buffer[l] = '\0';
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	long		nb_bytes;

	nb_bytes = 1;
	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_join(NULL, buffer);
	while (!in_line(line))
	{
			nb_bytes = read(fd, buffer, BUFFER_SIZE);
			buffer[nb_bytes] = '\0';
		if (!nb_bytes)
			break ;
		if (nb_bytes < 0)
			return (free(line), NULL);
		line = ft_join(line, buffer);
		if (!line)
			return (NULL);
	}
	trim_line(line);
	if (!line[0])
		return (free(line), NULL);
	trim_buffer(buffer, nb_bytes);
	return (line);
}
