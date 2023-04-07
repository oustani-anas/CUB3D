/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:39:15 by aoustani          #+#    #+#             */
/*   Updated: 2023/04/07 13:04:35 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_extension(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'b' || str[i - 1] != 'u' \
	|| str[i - 2] != 'c' || str[i - 3] != '.')
		print_error("Error \nWrong extension");
}

void	load_textures(t_game *my)
{
	my->texture_no.mlx_img = mlx_xpm_file_to_image(my->data.mlx, \
	my->map.no, &my->texture_no.width, &my->texture_no.height);
	my->texture_so.mlx_img = mlx_xpm_file_to_image(my->data.mlx, my->map.so, \
	&my->texture_so.width, &my->texture_so.height);
	my->texture_we.mlx_img = mlx_xpm_file_to_image(my->data.mlx, my->map.we, \
	&my->texture_we.width, &my->texture_we.height);
	my->texture_ea.mlx_img = mlx_xpm_file_to_image(my->data.mlx, my->map.ea, \
	&my->texture_ea.width, &my->texture_ea.height);
	if (!my->texture_no.mlx_img || !my->texture_ea.mlx_img
		|| !my->texture_so.mlx_img || !my->texture_we.mlx_img)
		print_error("error: file not found");
	my->texture_no.addr = (int *)mlx_get_data_addr(my->texture_no.mlx_img, \
	&my->texture_no.bpp, &my->texture_no.line_len, &my->texture_no.endian);
	my->texture_so.addr = (int *)mlx_get_data_addr(my->texture_so.mlx_img, \
	&my->texture_so.bpp, &my->texture_so.line_len, &my->texture_so.endian);
	my->texture_we.addr = (int *)mlx_get_data_addr(my->texture_we.mlx_img, \
	&my->texture_we.bpp, &my->texture_we.line_len, &my->texture_we.endian);
	my->texture_ea.addr = (int *)mlx_get_data_addr(my->texture_ea.mlx_img, \
	&my->texture_ea.bpp, &my->texture_ea.line_len, &my->texture_ea.endian);
}

int	key_release(int key, t_game *my)
{
	if (key == W_KEY)
		my->player.up_down = 0;
	if (key == S_KEY)
		my->player.up_down = 0;
	if (key == D_KEY)
		my->player.left_or_right = 0;
	if (key == A_KEY)
		my->player.left_or_right = 0;
	if (key == R_LEFT)
		my->player.rotation = 0;
	if (key == R_RIGHT)
		my->player.rotation = 0;
	return (0);
}

void	init_player_info(t_game *my)
{
	my->player.x = my->map.player_x * RECT_SIZE + RECT_SIZE / 2;
	my->player.y = my->map.player_y * RECT_SIZE + RECT_SIZE / 2;
	my->player.up_down = 0;
	my->player.left_or_right = 0;
	my->player.rotation = 0;
}
void v()
{
	system("leaks cub3D");
}
int	main(int ac, char **av)
{
	t_game	game;
// atexit(v);
	if (ac != 2)
		return (printf("INVALID ARGUMENTS\n"), 1);
	game.map.map_width = 0;
	game.map.map_height = 0;
	check_extension(av[1]);
	ft_read_file(av[1], &game.map);
	game.data.mlx = mlx_init();
	game.data.window = mlx_new_window(game.data.mlx, W_WIDTH,
			W_HIGHTH, "Cub3D");
	load_textures(&game);
	init_player_info(&game);
	get_angle(&game);
	mlx_hook(game.data.window, 2, 0, player_move, &game);
	mlx_hook(game.data.window, 3, 0, key_release, &game);
	mlx_hook(game.data.window, 17, 0, esc, NULL);
	mlx_loop_hook(game.data.mlx, mini_map, &game);
	mlx_loop(game.data.mlx);
	return (0);
}
