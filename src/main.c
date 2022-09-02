/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:39:45 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/02 13:35:10 by hepiment         ###   ########.fr       */
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

char	**read_map(int fd)
{
	t_map	map;

	if (fd < 0)
		return (NULL);
	map.read_line = ft_strdup("");
	map.buffer = get_next_line(fd);
	while (map.buffer)
	{
		if (map.buffer[0] == '\n')
		{
			while(map.buffer)
			{
				free(map.buffer);
				map.buffer = get_next_line(fd);
			}	
			free(map.read_line);
			return (NULL);
		}
		map.read_line = ft_strjoin(map.read_line, map.buffer);
		free(map.buffer);
		map.buffer = get_next_line(fd);
	}
	map.map_matrix = ft_split(map.read_line, '\n');
	free(map.read_line);
	return (map.map_matrix);
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
	game->map->map_matrix = (read_map(game->map->fd));
	if (game->map->fd < 0 || game->map->map_matrix == NULL)
	{
		ft_printf("Invalid map!\n");
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
