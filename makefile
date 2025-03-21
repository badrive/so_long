NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 

SRCS = so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		src/parse_map.c src/utils.c src/fill_map.c src/keys_map.c src/flood_fill.c \
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