/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butatar <butatar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:36:18 by butatar           #+#    #+#             */
/*   Updated: 2023/07/19 15:36:24 by butatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (!str)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		len++;
	}
	return (len);
}

int	ft_putnbr(long double nbr, int base, int is_upper)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		len++;
	}
	if (nbr >= base)
		len += ft_putnbr(((unsigned long)nbr / base), base, is_upper);
	if (is_upper == 1)
		write(1, &UPPER_BASE[(unsigned long)nbr % base], 1);
	else
		write(1, &LOWER_BASE[(unsigned long)nbr % base], 1);
	return (len);
}

int	ft_putptr(long double nbr, int base, int is_upper)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_putnbr(nbr, base, is_upper);
	return (len);
}
