NAME		=	push_swap
SRCS		=	push_swap.c \
				stack.c \
				node.c \
				radix_sort.c \
				heap_sort.c \
				operation1.c \
				operation2.c \
				utils.c \
				ft_atoi.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs

.INTERMEDIATE : $(SRCS:.c=.o) $(SRCS_BONUS:.c=.o) $(SRCS_ADDITION:.c=.o)
.PHONY : bonus all clean fclean re
.NOTPARALLEL : notparallel

all : $(NAME)

$(NAME) : mandatory

mandatory : $(NAME)($(SRCS:.c=.o) $(SRCS_ADDITION:.c=.o))

bonus : $(NAME)($(SRCS:.c=.o) $(SRCS_BONUS:.c=.o) $(SRCS_ADDITION:.c=.o))

clean :
	rm -f $(SRCS:.c=.o) $(SRCS_BONUS:.c=.o) $(SRCS_ADDITION:.c=.o)

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

$(SRCS:.c=.o) $(SRCS_BONUS:.c=.o) $(SRCS_ADDITION:.c=.o): $(HEADER)
