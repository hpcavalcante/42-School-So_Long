/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:00:54 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/02 14:46:58 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->map->psc_x;
	y = game->map->psc_y;
	if (keycode == ESC)
		kill_window(game);
	if (keycode == W)
		y--;
	if (keycode == A)
		x--;
	if (keycode == S)
		y++;
	if (keycode == D)
		x++;
	if (check_colision(x, y, game))
	{
		colision(x, y, game);
		ft_printf("\e[1;1H\e[2JMoves: %d\n", game->map->moves);
	}
}

void	colision(int x, int y, t_game *game)
{
	game->map->map_matrix[game->map->psc_y][game->map->psc_x] = '0';
	game->map->psc_x = x;
	game->map->psc_y = y;
	game->map->moves++;
	map_render(game);
}

int	check_colision(int x, int y, t_game *game)
{
	if (game->map->map_matrix[y][x] == '1')
		return (0);
	if (game->map->map_matrix[y][x] == 'C')
		game->map->count_c--;
	if (game->map->map_matrix[y][x] == 'E')
	{
		if (game->map->count_c == 0)
		{
			ft_printf("You win!\n");
			kill_window(game);
		}
		ft_printf("You need to collect all before exit\n");
		return (0);
	}
	return (1);
}
