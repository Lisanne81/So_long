/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_moves.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 22:33:59 by lisannehouk   #+#    #+#                 */
/*   Updated: 2022/08/26 10:49:46 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

void	player_left(t_game *game)
{
	mlx_draw_texture(game->player.i_player, \
		game->player.tex_player_left[0], 0, 0);
	if (!player_colide(game, game->player.x - 1, game->player.y, 0))
	{
		game->player.i_player->instances[0].x -= TILE_SIZE;
		game->moves++;
		game->player.x--;
		game->player.player_direction = 0;
		if (game->counter_on_off == 1)
		{
			ft_putstr_fd("Moves: ", 1);
			ft_putnbr_fd(game->moves, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	player_right(t_game *game)
{
	mlx_draw_texture(game->player.i_player, \
		game->player.tex_player_right[0], 0, 0);
	if (!player_colide(game, game->player.x + 1, game->player.y, 0))
	{
		game->player.i_player->instances[0].x += TILE_SIZE;
		game->moves++;
		game->player.x++;
		game->player.player_direction = 1;
		if (game->counter_on_off == 1)
		{
			ft_putstr_fd("Moves: ", 1);
			ft_putnbr_fd(game->moves, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	player_up(t_game *game)
{
	if (!player_colide(game, game->player.x, game->player.y - 1, 0))
	{
		game->player.i_player->instances[0].y -= TILE_SIZE;
		game->moves++;
		game->player.y--;
		if (game->counter_on_off == 1)
		{
			ft_putstr_fd("Moves: ", 1);
			ft_putnbr_fd(game->moves, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	player_down(t_game *game)
{
	if (!player_colide(game, game->player.x, game->player.y + 1, 0))
	{
		game->player.i_player->instances[0].y += TILE_SIZE;
		game->moves++;
		game->player.y++;
		if (game->counter_on_off == 1)
		{
			ft_putstr_fd("Moves: ", 1);
			ft_putnbr_fd(game->moves, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	update_counter(t_game *game)
{
	int		counter;
	char	*str;

	counter = game->moves;
	str = ft_itoa(counter);
	mlx_delete_image(game->mlx, game->image_counter);
	game->image_counter = mlx_put_string(game->mlx, str, \
		game->coll / 2 + 64, 10);
	if (str)
		free(str);
}
