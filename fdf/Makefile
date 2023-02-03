NAME := fdf
CC := clang
CFLAGS := -Wextra -Wall -Werror -g
LIBMLX := ./lib/MLX42
LIBFT := ./lib/libft

HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LINUX_LIBS := -lft -lmlx42 -ldl -lglfw -pthread -lm
MAC_LIBS := -lft -lmlx42 -lglfw -framework Cocoa -framework OpenGL -framework IOKit 
LIBS_PATH := -L$(LIBFT) -L$(LIBMLX) -L "/Users/hacho/.brew/opt/glfw/lib/"
LIBS := $(MAC_LIBS)
SRCS := ./src/fdf.c ./src/bresenham.c ./src/draw.c ./src/util.c ./src/matrix.c ./src/map.c
OBJS := $(SRCS:.c=.o)

all : libmlx libft $(NAME)

libmlx :
	$(MAKE) -C $(LIBMLX)

libft :
	$(MAKE) -C $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(LIBS_PATH) $(LIBS) $(HEADERS) -o $(NAME)

clean :
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re libmlx
.INTERMEDIATE : $(OBJS)