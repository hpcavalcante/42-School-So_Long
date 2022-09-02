/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:24:11 by hepiment          #+#    #+#             */
/*   Updated: 2022/08/16 18:46:51 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putnbr(long int n);
int		ft_putstr(char *s);
int		to_hex(unsigned long long nb, char flag);
int		ft_ptr(unsigned long adress);
#endif