
# CC = cc
# CFLAG = -Wall -Wextra -Werror

# NAME = 
# SERVER = server
# CLIENT = client
# SRCS = 	server.c			\
# 		client.c			\
# 		minitalk_utils.c	

# OBJS= $(SRCS:.c=.o)

# %.o : %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# all: $(SERVER) $(CLIENT)

# $(NAME): all

# $(SERVER): $(OBJS)
# 	$(CC) $(CFLAG) -o $(SERVER)

# $(CLIENT): $(OBJS)
# 	$(CC) $(CFLAG) -o $(CLIENT)

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(SERVER) $(CLIENT)

# re: fclean all

# .PHONY: all clean fclean re

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
