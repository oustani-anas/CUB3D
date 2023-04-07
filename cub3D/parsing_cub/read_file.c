/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:27:24 by oalaoui-          #+#    #+#             */
/*   Updated: 2023/04/04 22:15:00 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_struct(t_map *cub3d)
{
	cub3d->my_map = NULL;
	cub3d->no = NULL;
	cub3d->so = NULL;
	cub3d->we = NULL;
	cub3d->ea = NULL;
	cub3d->c = -1;
	cub3d->f = -1;
	cub3d->position = '0';
}

char	*skip_space(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

void	check_format(char *line, t_map *cub3d, char *str)
{
	(void)str;
	if (line[0] == '\0' || line[0] == '\n')
		return ;
	if (line[0] == 'N' && line[1] == 'O' && (line[2] == ' ' || line[2] == '\t'))
		check_texture(line, cub3d);
	else if (line[0] == 'S' && line[1] == 'O'
		&& (line[2] == ' ' || line[2] == '\t'))
		check_texture(line, cub3d);
	else if (line[0] == 'W' && line[1] == 'E'
		&& (line[2] == ' ' || line[2] == '\t'))
		check_texture(line, cub3d);
	else if (line[0] == 'E' && line[1] == 'A'
		&& (line[2] == ' ' || line[2] == '\t'))
		check_texture(line, cub3d);
	else if (line[0] == 'F' && (line[1] == ' ' || line[1] == '\t'))
		check_color(line, cub3d, 'F');
	else if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
		check_color(line, cub3d, 'C');
	else if (line[0] == '1')
		count_map(line, cub3d);
	else if (line[0] == '\0')
		return ;
	else
		print_error("Error : Wrong format");
}

void	ft_read_file(char *file, t_map *cub3d)
{
	int		fd;
	char	*line;
	char	*line2;
	int		i;

	i = 0;
	init_struct(cub3d);
	fd = open(file, O_RDWR);
	if (fd == -1)
		print_error("Error : Can't open file");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line2 = skip_space(line);
		check_format(line2, cub3d, line);
		free(line);
	}
	close(fd);
	init_map(cub3d, file);
}
