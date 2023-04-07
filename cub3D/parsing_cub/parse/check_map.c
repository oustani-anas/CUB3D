/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:26:42 by oalaoui-          #+#    #+#             */
/*   Updated: 2023/04/06 09:10:08 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	count_map(char *line, t_map *cub3d)
{
	if (cub3d->c == -1 || cub3d->f == -1)
		print_error("Error : Floor color not set");
	if (cub3d->no == NULL || cub3d->so == NULL
		|| cub3d->we == NULL || cub3d->ea == NULL)
		print_error("Error : Texture not set");
	cub3d->map_height += 1;
	if (ft_strlen(line) - 1 > cub3d->map_width)
		cub3d->map_width = ft_strlen(line);
}

void	check_surrounded(t_map *cub3d)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub3d->map_height)
	{
		j = 0;
		while (j < cub3d->map_width && cub3d->my_map[i][j++] != '\0'
			&& cub3d->my_map[i][j] != '\n' && cub3d->my_map[i][j + 1] != '\0'
			&& cub3d->my_map[i][j + 1] != '\n')
		{
			if (cub3d->my_map[i][j] == ' ')
			{
				if (i != 0 && cub3d->my_map[i - 1][j] == '0')
					print_error("Error : Map not surrounded by walls");
				if (i != cub3d->map_height - 1
					&& cub3d->my_map[i + 1][j] == '0')
					print_error("Error : Map not surrounded by walls");
				if (cub3d->my_map[i][j - 1] == '0' && j != 0)
					print_error("Error : Map not surrounded by walls");
				if (cub3d->my_map[i][j + 1] == '0')
					print_error("Error : Map not surrounded by walls");
			}
		}
	}
}

void	check_left(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1')
		print_error("Error : Map not surrounded by walls");
	else if (line[i] == '\0' || line[i] == '\n')
		print_error("Error : Map not surrounded by walls");
}

void	check_right(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	i--;
	while (line[i] == ' ')
		i--;
	if (line[i] != '1')
	{
		printf("%s | %c \n", line, line[i]);
		print_error("Error : Map not surrounded by walls");
	}
}

void	check_line(char *line)
{
	int	i;

	i = 0;
	check_left(line);
	check_right(line);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != ' ')
			print_error("Error : Wrong character in the map");
		i++;
	}
}
