/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input_map.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 15:42:32 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/08/25 17:36:21 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

int	check_component_vitals(t_game *game)
{
	t_map	*map;

	map = game->map;
	if (!map)
		exit(1);
	while (map)
	{
		if (map->component == PLAYER)
			update_player(game, map->x_pos, map->y_pos);
		if (map->component == VILLAIN)
			update_villain(game, map->x_pos, map->y_pos);
		if (map->component == COLLECT)
			update_collect(game, map->x_pos, map->y_pos);
		if (map->component == EXIT)
			update_exit(game, map->x_pos, map->y_pos);
		map = map->next;
	}
	if (game->player.player_check == 0 || game->player.player_check > 1)
		exit_this_way("\33[35;107mWho will play this game?!\33[m\n", 1);
	else if (game->exit.exit_count == 0 || game->exit.exit_count > 1)
		exit_this_way("\33[35;107mWhich way? check exit!\33[m\n", 1);
	else if (game->collect.c_count >= 1)
		return (1);
	return (0);
}

void	check_crack_in_wall(t_map *map, int row, int col)
{
	if (map->x_pos == 0 || map->y_pos == 0 || \
		map->x_pos == col - 1 || map->y_pos == row - 1)
		if (map->component != WALL)
			exit_this_way("\33[35;107mEscaped from Alcatraz,\
				tru a crack in the wall\33[m\n", 1);
}

void	check_component(t_map *map)
{
	if (ft_strchr("01CPEV", map->component) == 0)
		exit_this_way("\33[35;106mNot the right \
			components for the game, a shame...\33[m\n", 1);
}

void	check_map_input(t_game *game)
{
	t_map	*map;
	int		col;
	int		row;

	map = game->map;
	col = game->coll;
	row = game->rows;
	if (!map)
		exit(1);
	while (map)
	{
		check_component(map);
		check_crack_in_wall(map, row, col);
		map = map->next;
	}
	if (check_component_vitals(game) == 0)
		exit_this_way("Go to lost and found! \
		You are missing some components in the map\n", 1);
}
