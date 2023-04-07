/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:21:53 by aoustani          #+#    #+#             */
/*   Updated: 2023/04/07 13:03:02 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	left_rotation(t_game *my)
{
	my->player.angle -= 0.05 * my->player.rotation;
}

void	right_rotation(t_game *my)
{
	my->player.angle += 0.05 * my->player.rotation; 
}

void	get_angle(t_game *my)
{
	if (my->map.position == 'N')
		my->player.angle = 3 * PI / 2;
	else if (my->map.position == 'E')
		my->player.angle = 0;
	else if (my->map.position == 'W')
		my->player.angle = PI;
	else if (my->map.position == 'S')
		my->player.angle = PI / 2;
}

void	move_left_right(t_game *my)
{
	int	x;
	int	y;

	x = (my->player.x + my->player.left_or_right * cos(my->player.angle
				 ) * DISTANCE * 5) / RECT_SIZE;
	y = (my->player.y + my->player.left_or_right * sin(my->player.angle
				- (90 * M_PI / 180)) * DISTANCE * 5) / RECT_SIZE;
	if (my->map.my_map[y][x] != '1')
	{
		my->player.x += my->player.left_or_right * cos(my->player.angle
				- (90 * M_PI / 180)) * DISTANCE;
		my->player.y += my->player.left_or_right * sin(my->player.angle
				- (90 * M_PI / 180)) * DISTANCE;
	}
}
