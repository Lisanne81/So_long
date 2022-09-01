/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 15:32:09 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/08/21 20:22:48 by lisannehouk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

void	draw_game(mlx_image_t *image, t_game *game)
{
	game->player.i_player = player_image(game->mlx, game);
	game->collect.i_collect = collect_image(game->mlx, game);
	game->villain.i_villain = villain_image(game->mlx, game);
	game->exit.i_exit = exit_image(game->mlx, game);
	map_to_window(image, game);
	components_to_window(image, game);
	game->steps = mlx_put_string(game->mlx, "MOVES: ", game->coll / 2, 10);
}

mlx_image_t	*background(mlx_t *mlx, t_game *game)
{
	mlx_image_t	*background;

	background = mlx_new_image(mlx, game->coll * TILE_SIZE, \
		game->rows * TILE_SIZE);
	if (background == NULL)
		exit_this_way("Snap! did not make an image!", 1);
	return (background);
}

void	setup_png(t_game *game)
{
	player_png(game);
	villain_png(game);
	collect_png(game);
	basic_png(game);
	check_png(game);
}

void	create_window(t_game *game)
{
	game->mlx = mlx_init(TILE_SIZE * game->coll, \
		TILE_SIZE * game->rows, "SO_LONG...", true);
	if (!game->mlx)
		exit_this_way("\33[35;106moh no... mlx\33[m\n", 1);
	setup_png(game);
	game->background = background(game->mlx, game);
	mlx_image_to_window(game->mlx, game->background, 0, 0);
	draw_game(game->background, game);
	return ;
}
