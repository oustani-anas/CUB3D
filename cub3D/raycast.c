/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 04:24:12 by aoustani          #+#    #+#             */
/*   Updated: 2023/04/07 14:04:13 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	render_wall(t_game *my, int i)
{
	double	wall_height;
	double	distance_p_p;
	double	wall_bottom_pixel;
	double	wall_top_pixel;

	distance_p_p = (W_WIDTH / 2) / tan((FOV / 2) * (M_PI / 180));
	wall_height = RECT_SIZE / my->ray[i].distance * distance_p_p; 
	wall_bottom_pixel = (W_HIGHTH / 2) + (wall_height /  2);
	wall_top_pixel = (W_HIGHTH / 2) - (wall_height / 2);
	draw_wall(my, i, wall_top_pixel, wall_bottom_pixel);
	draw_floor(my, i, wall_bottom_pixel);
	draw_celling(my, i, wall_top_pixel);
}

void	set_xintercept(t_game *my, double x, int i)
{
	my->ray[i].ray_v = 1;
	my->ray[i].distance = x;
}

void	  raycast_and_proj(t_game *my)
{
	double	xintercept;
	double	yintercept;
	int		i;

	i = -1;
	while (++i < W_WIDTH)
	{
		my->ray[i].ray_v = 0;
		if (i == 0)
			my->ray[i].angle = my->player.angle - ((FOV / 2) * (M_PI / 180));
		else
			my->ray[i].angle = my->ray[i - 1].angle + \
			(FOV * (M_PI / 180) / W_WIDTH);   
		yintercept = horizontal_inter(my, my->ray[i].angle, i);
		xintercept = vertical_inter(my, my->ray[i].angle, i);
		if (yintercept < xintercept) 
			my->ray[i].distance = yintercept;
		else
			set_xintercept(my, xintercept, i);
		my->ray[i].distance *= cos(normalize_angle(\
			my->ray[i].angle - my->player.angle));
		render_wall(my, i);
	}
}
