/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:02:50 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/03 21:11:20 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_main(t_game *game)
{
	free(game->map);
	free(game);
	exit (0);
}

void	free_matrix(t_game *game)
{
	int	x;

	x = 0;
	while (game->map->map_matrix[x])
	{
		free(game->map->map_matrix[x]);
		x++;
	}
	free(game->map->map_matrix);
}

void	destroy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player->image);
	mlx_destroy_image(game->mlx, game->collect->image);
	mlx_destroy_image(game->mlx, game->exit->image);
	mlx_destroy_image(game->mlx, game->wall->image);
	mlx_destroy_image(game->mlx, game->empty->image);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
}

void	free_tr(t_game *game)
{
	free(game->player);
	free(game->collect);
	free(game->exit);
	free(game->wall);
	free(game->empty);
	free_matrix(game);
	free(game->map);
	free(game->mlx);
	free(game);
}

int	kill_window(t_game *game)
{
	destroy(game);
	free_tr(game);
	exit (0);
}
