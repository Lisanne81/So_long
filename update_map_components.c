/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_map_components.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 09:37:00 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/08/17 23:15:04 by lisannehouk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

void	update_villain(t_game *game, int x, int y)
{
	game->villain.villain_moves++;
	game->villain.x = x;
	game->villain.y = y;
}

void	update_player(t_game *game, int x, int y)
{
	game->player.player_check++;
	game->player.x = x;
	game->player.y = y;
}

void	update_collect(t_game *game, int x, int y)
{
	game->collect.c_count++;
	game->collect.x = x;
	game->collect.y = y;
}

void	update_exit(t_game *game, int x, int y)
{
	game->exit.exit_count++;
	game->exit.x = x;
	game->exit.y = y;
}
