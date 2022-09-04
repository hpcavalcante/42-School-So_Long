/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:34:14 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/03 21:13:23 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_map
{
	int		fd;
	int		x;
	int		y;
	int		count_p;
	int		count_c;
	int		count_e;
	char	*buffer;
	char	*read_line;
	char	**map_matrix;
	int		psc_x;
	int		psc_y;
	int		moves;
}	t_map;

typedef struct s_imagedata
{
	void	*image;
	int		i;
	int		j;
}	t_imagedata;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	t_imagedata	*player;
	t_imagedata	*collect;
	t_imagedata	*exit;
	t_imagedata	*wall;
	t_imagedata	*empty;
	float		reset;
}	t_game;

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	**read_map(int fd);
int		map_is_rectangular(t_map *map);
int		check_extension(char *path, char *extension);
int		walls(t_map *map);
void	count_char(t_map *map);
int		count_char_print(t_map *map);
int		map_validation(t_map *map);
void	ft_bzero(void *str, size_t n);
int		invalid_character(t_map *map);
void	run(t_game *game);
void	map_render(t_game *game);
void	render_image(t_imagedata *image, t_game *game, int t, int j);
void	interactive_render(t_game *game);
int		key_hook(int keycode, t_game *game);
int		kill_window(t_game *game);
int		check_colision(int x, int y, t_game *game);
void	free_matrix(t_game *game);
char	*ft_itoa(int n);
void	player_render(t_game *game);
void	open_image(t_game *game);
void	colision(int x, int y, t_game *game);
void	init_var(t_game *game);
void	init_struct(t_game *game);
void	free_main(t_game *game);
void	free_tr(t_game *game);

# define IVLCHAR "Error!\nInvalid character on map.\n"
# define IVLEXT "Error\nMap has to be a .ber file\n"
# define PERROR "Error\nMap must have one Player.\n"
# define CERROR "Error\nMap must have at least one collectable.\n"
# define EERROR "Error\nMap must have at least one exit.\n"
# define WERROR "Error\nInvalid map! Map has to be surrounded by walls.\n"
# define RERROR "Error\nInvalid map! Map has to be rectangular.\n"

# define TILES 65

# define W 0x77
# define S 0x73
# define A 0x61
# define D 0x64
# define ESC 0xff1b

# define PLAYER "./img/player_right.xpm"
# define COLLECT "./img/collect.xpm"
# define EXIT "./img/exit_open.xpm"
# define EMPTY "./img/empty.xpm"
# define WALL "./img/wall.xpm"

#endif