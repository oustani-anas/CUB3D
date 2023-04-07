/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 07:30:28 by aoustani          #+#    #+#             */
/*   Updated: 2023/04/05 09:42:36 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= W_WIDTH || y >= W_HIGHTH)
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	draw_rect(t_img *img, int i, int j, int color)
{
	int		x;
	int		y;

	y = i;
	while (y < i + RECT_SIZE - 1)
	{
		x = j;
		while (x < j + RECT_SIZE - 1)
			img_pix_put(img, x++, y, color);
		++y;
	}
}

int	mini_map(t_game *my)
{
	mlx_clear_window(my->data.mlx, my->data.window);
	my->mini_img.mlx_img = mlx_new_image(my->data.mlx, W_WIDTH, W_HIGHTH);
	my->mini_img.addr = mlx_get_data_addr(my->mini_img.mlx_img, \
	&my->mini_img.bpp, &my->mini_img.line_len, \
	&my->mini_img.endian);
	move_down(my);
	left_rotation(my);
	move_left_right(my);
	raycast_and_proj(my);
	mlx_put_image_to_window(my->data.mlx, my->data.window, \
	my->mini_img.mlx_img, 0, 0);
	my->data.bol = 0;
	return (1);
}
