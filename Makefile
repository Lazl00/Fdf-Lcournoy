CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0 -Iincludes -IMLX42

NAME = fdf
MLX42 = MLX42/libmlx_Linux.a
LIBS = -lXext -lX11 -lm -lz

SRCS = $(addprefix srcs/, draw_map.c free_vars.c ft_atoi.c get_coords.c get_map.c get_next_line_utils.c get_next_line.c int_split.c line.c main.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX42) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
