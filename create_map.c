/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: By: lhoukes <lhoukes@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 23:54:23 by lisannehouk   #+#    #+#                 */
/*   Updated: 2022/08/26 10:50:03 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

t_map	*insert_at_end(char component, int x, int y)
{
	t_map	*current_node;

	current_node = (t_map *) malloc(sizeof(t_map));
	if (!current_node)
		exit(1);
	current_node->x_pos = x;
	current_node->y_pos = y;
	current_node->component = component;
	current_node->next = NULL;
	return (current_node);
}

void	add_node(t_map **map_line, t_map *new)
{
	t_map	*tmp;

	tmp = *map_line;
	if (*map_line)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*map_line = new;
}

void	create_map(t_map **map, char *map_line, int y)
{
	t_map	*grid_pos;
	int		x;

	x = 0;
	if (!map_line)
		exit_this_way("no line to read\n", 1);
	while (map_line[x] && map_line[x] != '\n')
	{
		grid_pos = insert_at_end(map_line[x], x, y);
		add_node(map, grid_pos);
		x++;
	}
}
