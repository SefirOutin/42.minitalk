/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:17:11 by soutin            #+#    #+#             */
/*   Updated: 2023/06/15 15:00:12 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	pf_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	pf_putnbr(int nb, size_t *len)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		*len += pf_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		pf_putnbr(n / 10, len);
	}
	*len += pf_putchar(n % 10 + 48);
}

size_t	pf_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

static void	pf_putnbr_base(unsigned long nb, char *base, size_t *len)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nb >= base_len)
	{
		pf_putnbr_base(nb / base_len, base, len);
	}
	*len += pf_putchar(base[nb % base_len]);
}

void	pf_convert_base(unsigned long nb, char index, size_t *len)
{
	char	*base[3];

	base[0] = "0123456789";
	base[1] = "0123456789abcdef";
	base[2] = "0123456789ABCDEF";
	if (index == 'u')
		pf_putnbr_base(nb, base[0], len);
	else if (index == 'x')
		pf_putnbr_base(nb, base[1], len);
	else if (index == 'X')
		pf_putnbr_base(nb, base[2], len);
	else if (index == 'p')
	{
		if (!nb)
		{
			*len += write(1, "(nil)", 5);
			return ;
		}
		*len += write(1, "0x", 2);
		pf_putnbr_base(nb, base[1], len);
	}
}
