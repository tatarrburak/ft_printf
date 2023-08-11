/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butatar <butatar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:47:09 by butatar           #+#    #+#             */
/*   Updated: 2023/07/19 14:47:35 by butatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char c, va_list va)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchr(va_arg(va, int));
	else if (c == 's')
		len += ft_putstr(va_arg(va, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(va, int), 10, 0);
	else if (c == 'u')
		len += ft_putnbr(va_arg(va, unsigned int), 10, 0);
	else if (c == 'x')
		len += ft_putnbr(va_arg(va, unsigned int), 16, 0);
	else if (c == 'X')
		len += ft_putnbr(va_arg(va, unsigned int), 16, 1);
	else if (c == 'p')
		len += ft_putptr(va_arg(va, unsigned long), 16, 0);
	else
		len += ft_putchr(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		len;

	va_start(va, str);
	len = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			len += ft_control(*(str + 1), va);
			str++;
		}
		else if (*str != '%')
			len += ft_putchr(*str);
		str++;
	}
	va_end(va);
	return (len);
}
