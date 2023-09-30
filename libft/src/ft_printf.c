/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:01:53 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 14:45:02 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	check_format(const char *str)
{
	while (*str)
	{
		if (ft_strchr(str, '%'))
		{
			str = ft_strchr(str, '%') + 1;
			if (!ft_strchr("%cspdiuxX", *str))
				return (0);
		}
		str++;
	}
	return (1);
}

static void	oula(const char *str, va_list arg, size_t *len)
{
	while (*str)
	{
		if (*str == 37)
		{
			if (*++str == 'c')
				*len += pf_putchar(va_arg(arg, int));
			else if (*str == 's')
				*len += pf_putstr(va_arg(arg, char *));
			else if (*str == 'p')
				pf_convert_base(va_arg(arg, unsigned long), 'p', len);
			else if (*str == 'd' || *str == 'i')
				pf_putnbr(va_arg(arg, int), len);
			else if (*str == 'u')
				pf_convert_base(va_arg(arg, unsigned int), 'u', len);
			else if (*str == 'x')
				pf_convert_base(va_arg(arg, unsigned int), 'x', len);
			else if (*str == 'X')
				pf_convert_base(va_arg(arg, unsigned int), 'X', len);
			else if (*str == '%')
				*len += pf_putchar(*str);
		}
		else
			*len += pf_putchar(*str);
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	len;

	len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	if (check_format(str))
		oula(str, args, &len);
	va_end(args);
	return (len);
}
