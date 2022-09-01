/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_png.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 07:10:50 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/09/01 17:28:23 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

void	check_png(t_game *game)
{
	int	index;

	index = 0;
	while (index < 6)
	{
		if (game->player.tex_player_left[index] == NULL)
			exit_this_way("No player PNG\n", 1);
		if (game->player.tex_player_right[index] == NULL)
			exit_this_way("No player PNG\n", 1);
		if (game->collect.tex_collect[index] == NULL)
			exit_this_way("No collect PNG\n", 1);
		if (game->villain.tex_villain[index] == NULL)
			exit_this_way("No collect villain\n", 1);
		index++;
	}
	if (game->map->floor.tex_floor == NULL)
		exit_this_way("No floor PNG\n", 1);
	if (game->map->wall.tex_wall == NULL)
		exit_this_way("No wall PNG\n", 1);
	if (game->exit.tex_exit[0] == NULL)
		exit_this_way("No exit PNG\n", 1);
	if (game->exit.tex_exit[1] == NULL)
		exit_this_way("No exit PNG\n", 1);
}

void	player_png(t_game *game)
{
	game->player.tex_player_left[0] = mlx_load_png("./image/keen_left0.png");
	game->player.tex_player_left[1] = mlx_load_png("./image/keen_left1.png");
	game->player.tex_player_left[2] = mlx_load_png("./image/keen_left2.png");
	game->player.tex_player_left[3] = mlx_load_png("./image/keen_left3.png");
	game->player.tex_player_left[4] = mlx_load_png("./image/keen_left4.png");
	game->player.tex_player_left[5] = mlx_load_png("./image/keen_left5.png");
	game->player.tex_player_right[0] = mlx_load_png("./image/keen_right0.png");
	game->player.tex_player_right[1] = mlx_load_png("./image/keen_right1.png");
	game->player.tex_player_right[2] = mlx_load_png("./image/keen_right2.png");
	game->player.tex_player_right[3] = mlx_load_png("./image/keen_right3.png");
	game->player.tex_player_right[4] = mlx_load_png("./image/keen_right4.png");
	game->player.tex_player_right[5] = mlx_load_png("./image/keen_right5.png");
}

void	villain_png(t_game *game)
{
	game->villain.tex_villain[0] = mlx_load_png("./image/enemy0.png");
	game->villain.tex_villain[1] = mlx_load_png("./image/enemy1.png");
	game->villain.tex_villain[2] = mlx_load_png("./image/enemy2.png");
	game->villain.tex_villain[3] = mlx_load_png("./image/enemy3.png");
	game->villain.tex_villain[4] = mlx_load_png("./image/enemy4.png");
	game->villain.tex_villain[5] = mlx_load_png("./image/enemy5.png");
}

void	collect_png(t_game *game)
{
	game->collect.tex_collect[0] = mlx_load_png("./image/GB0.png");
	game->collect.tex_collect[1] = mlx_load_png("./image/GB1.png");
	game->collect.tex_collect[2] = mlx_load_png("./image/GB2.png");
	game->collect.tex_collect[3] = mlx_load_png("./image/GB3.png");
	game->collect.tex_collect[4] = mlx_load_png("./image/GB4.png");
	game->collect.tex_collect[5] = mlx_load_png("./image/GB5.png");
}

void	basic_png(t_game *game)
{
	game->map->floor.tex_floor = mlx_load_png("./image/floor0.png");
	game->map->wall.tex_wall = mlx_load_png("./image/wall1.png");
	game->exit.tex_exit[0] = mlx_load_png("./image/exit0.png");
	game->exit.tex_exit[1] = mlx_load_png("./image/exit1.png");
}
