/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 17:34:58 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/08/26 10:28:44 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_this_way("\33[35;106mAre these the right 'ARGuments?'.\33[m\n", 1);
	ft_bzero(&game, sizeof(t_game));
	mlx_stretch_imgs = true;
	init_game(&game);
	parse_map(&game, argv[1]);
	check_map_input(&game);
	create_window(&game);
	mlx_key_hook(game.mlx, &my_key_hook, &game);
	mlx_loop_hook(game.mlx, &animation, &game);
	mlx_close_hook(game.mlx, exit_on_click, &game);
	mlx_loop(game.mlx);
	ft_putstr_fd("\33[35;107mSo Long and thanks for the Fish!\33[m\n", 1);
	clean_field(&game);
	free_map(game.map);
	mlx_terminate(game.mlx);
	return (0);
}
