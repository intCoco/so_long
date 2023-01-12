/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:17:19 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/14 13:13:49 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define ULL unsigned long long
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"
# define DEC "0123456789"

int	ft_printf(const char *format, ...);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *str);
int	ft_putnbr_pf(int nb);

#endif
