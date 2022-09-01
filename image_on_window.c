/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_on_window.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 13:48:39 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/08/21 19:38:07 by lisannehouk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

void	player_on_window(mlx_t *mlx, mlx_image_t *image, t_game *game)
{
	mlx_draw_texture(image, game->player.tex_player_left[0], 0, 0);
	mlx_image_to_window(mlx, image, game->player.x * TILE_SIZE, \
		game->player.y * TILE_SIZE);
	return ;
}

void	collect_on_window(mlx_t *mlx, mlx_image_t *image, t_map *curr)
{
	curr->inst_index = mlx_image_to_window(mlx, image, curr->x_pos * TILE_SIZE, \
		curr->y_pos * TILE_SIZE);
	return ;
}

void	exit_on_window(mlx_t *mlx, mlx_image_t *image, t_game *game)
{
	mlx_draw_texture(image, game->exit.tex_exit[0], 0, 0);
	mlx_image_to_window(mlx, image, game->exit.x * TILE_SIZE, \
		game->exit.y * TILE_SIZE);
	return ;
}

void	villain_on_window(mlx_t *mlx, mlx_image_t *image, t_map *curr)
{
	curr->inst_index = mlx_image_to_window(mlx, image, curr->x_pos * TILE_SIZE, \
		curr->y_pos * TILE_SIZE);
	return ;
}
