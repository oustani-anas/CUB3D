/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:26:48 by oalaoui-          #+#    #+#             */
/*   Updated: 2023/04/04 22:16:47 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	ft_isdigite(char *str)
{
	int	i;

	i = 0;
	if (ft_atoi2(str) > 255 || ft_atoi2(str) < 0)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	check_color_digite(char *str, t_map *cub3d, char type)
{
	char	**color;
	int		i;

	i = 0;
	color = ft_split(str, ',');
	if (color[0] == NULL || color[1] == NULL || color[2] == NULL)
		print_error("Error : Wrong format5");
	if (ft_isdigite(color[0]) == 0 || ft_isdigite(color[1]) == 0
		|| ft_isdigite(color[2]) == 0)
		print_error("Error : Wrong format4");
	if (type == 'F')
	{
		if (cub3d->f != -1)
			print_error("Error : F color already defined");
		cub3d->f = (ft_atoi2(color[0]) << 16) + (ft_atoi2(color[1]) << 8)
			+ (ft_atoi2(color[2]));
	}
	else if (type == 'C')
	{
		if (cub3d->c != -1)
			print_error("Error : C color already defined");
		cub3d->c = (ft_atoi2(color[0]) << 16) + (ft_atoi2(color[1]) << 8)
			+ (ft_atoi2(color[2]));
	}
	free_2d(color);
}

void	check_color(char *line, t_map *cub3d, char type)
{
	int		i;
	int		j;
	char	**color;
	char	*tmp;

	i = 0;
	j = 0;
	if (line[1] != ' ')
		color = ft_split(line, '\t');
	else
		color = ft_split(line, ' ');
	if (color[1] == NULL)
		print_error("Error : Wrong format3");
	tmp = remove_space(line);
	while (tmp[i] && tmp[i] != '\n')
	{
		if (tmp[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		print_error("Error : alot of , in color");
	check_color_digite(tmp + 1, cub3d, type);
	free(tmp);
	free_2d(color);
}
