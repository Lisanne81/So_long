/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 08:41:05 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/08/26 10:14:16 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

void	collect_gameboy(t_game *game, t_map *curr)
{
	if (game->collect.collect_on_off == 0)
	{
		game->collect.i_collect->instances[curr->inst_index].z = -1;
		game->collect.c_count--;
	}
	if (game->collect.c_count == 0)
	{
		mlx_draw_texture(game->exit.i_exit, game->exit.tex_exit[1], 0, 0);
		game->earth = mlx_put_string(game->mlx, "Go to Earth!", \
			TILE_SIZE, TILE_SIZE);
	}
}

int	check_wall(t_game *game, t_map *curr, int colide)
{
	if (curr->component == '1' || (curr->component == 'E' && \
		game->collect.c_count != 0))
	{
		colide = 1;
	}
	return (colide);
}

void	game_over(t_game *game, char id)
{
	if (id == 'V')
	{
		game->player.i_player->instances->z = -1;
		game->lose = mlx_put_string(game->mlx, "YOU LOSE!", game->coll / 2, 60);
		game->escape = mlx_put_string(game->mlx, "Press ESC", \
			TILE_SIZE, TILE_SIZE * 3);
		game->counter_on_off = 0;
		game->keyhook_on_of = 1;
		game->collect.collect_on_off = 1;
		return ;
	}
	else if (id == 'E')
	{
		game->player.i_player->instances->z = -1;
		game->win = mlx_put_string(game->mlx, "GREAT JOB!", \
			game->coll / 2, 80);
			game->escape = mlx_put_string(game->mlx, \
				"Press ESC", TILE_SIZE, TILE_SIZE * 3);
		game->keyhook_on_of = 1;
		game->counter_on_off = 0;
		return ;
	}
	game->counter_on_off = 0;
}

bool	player_colide(t_game *game, int x, int y, int colide)
{
	t_map	*curr;

	curr = game->map;
	while (curr != NULL)
	{
		if (curr->x_pos == x && curr->y_pos == y)
		{
			if (curr->component == '1' || (curr->component == 'E' && \
				game->collect.c_count != 0))
			{
				colide = 1;
				break ;
			}
			else if (curr->component == 'C' && game->collect.c_count != 0 \
			&& !(game->collect.i_collect->instances[curr->inst_index].z == -1))
				collect_gameboy(game, curr);
			else if (curr->component == 'V')
				game_over(game, 'V');
			else if (curr->component == 'E' && game->collect.c_count == 0)
				game_over(game, 'E');
		}
		curr = curr->next;
	}
	return (colide);
}

void	my_key_hook(mlx_key_data_t keyaction, void *param)
{
	t_game	*game;
	int		index;

	game = param;
	index = 0;
	if (keyaction.action == MLX_PRESS || keyaction.action == MLX_REPEAT)
	{
		if (keyaction.key == MLX_KEY_ESCAPE || keyaction.key == MLX_KEY_Q)
			mlx_close_window(game->mlx);
		if (game->keyhook_on_of == 1)
			return ;
		if (keyaction.key == MLX_KEY_W || keyaction.key == MLX_KEY_UP)
			player_up(game);
		else if (keyaction.key == MLX_KEY_S || keyaction.key == MLX_KEY_DOWN)
			player_down(game);
		else if (keyaction.key == MLX_KEY_A || keyaction.key == MLX_KEY_LEFT)
			player_left(game);
		else if (keyaction.key == MLX_KEY_D || keyaction.key == MLX_KEY_RIGHT)
			player_right(game);
	}
	if (game->counter_on_off == 1)
		update_counter(game);
}
