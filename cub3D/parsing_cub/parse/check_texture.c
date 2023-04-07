/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:26:39 by oalaoui-          #+#    #+#             */
/*   Updated: 2023/04/04 22:15:42 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	check_texture_extension(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[j] != '.' || str[j + 1] != 'x'
		|| str[j + 2] != 'p' || str[j + 3] != 'm')
		printf("Error : Wrong format2");
}

char	*remove_space2(char *line)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = 0;
	j = ft_strlen(line) - 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[j] == ' ' || line[j] == '\t')
		j--;
	tmp = malloc(sizeof(char) * (j - i + 2));
	k = 0;
	while (i <= j && line[i] != '\n')
		tmp[k++] = line[i++];
	tmp[k] = '\0';
	return (tmp);
}

void	init_texture(t_map *cub3d, char *line, char *texture)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		if (cub3d->no != NULL)
			print_error("Error : NO texture already defined");
		cub3d->no = ft_strdup2(texture);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (cub3d->so != NULL)
			print_error("Error : SO texture already defined");
		cub3d->so = ft_strdup2(texture);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (cub3d->we != NULL)
			print_error("Error : WE texture already defined");
		cub3d->we = ft_strdup2(texture);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		if (cub3d->ea != NULL)
			print_error("Error : EA texture already defined");
		cub3d->ea = ft_strdup2(texture);
	}
}

void	check_texture(char *line, t_map *cub3d)
{
	int		i;
	char	**texture;
	char	*tmp;

	i = 0;
	tmp = remove_space2(line);
	if (line[2] != ' ')
		texture = ft_split(tmp, '\t');
	else
		texture = ft_split(tmp, ' ');
	if (ft_2dlen(texture) != 2)
		print_error("Error : texture format is wrong");
	if (access(texture[1], F_OK) == -1)
		print_error(texture[1]);
	init_texture(cub3d, line, texture[1]);
	free(tmp);
	free_2d(texture);
}
