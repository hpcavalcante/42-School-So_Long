/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:53:10 by hepiment          #+#    #+#             */
/*   Updated: 2022/08/17 14:05:20 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_extension(char *path, char *extension)
{
	int	len_path;
	int	len_ext;

	len_path = ft_strlen(path);
	len_ext = ft_strlen(extension);
	if (len_path < 5)
		return (0);
	while (len_ext)
	{
		if (extension[len_ext] == path[len_path])
		{
			len_ext--;
			len_path--;
		}
		else
			return (0);
	}
	return (1);
}

int	map_is_rectangular(t_map *map)
{
	int	i;

	i = -1;
	while (map->map_matrix[++i])
	{
		if (ft_strlen(map->map_matrix[i]) != map->x)
		{
			ft_printf(RERROR);
			return (0);
		}
	}
	return (1);
}
