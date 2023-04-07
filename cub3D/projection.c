/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:55:26 by oalaoui-          #+#    #+#             */
/*   Updated: 2023/04/05 11:38:19 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_texture	*get_texture(t_game *my, int x)
{
	if (my->ray[x].ray_v == 1)
	{
		if (my->ray[x].ray_v_inter_x > my->player.x)
			return (&my->texture_ea);
		else
			return (&my->texture_we);
	}
	else
	{
		if (my->ray[x].ray_h_inter_y > my->player.y)
			return (&my->texture_so);
		else
			return (&my->texture_no);
	}
}

void	draw_wall(t_game *my, int x, int y, int y2)
{
	int			i;
	int			*color;
	double		y_t;
	double		x_t;
	t_texture	*texture;

	i = y;
	texture = get_texture(my, x);
	if (my->ray[x].ray_v != 1)
		x_t = fmod(my->ray[x].ray_h_inter_x, RECT_SIZE)
			* texture->width / RECT_SIZE;
	else
		x_t = fmod(my->ray[x].ray_v_inter_y, RECT_SIZE)
			* texture->width / RECT_SIZE;
	while (i < y2)
	{
		y_t = (i - y) * texture->height / (y2 - y);
		color = texture->addr + (int)y_t * texture->width + (int)x_t;
		img_pix_put(&my->mini_img, x, i, *color);
		i++;
	}
}

void	draw_floor(t_game *my, int x, int y)
{
	int	i;

	i = y;
	while (i < W_HIGHTH)
	{
		img_pix_put(&my->mini_img, x, i, my->map.f);
		i++;
	}
}

void	draw_celling(t_game *my, int x, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		img_pix_put(&my->mini_img, x, i, my->map.c);
		i++;
	}
}
