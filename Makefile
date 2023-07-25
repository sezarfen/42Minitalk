SERVER_SRCS = server.c 
CLIENT_SRCS = client.c
UTILS_SRCS = utils.c   # It could be deleted
FT_PRINTF = libftprintf.a

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
UTILS_OBJS = $(UTILS_SRCS:.c=.o)

all: server client

server: $(SERVER_OBJS) $(UTILS_OBJS)
	gcc -o server $(SERVER_OBJS) $(FT_PRINTF) $(UTILS_OBJS)

client: $(CLIENT_OBJS) $(UTILS_OBJS)
	gcc -o client $(CLIENT_SRCS) $(FT_PRINTF) $(UTILS_OBJS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf server
	rm -rf client

re: fclean all

.PHONY: all server client clean fclean re