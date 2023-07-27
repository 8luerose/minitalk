CC = cc
CFLAG = -Wall -Wextra -Werror

NAME = minitalk
SERVER = server
CLIENT = client

SRCS_SERVER = server.c minitalk_utils.c
SRCS_CLIENT = client.c minitalk_utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAG) -o $(SERVER) $(OBJS_SERVER)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAG) -o $(CLIENT) $(OBJS_CLIENT)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
