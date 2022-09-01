/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 07:35:10 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/08/25 18:29:06 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

void	animation(void *param)
{
	t_game	*game;

	game = param;
	game->time_frame += game->mlx->delta_time;
	if (game->time_frame >= 0.2)
	{
		game->time_frame = 0;
		if (game->current_frame == 6)
			game->current_frame = 0;
		if (game->collect.collect_on_off == 0 || \
			game->collect.collect_on_off == 1)
			mlx_draw_texture(game->collect.i_collect, \
				game->collect.tex_collect[game->current_frame], 0, 0);
		if (game->villain.villain_on_off == 1)
			mlx_draw_texture(game->villain.i_villain, \
				game->villain.tex_villain[game->current_frame], 0, 0);
		if (game->player.player_direction == 0)
			mlx_draw_texture(game->player.i_player, \
				game->player.tex_player_left[game->current_frame], 0, 0);
		else if (game->player.player_direction == 1)
			mlx_draw_texture(game->player.i_player, \
				game->player.tex_player_right[game->current_frame], 0, 0);
		game->current_frame++;
	}
}
