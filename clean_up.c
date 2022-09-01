/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_up.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 13:58:29 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/08/26 10:24:39 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

void	clean_player(t_game *game)
{
	mlx_delete_texture(game->player.tex_player_left[0]);
	mlx_delete_texture(game->player.tex_player_left[1]);
	mlx_delete_texture(game->player.tex_player_left[2]);
	mlx_delete_texture(game->player.tex_player_left[3]);
	mlx_delete_texture(game->player.tex_player_left[4]);
	mlx_delete_texture(game->player.tex_player_left[5]);
	mlx_delete_texture(game->player.tex_player_right[0]);
	mlx_delete_texture(game->player.tex_player_right[1]);
	mlx_delete_texture(game->player.tex_player_right[2]);
	mlx_delete_texture(game->player.tex_player_right[3]);
	mlx_delete_texture(game->player.tex_player_right[4]);
	mlx_delete_texture(game->player.tex_player_right[5]);
	mlx_delete_image(game->mlx, game->player.i_player);
}

void	clean_collect(t_game *game)
{
	if (game->collect.i_collect != NULL)
	{
		mlx_delete_texture(game->collect.tex_collect[0]);
		mlx_delete_texture(game->collect.tex_collect[1]);
		mlx_delete_texture(game->collect.tex_collect[2]);
		mlx_delete_texture(game->collect.tex_collect[3]);
		mlx_delete_texture(game->collect.tex_collect[4]);
		mlx_delete_texture(game->collect.tex_collect[5]);
		mlx_delete_image(game->mlx, game->collect.i_collect);
	}
}

void	clean_villain(t_game *game)
{
	mlx_delete_texture(game->villain.tex_villain[0]);
	mlx_delete_texture(game->villain.tex_villain[1]);
	mlx_delete_texture(game->villain.tex_villain[2]);
	mlx_delete_texture(game->villain.tex_villain[3]);
	mlx_delete_texture(game->villain.tex_villain[4]);
	mlx_delete_texture(game->villain.tex_villain[5]);
	mlx_delete_image(game->mlx, game->villain.i_villain);
}

void	clean_elements(t_game *game)
{
	mlx_delete_texture(game->map->wall.tex_wall);
	mlx_delete_texture(game->map->floor.tex_floor);
	mlx_delete_texture(game->exit.tex_exit[0]);
	mlx_delete_texture(game->exit.tex_exit[1]);
	mlx_delete_image(game->mlx, game->exit.i_exit);
	mlx_delete_image(game->mlx, game->image_counter);
	mlx_delete_image(game->mlx, game->steps);
	mlx_delete_image(game->mlx, game->win);
	mlx_delete_image(game->mlx, game->lose);
	mlx_delete_image(game->mlx, game->escape);
	mlx_delete_image(game->mlx, game->earth);
	mlx_delete_image(game->mlx, game->background);
}

void	clean_field(t_game *game)
{
	clean_player(game);
	clean_villain(game);
	clean_collect(game);
	clean_elements(game);
	ft_print_banner(1);
	ft_putstr_fd(G22"\n\tTime to close: \n\n", 1);
	ft_print_banner(2);
}
