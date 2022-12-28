NAME		=	push_swap
SRCS		=	push_swap.c \
				stack.c \
				node.c \
				radix_sort.c \
				heap_sort.c \
				hard_sort.c \
				operation1.c \
				operation2.c \
				utils.c \
				ft_atoi.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs

.INTERMEDIATE : $(SRCS:.c=.o)
.PHONY : all clean fclean re
.NOTPARALLEL : notparallel

all : $(NAME)

$(NAME) : $(SRCS:.c=.o)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS:.c=.o)

clean :
	rm -f $(SRCS:.c=.o)

fclean : clean
	rm -f $(NAME)

re : fclean
	make all
