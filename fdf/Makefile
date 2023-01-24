NAME := fdf
CC := clang
CFLAGS := -Wextra -Wall -Werror
LIBMLX := ./lib/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm
SRCS := ./src/fdf.c ./src/bresenham.c ./src/draw.c ./src/util.c
OBJS := $(SRCS:.c=.o)

all : libmlx $(NAME)

libmlx :
	$(MAKE) -C $(LIBMLX)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean :
	rm -f $(OBJS)
	$(MAKE) -C $(LIBMLX) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBMLX) fclean

re : clean all

.PHONY : all clean fclean re libmlx
.INTERMEDIATE : $(OBJS)