NAME	=	libftprintf.a
CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	ft_printf.c \
			ft_printf_conversion.c \
			ft_printf_options.c \
			ft_printf_print.c \
			conversion/ft_printf_character.c \
			conversion/ft_printf_decimal.c \
			conversion/ft_printf_hex.c \
			conversion/ft_printf_integer.c \
			conversion/ft_printf_percent.c \
			conversion/ft_printf_pointer.c \
			conversion/ft_printf_string.c \
			conversion/ft_printf_unsigned_int.c
OBJS	=	$(SRCS:.c=.o)
AR		=	ar
ARFLAGS =	crs

.PHONY	:	all clean fclean re	

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean
			make all

