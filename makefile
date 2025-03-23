NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 

SRCS = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		src/parse_map_utils.c src/parse_map.c src/fill_map.c src/keys_map.c src/flood_fill.c \
		src/utils.c src/utils2.c src/utils3.c \
		printf/ft_printf.c printf/ft_put_nbr.c printf/ft_put_str.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lmlx -lXext -lX11

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all