LIBFT		=	libft.a
LIBFT_DIR	=	libft
NAME		=	libftprintf.a
SRCS		=	ft_printf.c \
				character.c \
				decimal.c \
				hex_lower.c \
				hex_upper.c \
				integer.c \
				percent.c \
				pointer.c \
				string.c \
				unsigned_int.c
VPATH = mandatory:mandatory/conversion

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -Imandatory/headers
AR = ar
ARFLAGS = crs

.INTERMEDIATE : $(SRCS:.c=.o) $(LIBFT) mandatory_target
.DEFAULT : all
.PHONY : all bonus clean fclean re

all : $(NAME)

$(NAME) : mandatory_target

mandatory_target : $(SRCS:.c=.o) $(LIBFT)
	$(AR) $(ARFLAGS) $(LIBFT) $(SRCS:.c=.o)
	mv $(LIBFT) $(NAME)

$(LIBFT) :
	$(MAKE) -C$(LIBFT_DIR)
	mv $(LIBFT_DIR)/$(LIBFT) ./

clean :
	rm -f $(SRCS:.c=.o) $(LIBFT)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all

ft_printf.o : headers/ft_printf.h
character.o decimal.o  hex_lower.o  hex_upper.o  integer.o  percent.o  pointer.o  string.o  unsigned_int.o : headers/conversion.h
