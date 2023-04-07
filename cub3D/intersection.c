/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:09:53 by aoustani          #+#    #+#             */
/*   Updated: 2023/04/07 13:44:55 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int	check_wall(float x, float y, t_game *my)
{
	int	i;
	int	j;

	if (x < 0 || y < 0)
		return (0);
	i = floor ((x) / RECT_SIZE);
	j = floor ((y) / RECT_SIZE);
	if ((y >= my->map.map_height * RECT_SIZE \
		|| x >= my->map.map_width * RECT_SIZE \
		|| (j >= my->map.map_height || i >= my->map.map_width)))
		return (0);
	if (my->map.my_map[j])
	{
		if (my->map.my_map[j][i] == '1')
			return (0);
	}
	return (1);
}

float	normalize_angle(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

float	horizontal_inter(t_game *my, double ray_angle, int index)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		check;

	ystep = RECT_SIZE;
	ray_angle = normalize_angle(ray_angle);
	yintercept = floor(my->player.y / RECT_SIZE) * RECT_SIZE;
	check = check_horizontal(ray_angle, &yintercept, &ystep);
	xintercept = my->player.x + (yintercept - my->player.y) / tan(ray_angle); 
	xstep = RECT_SIZE / tan(   ray_angle); 
	if ((ray_angle >= M_PI / 2 && ray_angle <= 3 * M_PI / 2) && xstep > 0)
		xstep *= -1;
	else if (!(ray_angle > M_PI / 2 && ray_angle < 3 * M_PI / 2) && xstep < 0)
		xstep *= -1; 
	while (check_wall(xintercept, yintercept - check, my))
	{
		xintercept += xstep;
		yintercept += ystep;
	}
	my->ray[index].ray_h_inter_x = xintercept;
	my->ray[index].ray_h_inter_y = yintercept;
	return (distance(my->player.x, my->player.y, \
	my->ray[index].ray_h_inter_x, my->ray[index].ray_h_inter_y));
}

float	vertical_inter(t_game *my, double ray_angle, int index)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		check;

	ray_angle = normalize_angle(ray_angle);
	xintercept = floor(my->player.x / RECT_SIZE) * RECT_SIZE;
	xstep = RECT_SIZE;
	check = check_vertical(ray_angle, &xintercept, &xstep);
	yintercept = my->player.y + (xintercept - my->player.x) * tan(ray_angle);
	ystep = RECT_SIZE * tan(ray_angle);
	if ((ray_angle > 0 && ray_angle < M_PI) && ystep < 0)
		ystep *= -1;
	else if (!(ray_angle > 0 && ray_angle < M_PI) && ystep > 0)
		ystep *= -1;
	while (check_wall(xintercept - check, yintercept, my))
	{
		xintercept += xstep;
		yintercept += ystep;
	}
	my->ray[index].ray_v_inter_x = xintercept;
	my->ray[index].ray_v_inter_y = yintercept;
	return (distance(my->player.x, my->player.y, \
	my->ray[index].ray_v_inter_x, my->ray[index].ray_v_inter_y));
}
