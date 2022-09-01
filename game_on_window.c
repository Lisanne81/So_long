/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_on_window.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 15:43:51 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/08/17 23:26:40 by lisannehouk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

void	put_player(mlx_image_t *image, t_game *game, int x, int y)
{
	mlx_draw_texture(image, game->map->floor.tex_floor, \
		x * TILE_SIZE, y * TILE_SIZE);
	player_on_window(game->mlx, game->player.i_player, game);
}

void	put_villain(mlx_image_t *image, t_game *game, t_map *curr)
{
	mlx_draw_texture(image, game->map->floor.tex_floor, \
		curr->x_pos * TILE_SIZE, curr->y_pos * TILE_SIZE);
	villain_on_window(game->mlx, game->villain.i_villain, curr);
}

void	components_to_window(mlx_image_t *image, t_game *game)
{
	t_map	*curr;

	curr = game->map;
	if (game->map == NULL)
		exit_this_way("No map to draw\n", 1);
	while (curr != NULL)
	{
		if (curr->component == 'P')
			put_player(image, game, curr->x_pos, curr->y_pos);
		else if (curr->component == 'C')
		{
			mlx_draw_texture(image, game->map->floor.tex_floor,
				curr->x_pos * TILE_SIZE, curr->y_pos * TILE_SIZE);
			collect_on_window(game->mlx, game->collect.i_collect, curr);
		}
		else if (curr->component == 'E')
			exit_on_window(game->mlx, game->exit.i_exit, game);
		else if (curr->component == 'V')
		{
			put_villain(image, game, curr);
			game->villain.villain_on_off = 1;
		}
		curr = curr->next;
	}
}

void	map_to_window(mlx_image_t *image, t_game *game)
{
	t_map	*curr;

	curr = game->map;
	if (game->map == NULL)
		exit_this_way("No map to draw\n", 1);
	while (curr != NULL)
	{
		if (curr->component == '1')
			mlx_draw_texture(image, game->map->wall.tex_wall, \
				curr->x_pos * TILE_SIZE, curr->y_pos * TILE_SIZE);
		if (curr->component == '0')
			mlx_draw_texture(image, game->map->floor.tex_floor, \
				curr->x_pos * TILE_SIZE, curr->y_pos * TILE_SIZE);
		curr = curr->next;
	}
}
