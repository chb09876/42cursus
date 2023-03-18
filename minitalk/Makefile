NAME := minitalk
CC := cc
CFLAGS := -Wextra -Wall -Werror -g
LIBFT := ./lib/libft

HEADERS := -I ./include -I $(LIBFT)
LIBS := -lft
LIBS_PATH := -L$(LIBFT)

SERVER_SRCS := src/server.c
SERVER_OBJS := $(SERVER_SRCS:.c=.o)
CLIENT_SRCS := src/client.c
CLIENT_OBJS := $(CLIENT_SRCS:.c=.o)

SERVER_SRCS_BONUS := src/server_bonus.c
SERVER_OBJS_BONUS := $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_SRCS_BONUS := src/client_bonus.c
CLIENT_OBJS_BONUS := $(CLIENT_SRCS_BONUS:.c=.o)

all : $(NAME)

libft :
	$(MAKE) -C $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME) : server client

server : libft $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) $(LIBS_PATH) $(LIBS) $(HEADERS) -o server

client : libft $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) $(LIBS_PATH) $(LIBS) $(HEADERS) -o client

bonus : server_bonus client_bonus

server_bonus : libft $(SERVER_OBJS_BONUS)
	$(CC) $(SERVER_OBJS_BONUS) $(LIBS_PATH) $(LIBS) $(HEADERS) -o server

client_bonus : libft $(CLIENT_OBJS_BONUS)
	$(CC) $(CLIENT_OBJS_BONUS) $(LIBS_PATH) $(LIBS) $(HEADERS) -o client

clean :
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	@$(MAKE) -C $(LIBFT) fclean

fclean : clean
	@rm -f server client

re : fclean all

.PHONY : all clean fclean re libft
.INTERMEDIATE : $(OBJS)