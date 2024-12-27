/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:17:52 by moboulan          #+#    #+#             */
/*   Updated: 2024/12/26 18:25:39 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <signal.h>

int		ft_isspace(char c);
int		ft_isallspace(char *str);
int		ft_isint(char *str);
long	ft_atol(char *str);
int		ft_strlen(char *str);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(unsigned long nbr);
int		ft_putnbr_base(unsigned long nbr, char *base);
int		ft_printf(const char *format, ...);

#endif