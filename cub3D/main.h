/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:19:40 by aoustani          #+#    #+#             */
/*   Updated: 2023/04/07 14:10:37 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

# define A_KEY 0
# define W_KEY 13
# define S_KEY 1
# define D_KEY 2
# define FOV 60

# define BUFFER_SIZE 32

# define W_HIGHTH 400
# define W_WIDTH 800
# define DDA_L 60
# define R_LEFT  123
# define R_RIGHT 124

# define ESC 53 

# define DISTANCE 7
# define RECT_SIZE 50
# define RED_PIXEL 0xFF0000
# define BROWN_PIXEL 0xA52A2A
# define WHITE_PIXEL 0xFFFFFF
# define GREEN_PIXEL 0xFF00
# define PI 3.14159265359

typedef struct s_data
{
	void	*mlx;
	char	*addr;
	void	*window;
	int		width;
	int		height;
	int		bol;
}			t_data;

typedef struct s_map
{
	int		c;
	int		f;
	char	**my_map;
	char	**only_map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		y;
	int		map_width;
	int		map_height;
	char	position;
	int		tile_size;
	int		x;
	int		player_y;
	int		player_x;
	size_t	longest;
}			t_map;

typedef struct s_player
{
	int		x;
	int		y;
	float	angle;
	char	direction;
	int		left_or_right;
	int		up_down;
	int		rotation;
}			t_player;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_ray
{
	float	distance;
	float	angle;
	float	ray_h_inter_x;
	float	ray_h_inter_y;
	float	ray_v_inter_x;
	float	ray_v_inter_y;
	int		ray_v;
}			t_ray;

typedef struct s_projection
{
	float	distance_proj_plane;
	float	height_wall;
	float	top;
}			t_project;

typedef struct s_texture
{
	void	*mlx_img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}		t_texture;

typedef struct s_game
{
	t_map		map;
	t_texture	texture_no;
	t_texture	texture_so;
	t_texture	texture_we;
	t_texture	texture_ea;
	t_data		data;
	t_img		mini_img;
	t_player	player;
	t_ray		ray[W_WIDTH];
	t_project	project;	
}	t_game;

void	move_left_right(t_game *my);
// void	move_left(t_game *my);
// void	move_right(t_game *my);
void	left_rotation(t_game *my);
void	right_rotation(t_game *my);
int		mini_map(t_game *my);
int		player_move( int key, t_game *my);
void	get_angle(t_game *my);
int		esc(void);
float	normalize_angle(float angle);
float	horizontal_inter(t_game *my, double ray_angle, int index);
float	vertical_inter(t_game *my, double ray_angle, int index);
void	raycast_and_proj(t_game *my);
void	draw_wall(t_game *my, int x, int y, int y2);
void	draw_floor(t_game *my, int x, int y);
void	draw_celling(t_game *my, int x, int y);
void	img_pix_put(t_img *img, int x, int y, int color);
void	move_down(t_game *my);
int		check_vertical(double ray_angle, float *xintercept, float *xstep);
int		check_horizontal(double ray_angle, float
			*yintercept, float *ystep);

//parssing
char	*get_next_line(int fd);
char	**ft_split(const char *s, char c);
int		ft_atoi2(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *buffers, char *buff);
int		ft_strlen(char *s);
char	*ft_strdup2(const char *src);
char	*skip_space(char *line);
void	print_error(char *str);
void	check_texture(char *line, t_map *cub3d);
void	check_color(char *line, t_map *cub3d, char type);
void	count_map(char *line, t_map *cub3d);
void	init_map(t_map *cub3d, char *file);
void	init_player(t_map *cub3d);
void	init_line(char *line, t_map *cub3d, int i);
void	init_map(t_map *cub3d, char *file);
void	check_line(char *line);
void	check_surrounded(t_map *cub3d);
void	print_error(char *str);
void	free_2d(char **str);
int		ft_2dlen(char **str);
char	*remove_space(char *line);
void	ft_read_file(char *file, t_map *cub3d);

#endif