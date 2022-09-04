/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:11:04 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/04 04:19:04 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_render(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map->x)
	{
		j = 0;
		while (j < game->map->y)
		{
			if (game->map->map_matrix[j][i] == '1')
				render_image(game->wall, game, i, j);
			if (game->map->map_matrix[j][i] == '0')
				render_image(game->empty, game, i, j);
			if (game->map->map_matrix[j][i] == 'E')
				render_image(game->exit, game, i, j);
			if (game->map->map_matrix[j][i] == 'C')
				render_image(game->collect, game, i, j);
			j++;
		}
		render_image(game->player, game, game->map->psc_x, game->map->psc_y);
		i++;
	}
}

void	render_image(t_imagedata *image, t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, image->image, \
	i * TILES, j * TILES);
	mov_count(game);
}

void	open_image(t_game *game)
{
	game->player->image = mlx_xpm_file_to_image(game->mlx, PLAYER, \
	&game->player->i, &game->player->j);
	game->collect->image = mlx_xpm_file_to_image(game->mlx, COLLECT, \
	&game->collect->i, &game->collect->j);
	game->exit->image = mlx_xpm_file_to_image(game->mlx, EXIT, \
	&game->exit->i, &game->exit->j);
	game->empty->image = mlx_xpm_file_to_image(game->mlx, EMPTY, \
	&game->empty->i, &game->empty->j);
	game->wall->image = mlx_xpm_file_to_image(game->mlx, WALL, \
	&game->wall->i, &game->wall->j);
}
