/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:32:04 by oalaoui-          #+#    #+#             */
/*   Updated: 2023/04/06 09:10:08 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	init_player(t_map *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub3d->map_height)
	{
		j = 0;
		while (j < cub3d->map_width && cub3d->my_map[i][j] != '\0'
			&& cub3d->my_map[i][j] != '\n')
		{
			if (cub3d->my_map[i][j] == 'N' || cub3d->my_map[i][j] == 'S'
				|| cub3d->my_map[i][j] == 'E' || cub3d->my_map[i][j] == 'W')
			{
				if (cub3d->position != '0')
					print_error("Error : More than one player");
				cub3d->player_x = j;
				cub3d->player_y = i;
				cub3d->position = cub3d->my_map[i][j];
			}
			j++;
		}
		i++;
	}
	if (cub3d->position == '0')
		print_error("Error : Player not found");
}

void	init_line(char *line, t_map *cub3d, int i)
{
	int	j;

	j = 0;
	cub3d->my_map[i] = malloc(sizeof(char) * cub3d->map_width + 1);
	while (line[j] != '\0' && line[j] != '\n')
	{
		cub3d->my_map[i][j] = line[j];
		j++;
	}
	while (j < cub3d->map_width)
	{
		cub3d->my_map[i][j] = ' ';
		j++;
	}
	cub3d->my_map[i][j] = '\0';
}

void	check_first_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != ' ')
			print_error("Error : map is not surrounded by walls");
		i++;
	}
}

void	check_norm(t_map *cub3d, int fd)
{
	close(fd);
	init_player(cub3d);
	check_first_last_line(cub3d->my_map[0]);
	check_first_last_line(cub3d->my_map[cub3d->map_height - 1]);
	check_surrounded(cub3d);
}

void	init_map(t_map *cub3d, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	cub3d->my_map = malloc(sizeof(char *) * cub3d->map_height + 3);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) == 1 && line[0] == '\n' && i > 0)
			print_error("Error : Empty line in the map");
		if (skip_space(line)[0] == '1')
		{
			check_line(line);
			init_line(line, cub3d, i++);
		}
		else if ((skip_space(line)[0] == '\0'
			|| skip_space(line)[0] == '\n') && i > 0)
			print_error("Error : Map not surrounded by walls");
		free(line);
	}
	check_norm(cub3d, fd);
}
