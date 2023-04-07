
NAME = cub3D
CC = cc
Mlx_F = -lmlx -framework OpenGL -framework AppKit 
CFLAGS = -Wall -Werror -Wextra -g
SRC =	parsing_cub/read_file.c \
		parsing_cub/utilise.c \
		parsing_cub/parse/check_color.c \
		parsing_cub/parse/check_map.c \
		parsing_cub/parse/check_texture.c \
		parsing_cub/parse/init_map.c \
		parsing_cub/utilise/splite.c \
		parsing_cub/utilise/string_utilise.c \
		parsing_cub/utilise/get_next_line.c \
		main.c \
		mini_map.c \
		movements.c\
		raycast.c\
		intersection.c\
		projection.c\
		player_move.c\
		inter_utilise.c\


HEADERS = main.h

OBJECTS = $(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(Mlx_F) $(CFLAGS) $(OBJECTS) -o $(NAME) -g

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_B)

fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)

re: fclean all