/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:10:10 by hepiment          #+#    #+#             */
/*   Updated: 2022/08/16 16:31:18 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	count_size;

	count_size = 0;
	while (src[count_size] && count_size < n)
	{
		dst[count_size] = src [count_size];
		count_size++;
	}
	while (count_size < n)
	{
		dst[count_size] = '\0';
		count_size++;
	}
	return (dst);
}

static int	lenght_int(int nb)
{
	int	lenght;

	if (nb > 0)
		lenght = 0;
	else
		lenght = 1;
	while (nb != 0)
	{
		lenght++;
		nb = nb / 10;
	}
	return (lenght);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = lenght_int(n);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
		return (ft_strncpy(str, "-2147483648\0", 12));
	if (n < 0)
	{
		n = n * (-1);
		str[0] = '-';
	}
	str[len] = '\0';
	while (n > 0)
	{
		len -= 1;
		str[len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
