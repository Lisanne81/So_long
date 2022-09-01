/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:30:40 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/09/01 17:28:37 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 32
# define WIDTH 256
# define HEIGHT 256

# define R124 "\e[38;5;196m"
# define B17 "\e[38;5;202m"
# define B18 "\e[38;5;209m"
# define B19 "\e[38;5;214m"
# define B20 "\e[38;5;216m"
# define B21 "\e[38;5;21m"
# define G22 "\e[38;5;22m"
# define B23 "\e[38;5;23m"
# define Y185 "\e[38;5;185m"
# define G40 "\e[38;5;40m"
# define G41 "\e[38;5;41m"
# define G42 "\e[38;5;42m"
# define G43 "\e[38;5;43m"
# define G46 "\e[38;5;46m"
# define G47 "\e[38;5;47m"
# define G48 "\e[38;5;48m"
# define G49 "\e[38;5;49m"
# define G50 "\e[38;5;50m"
# define RESET "\e[0m"

# include "./get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_floor
{
	int				x;
	int				y;
	mlx_texture_t	*tex_floor;
}	t_floor;

typedef struct s_wall
{
	int				x;
	int				y;
	mlx_texture_t	*tex_wall;
}	t_wall;

typedef struct s_exit
{
	int				x;
	int				y;
	int				exit_count;
	mlx_texture_t	*tex_exit[2];
	mlx_image_t		*i_exit;		
}	t_exit;

typedef struct s_collect
{
	int				x;
	int				y;
	int				c_count;
	int				collect_on_off;	
	mlx_texture_t	*tex_collect[6];
	mlx_image_t		*i_collect;
}	t_collect;

typedef struct s_map
{
	int				x_pos;
	int				y_pos;
	int				player;
	int				exit;
	char			component;
	int				inst_index;
	t_floor			floor;
	t_wall			wall;
	t_exit			t_exit;
	struct s_map	*next;
}	t_map;

typedef enum e_map_component
{
	PLAYER = 'P',
	VILLAIN = 'V',
	COLLECT = 'C',
	FLOOR = '0',
	WALL = '1',
	EXIT = 'E',
}	t_map_component;

typedef struct s_player
{
	int				x;
	int				y;
	int				player_check;
	int				player_direction;
	mlx_texture_t	*tex_player_right[6];
	mlx_texture_t	*tex_player_left[6];
	mlx_image_t		*i_player;
}	t_player;

typedef struct s_villain
{
	int				x;
	int				y;
	int				villain_moves;
	int				villain_on_off;
	mlx_texture_t	*tex_villain[6];
	mlx_image_t		*i_villain;
}	t_villain;

typedef struct s_game
{
	int			rows;
	int			coll;
	int			moves;
	double		time_frame;
	int			current_frame;
	int			counter_on_off;
	int			keyhook_on_of;
	mlx_t		*mlx;
	mlx_image_t	*image_counter;
	mlx_image_t	*steps;
	mlx_image_t	*background;
	mlx_image_t	*lose;
	mlx_image_t	*win;
	mlx_image_t	*earth;
	mlx_image_t	*escape;
	t_map		*map;
	t_player	player;
	t_villain	villain;
	t_collect	collect;
	t_exit		exit;
}	t_game;

/*----------check input - create map-----------------------*/
t_map		*insert_at_end(char component, int x, int y);
void		init_game(t_game *game);
void		add_node(t_map **map_line, t_map *new);
void		free_map(t_map *map);
void		valid_extention(char *file);
void		parse_map(t_game *game, char *file_map);
void		check_shape_map(char *element_in_row, int coll_len);
void		create_map(t_map **map, char *map_line, int y);
void		check_map_input(t_game *game);
void		check_component(t_map *map);
int			check_component_vitals(t_game *game);
void		update_player(t_game *game, int x, int y);
void		update_villain(t_game *game, int x, int y);
void		update_collect(t_game *game, int x, int y);
void		update_exit(t_game *game, int x, int y);

/*----------load png for game-----------------------*/
void		setup_png(t_game *game);
void		player_png(t_game *game);
void		villain_png(t_game *game);
void		collect_png(t_game *game);
void		basic_png(t_game *game);
void		check_png(t_game *game);

/*----------draw and play game-----------------------*/
void		draw_game(mlx_image_t *image, t_game *game);
void		map_to_window(mlx_image_t *image, t_game *game);
void		components_to_window(mlx_image_t *image, t_game *game);
void		create_window(t_game *game);
void		player_on_window(mlx_t *mlx, mlx_image_t *image, t_game *game);
void		collect_on_window(mlx_t *mlx, mlx_image_t *image, t_map *current);
void		exit_on_window(mlx_t *mlx, mlx_image_t *image, t_game *game);
void		villain_on_window(mlx_t *mlx, mlx_image_t *image, t_map *current);
void		my_key_hook(mlx_key_data_t keyaction, void *param);
void		player_left(t_game *game);
void		player_right(t_game *game);
void		player_up(t_game *game);
void		player_down(t_game *game);
void		update_counter(t_game *game);
void		animation(void *param);
bool		player_colide(t_game *game, int x, int y, int colide);

/*----------check input - create map-----------------------*/
void		clean_field(t_game *game);
void		clean_collect(t_game *game);
void		exit_on_click(void *param);
int			ft_print_banner(int num);
int			exit_this_way(char *message, int id);

/*----------create images -----------------------*/
mlx_image_t	*background(mlx_t *mlx, t_game *game);
mlx_image_t	*player_image(mlx_t *mlx, t_game *game);
mlx_image_t	*collect_image(mlx_t *mlx, t_game *game);
mlx_image_t	*villain_image(mlx_t *mlx, t_game *game);
mlx_image_t	*exit_image(mlx_t *mlx, t_game *game);
mlx_image_t	*game_over_image(mlx_t *mlx, t_game *game);

#endif