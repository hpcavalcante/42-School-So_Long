/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:39:45 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/04 03:40:47 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	dimensions(t_map *map)
{
	int	lines;
	int	col;

	lines = 0;
	col = 0;
	while (map->map_matrix[0][col] != '\0')
		col++;
	while (map->map_matrix[lines] != NULL)
		lines++;
	map->y = lines;
	map->x = col;
}

char	**read_map(int fd, t_game *game)
{
	game->map->buffer = get_next_line(fd);
	if (game->map->buffer == NULL)
		return (NULL);
	game->map->read_line = ft_strdup("");
	while (game->map->buffer != 0)
	{
		if (game->map->buffer[0] == '\n')
		{
			while (game->map->buffer)
			{
				free(game->map->buffer);
				game->map->buffer = get_next_line(fd);
			}	
			free(game->map->read_line);
			return (NULL);
		}
		game->map->read_line = ft_strjoin(game->map->read_line, \
		game->map->buffer);
		free(game->map->buffer);
		game->map->buffer = get_next_line(fd);
	}
	game->map->map_matrix = ft_split(game->map->read_line, '\n');
	free(game->map->read_line);
	return (game->map->map_matrix);
}

int	refresh(t_game *game)
{
	if (game->reset < 20)
		game->reset += 0.0001;
	else
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		game->reset = 0;
	}
	map_render(game);
	return (0);
}

void	run(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_tr(game);
		exit(1);
	}
	game->mlx_win = mlx_new_window(game->mlx, game->map->x * TILES,
			game->map->y * TILES, "Demon Cleaner");
	open_image(game);
	map_render(game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0L, kill_window, (void *)game);
	mlx_loop_hook(game->mlx, refresh, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2 || !check_extension(argv[1], ".ber"))
	{
		ft_printf(IVLEXT);
		exit(0);
	}
	game = malloc(sizeof(t_game));
	init_var(game);
	game->map->fd = open(argv[1], O_RDONLY);
	game->map->map_matrix = (read_map(game->map->fd, game));
	if (game->map->fd < 0 || game->map->map_matrix == NULL)
	{
		ft_printf("Error\nInvalid map!\n");
		free_main(game);
	}
	dimensions(game->map);
	if (!map_validation(game->map))
	{
		free_matrix(game);
		free_main(game);
	}
	init_struct(game);
	run(game);
}
