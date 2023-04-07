/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:37:27 by aoustani          #+#    #+#             */
/*   Updated: 2023/04/06 11:54:43 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	esc(void)
{
	exit(0);
	return (0);
}

void	move_down(t_game *my)
{
	int	x;
	int	y;

	x = (my->player.x + my->player.up_down * cos(my->player.angle)
			* DISTANCE * 5) / RECT_SIZE;
	if (my->map.my_map[my->player.y / RECT_SIZE][x] != '1')
	{
		y = (my->player.y + my->player.up_down * sin(my->player.angle)
				* DISTANCE * 5) / RECT_SIZE;
		if (my->map.my_map[y][my->player.x / RECT_SIZE] != '1')
		{	
			my->player.x += my->player.up_down
				* cos(my->player.angle) * DISTANCE;
			my->player.y += my->player.up_down * sin(my->player.angle)
				* DISTANCE;
		}
	}
}

int	player_move(int key, t_game *my)
{
	if (key == W_KEY)
		my->player.up_down = 1;
	if (key == S_KEY)
		my->player.up_down = -1;
	if (key == D_KEY)
		my->player.left_or_right = -1;
	if (key == A_KEY)
		my->player.left_or_right = 1;
	if (key == R_LEFT)
		my->player.rotation = 1;
	if (key == R_RIGHT)
		my->player.rotation = -1;
	if (key == ESC)
		esc();
	return (0);
}
