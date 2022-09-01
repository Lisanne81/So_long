/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 17:53:04 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/09/01 18:08:48 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

/*
** Check the file for right extension
** We parse the map with GNL
** the first line of the map is read untill the \n
** the length of this line is used to check the shape of map
*/

void	valid_extention(char *file)
{
	int	length;

	length = ft_strlen(file);
	if (length < 4)
		exit_this_way("\33[35;106mWrong file, wrong life!\033[m\n", 1);
	if (ft_strncmp(file + length - 4, ".ber", 5))
		exit_this_way("\33[35;106mWrong file, wrong life!\033[m\n", 1);
}

void	check_shape_map(char *element_in_row, int coll_len)
{
	int	counter;

	counter = 0;
	if (coll_len == 0)
		exit_this_way("\33[35;106mNeed a map to find the line!\33[m\n", 1);
	while (element_in_row[counter] != '\0')
	{
		counter++;
	}
	if (counter == 0)
		exit_this_way("\33[35;106mOut of shape!\033[m\n", 1);
	if (counter == coll_len)
		return ;
	else
	{
		exit_this_way("\33[35;106mOut of shape!\033[m\n", 1);
	}
}

void	parse_map(t_game *game, char *file_map)
{
	int		fd;
	int		gnl;
	char	*map_line;
	int		first_line;

	fd = open(file_map, O_RDONLY);
	valid_extention(file_map);
	if (fd < 0)
		exit_this_way("What the FD!? the buck stops here\n", 1);
	gnl = 1;
	first_line = 0;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &map_line);
		if (first_line == 0)
		{
			game->coll = ft_strlen(map_line);
			first_line = 1;
		}
		check_shape_map(map_line, game->coll);
		create_map(&game->map, map_line, game->rows);
		free(map_line);
		game->rows++;
	}
	close(fd);
}
