/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_utilise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:36:28 by oalaoui-          #+#    #+#             */
/*   Updated: 2023/04/05 09:19:07 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_vertical(double ray_angle, float *xintercept, float *xstep)
{
	if (!(ray_angle > M_PI / 2 && ray_angle < 3 * M_PI / 2))
	{
		*xintercept += RECT_SIZE;
		return (0);
	}
	else
	{
		*xstep *= -1;
		return (1);
	}
}

int	check_horizontal(double ray_angle, float *yintercept, float *ystep)
{
	if (ray_angle > 0 && ray_angle < M_PI)
	{
		*yintercept += RECT_SIZE;
		return (0);
	}
	else
	{
		*ystep *= -1;
		return (1);
	}
}
