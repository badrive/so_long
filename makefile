NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS = so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all