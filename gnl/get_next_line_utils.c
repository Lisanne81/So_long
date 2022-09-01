/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 08:08:00 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/04/08 11:33:03 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	check_line_length(char *line, char to_find)
{
	int			give_back;

	give_back = 0;
	while (line[give_back] != '\0' && line[give_back] != to_find)
	{
		give_back++;
	}
	return (give_back);
}

int	compair_and_copy(char *line1, char *line2, char to_find)
{
	while (line2 && *line2 != to_find && *line2)
	{
		*line1 = *line2;
		line1++;
		line2++;
	}
	*line1 = '\0';
	if (line2 && *line2 == '\n')
		return (1);
	return (0);
}

int	move_and_join(char **line, char *buff_line)
{
	int		tracker;
	int		give_back;
	int		index;

	tracker = check_line_length(*line, '\0');
	give_back = compair_and_copy(*line + tracker, buff_line, '\n');
	index = check_line_length(buff_line, '\n') + 1;
	if (buff_line[index - 1] == '\0')
	{
		buff_line[0] = '\0';
		return (give_back);
	}
	else
	{
		compair_and_copy(buff_line, buff_line + index, '\0');
		return (give_back);
	}
}
