/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:29:10 by moboulan          #+#    #+#             */
/*   Updated: 2024/12/26 16:06:01 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	handle_format(const char *s, va_list args)
{
	int	size;

	size = 0;
	if (*s == '%')
		size += ft_putchar('%');
	else if (*s == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (*s == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (*s == 'p')
	{
		size += ft_putstr("0x");
		size += ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef");
	}
	else if (*s == 'd' || *s == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (*s == 'u')
		size += ft_putnbr(va_arg(args, unsigned int));
	else if (*s == 'x')
		size += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*s == 'X')
		size += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else
		size += ft_putchar(*s);
	return (size);
}

int	ft_printf(const char *s, ...)
{
	int		size;
	va_list	args;

	if (write(1, "", 0))
		return (-1);
	va_start(args, s);
	size = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1))
			size += handle_format(++s, args);
		else if (*s != '%')
			size += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (size);
}
