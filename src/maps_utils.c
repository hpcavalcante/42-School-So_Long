/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:14:04 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/15 17:43:22 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		count_size;
	int		i;

	count_size = ft_strlen(src);
	dest = (char *) malloc(sizeof(char) * (count_size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < count_size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	count_size;

	count_size = 0;
	while (src[count_size] && count_size < n)
	{
		dst[count_size] = src[count_size];
		count_size++;
	}
	while (count_size < n)
	{
		dst[count_size] = '\0';
		count_size++;
	}
	return (dst);
}

static int	counterwords(const char *s, char c)
{
	int	index;
	int	count;
	int	findword;

	findword = 0;
	count = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c && findword == 0)
		{
			findword = 1;
			count++;
		}
		else if (s[index] == c && findword == 1)
			findword = 0;
		index++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t len)
{
	char	*str;

	str = (char *) malloc (sizeof(char) * len + 1);
	if (str == 0)
		return (NULL);
	str = ft_strncpy(str, s, len);
	str[len] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		posc;
	int		n;
	char	**new_str;

	index = 0;
	posc = 0;
	n = 0;
	new_str = (char **) malloc(sizeof (char *) * ((counterwords(s, c) + 1)));
	if (new_str == 0)
		return (NULL);
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		posc = index;
		while (s[index] != '\0' && s[index] != c)
			index++;
		if (index > posc)
			new_str[n++] = ft_strndup(s + posc, index - posc);
	}
	new_str[n] = NULL;
	return (new_str);
}
