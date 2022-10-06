CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a
SRCS	=	ft_printf.c \
			ft_printf_conversion.c \
			ft_printf_flags.c \
			ft_printf_ordinary.c \
			ft_atoi.c \
			conversion/ft_printf_character.c \
			conversion/ft_printf_decimal.c \
			conversion/ft_printf_hex.c \
			conversion/ft_printf_integer.c \
			conversion/ft_printf_percent.c \
			conversion/ft_printf_pointer.c \
			conversion/ft_printf_string.c \
			conversion/ft_printf_unsigned_int.c
OBJS	=	$(SRCS:.c=.o)
ARCHIVE	=	ar -crs

.PHONY	:	all clean fclean re	

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(ARCHIVE) $(NAME) $(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean
			make all

