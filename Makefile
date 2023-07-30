SERVER_SRCS = server.c 
CLIENT_SRCS = client.c
SERVER_BONUS_SRCS = server_bonus.c 
CLIENT_BONUS_SRCS = client_bonus.c
FT_PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a
NAME = server_client

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

$(NAME): all

all: server client

server: $(SERVER_OBJS) $(FT_PRINTF) $(LIBFT)
	gcc -o server $(SERVER_OBJS) $(FT_PRINTF) $(LIBFT)

client: $(CLIENT_OBJS) $(FT_PRINTF) $(LIBFT)
	gcc -o client $(CLIENT_OBJS) $(FT_PRINTF) $(LIBFT)

$(FT_PRINTF):
	make -C ft_printf

$(LIBFT):
	make -C libft

bonus: server_bonus client_bonus

server_bonus: $(SERVER_BONUS_OBJS) $(FT_PRINTF) $(LIBFT)
	gcc -o server_bonus $(SERVER_BONUS_OBJS) $(FT_PRINTF) $(LIBFT)

client_bonus: $(CLIENT_BONUS_OBJS) $(FT_PRINTF) $(LIBFT)
	gcc -o client_bonus $(CLIENT_BONUS_OBJS) $(FT_PRINTF) $(LIBFT)

clean:
	rm -rf *.o
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -rf server
	rm -rf client
	rm -rf server_bonus
	rm -rf client_bonus
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re bonus
