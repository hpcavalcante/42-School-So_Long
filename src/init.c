/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:27:46 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/03 21:14:49 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_var(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	game->map->count_p = 0;
	game->map->count_c = 0;
	game->map->count_e = 0;
	game->map->psc_x = 0;
	game->map->psc_y = 0;
	game->map->moves = 0;
	game->reset = 0;
}

void	init_struct(t_game *game)
{
	game->player = malloc(sizeof(t_imagedata) * 1);
	game->collect = malloc(sizeof(t_imagedata) * 1);
	game->exit = malloc(sizeof(t_imagedata) * 1);
	game->wall = malloc(sizeof(t_imagedata) * 1);
	game->empty = malloc(sizeof(t_imagedata) * 1);
}
