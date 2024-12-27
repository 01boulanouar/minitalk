/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:02:16 by moboulan          #+#    #+#             */
/*   Updated: 2024/12/26 16:37:45 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

long	ft_atol(char *str)
{
	unsigned long		num;
	int					signe;

	num = 0;
	signe = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			signe *= -1;
	}
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((long)num * signe);
}

int	ft_isint(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (i < ft_strlen(str) || ft_isallspace(str)
		|| (ft_strlen(str) == 1 && (str[0] == '-' || str[0] == '+' ))
		|| ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}

int	ft_putnbr(unsigned long nbr)
{
	int	size;

	size = 0;
	if ((long)nbr < 0)
	{
		size += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		size += ft_putnbr(nbr / 10);
	size += ft_putchar((nbr % 10) + '0');
	return (size);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int				size;
	unsigned long	base_len;

	base_len = ft_strlen(base);
	size = 0;
	if (nbr >= base_len)
		size += ft_putnbr_base(nbr / base_len, base);
	size += ft_putchar(base[nbr % base_len]);
	return (size);
}
