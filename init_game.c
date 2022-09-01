/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 16:47:45 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/08/26 10:12:35 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

static void	start_game(void)
{
	ft_print_banner(2);
	ft_putstr_fd(Y185"Game Boy Collecter\n"RESET, 1);
}

void	init_game(t_game *game)
{
	game->rows = 0;
	game->coll = 0;
	game->map = NULL;
	game->moves = 0;
	game->current_frame = 0;
	game->player.player_direction = 0;
	game->villain.villain_on_off = 0;
	game->counter_on_off = 1;
	game->collect.collect_on_off = 0;
	game->keyhook_on_of = 0;
	start_game();
}
