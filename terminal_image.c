/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   terminal_image.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/21 20:52:37 by lisannehouk   #+#    #+#                 */
/*   Updated: 2022/08/26 10:51:01 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "./includes/so_long.h"

static void	printline(char *line, int no)
{
	int	index;

	index = 0;
	while (index < no)
	{
		ft_putstr_fd(" ", 1);
		index++;
	}
	ft_putstr_fd(line, 1);
	ft_putchar_fd('\n', 1);
}

static void	keen_banner(int create_line)
{
	char	*line[8];
	int		index;

	line[0] = G40" █████   ████";
	line[1] = G41"░░███   ███░   COMMANDER";
	line[2] = G42" ░███  ███    ██████  ██████  ████████";
	line[3] = G43"  ░███████    ███░░██████░░███░░███░░███";
	line[4] = G46" ░███░░███   ░███████░███████  ░███ ░███";
	line[5] = G47" ░███ ░░███  ░███░░░ ░███░░░   ░███ ░███";
	line[6] = G48" █████ ░░████░░██████░░██████  ████ █████";
	line[7] = G49"░░░░░   ░░░░  ░░░░░░  ░░░░░░  ░░░░ ░░░░░ ";
	index = 0;
	while (index < 8)
	{
		printline(line[index], create_line);
		index++;
	}
}	

static void	game_banner(int create_line)
{
	char	*line[6];
	int		index;

	line[0] = R124" \n ██████╗  █████╗ ███╗   ███╗███████╗";
	line[1] = B17"██╔════╝ ██╔══██╗████╗ ████║██╔════╝";
	line[2] = B18"██║  ███╗███████║██╔████╔██║█████╗  ";
	line[3] = B19"██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ";
	line[4] = B20"╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗";
	line[5] = RESET" ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝";
	index = 0;
	while (index < 6)
	{
		printline(line[index], create_line);
		index++;
	}
}

static void	over_banner(int create_line)
{
	char	*line[6];
	int		index;

	line[0] = B20" ██████╗ ██╗   ██╗███████╗██████╗ ";
	line[1] = B19"██╔═══██╗██║   ██║██╔════╝██╔══██╗";
	line[2] = B18"██║   ██║██║   ██║█████╗  ██████╔╝";
	line[3] = B17"██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗";
	line[4] = R124"╚██████╔╝ ╚████╔╝ ███████╗██║  ██║";
	line[5] = RESET" ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝";
	index = 0;
	while (index < 6)
	{
		printline(line[index], create_line);
		index++;
	}
}

int	ft_print_banner(int num)
{
	int	index;

	index = 0;
	if (num == 1)
	{
		while (index < 1)
		{
			game_banner(index);
			over_banner(index);
			index++;
		}
	}
	else if (num == 2)
	{
		while (index < 1)
		{
			keen_banner(index);
			index++;
		}
	}
	return (0);
}
