/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 13:48:39 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/08/21 23:07:45 by lisannehouk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

mlx_image_t	*player_image(mlx_t *mlx, t_game *game)
{
	game->player.i_player = mlx_new_image(mlx, TILE_SIZE, TILE_SIZE);
	if (game->player.i_player == NULL)
		exit_this_way("No image, no magic\n,", 1);
	return (game->player.i_player);
}

mlx_image_t	*collect_image(mlx_t *mlx, t_game *game)
{
	game->collect.i_collect = mlx_new_image(mlx, TILE_SIZE, TILE_SIZE);
	mlx_draw_texture(game->collect.i_collect, \
		game->collect.tex_collect[0], 0, 0);
	if (game->collect.i_collect == NULL)
		exit_this_way("No image, no magic\n", 1);
	return (game->collect.i_collect);
}

mlx_image_t	*exit_image(mlx_t *mlx, t_game *game)
{
	game->exit.i_exit = mlx_new_image(mlx, TILE_SIZE, TILE_SIZE);
	if (game->exit.i_exit == NULL)
		exit_this_way("No image, no magic\n", 1);
	return (game->exit.i_exit);
}

mlx_image_t	*villain_image(mlx_t *mlx, t_game *game)
{
	game->villain.i_villain = mlx_new_image(mlx, TILE_SIZE, TILE_SIZE);
	if (game->villain.i_villain == NULL)
		exit_this_way("No image, no magic\n", 1);
	mlx_draw_texture(game->villain.i_villain, \
		game->villain.tex_villain[0], 0, 0);
	return (game->villain.i_villain);
}
