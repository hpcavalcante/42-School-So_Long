/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:38:55 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/03 21:10:03 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	walls(t_map *map)
{
	size_t	i;

	i = -1;
	while (map->map_matrix[++i])
	{
		if (map->map_matrix[i][0] != '1'
			|| map->map_matrix[i][map->x - 1] != '1')
		{
			ft_printf(WERROR);
			return (0);
		}
	}
	i = -1;
	while (++i < map->x)
	{
		if (map->map_matrix[0][i] != '1'
			|| map->map_matrix[map->y - 1][i] != '1')
		{
			ft_printf(WERROR);
			return (0);
		}
	}
	return (1);
}

int	count_char_print(t_map *map)

{
	if (map->count_p != 1)
	{
		ft_printf(PERROR);
		return (0);
	}	
	if (map->count_c == 0)
	{
		ft_printf(CERROR);
		return (0);
	}	
	if (map->count_e == 0)
	{
		ft_printf(EERROR);
		return (0);
	}
	return (1);
}

void	count_char(t_map *map)
{
	int		i;
	int		j;

	map->psc_y = 0;
	map->psc_x = 0;
	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map_matrix[i][j] == 'P')
			{
				map->count_p++;
				map->psc_y = i;
				map->psc_x = j;
			}
			if (map->map_matrix[i][j] == 'C')
				map->count_c++;
			if (map->map_matrix[i][j] == 'E')
				map->count_e++;
			j++;
		}
		i++;
	}
}

int	invalid_character(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map_matrix[i][j] != 'P' && map->map_matrix[i][j] != 'C'
				&& map->map_matrix[i][j] != 'E' && map->map_matrix[i][j] != '0'
				&& map->map_matrix[i][j] != '1' && map->map_matrix[i][j] != 'H')
			{
				ft_printf(IVLCHAR);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	map_validation(t_map *map)
{
	if (!map_is_rectangular(map))
		return (0);
	if (!walls(map))
		return (0);
	count_char(map);
	if (!count_char_print(map))
		return (0);
	if (!invalid_character(map))
		return (0);
	return (1);
}
