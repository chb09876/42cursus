CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
AR = ar
ARFLAGS = crs
VPATH = conversion:libft

LIBFT		=	libft.a
LIBFT_DIR	=	libft
NAME		=	libftprintf.a
SRCS		=	ft_printf.c \
				ft_printf_conversion.c \
				ft_printf_options.c \
				ft_printf_print.c \
				convert_character.c \
				convert_decimal.c \
				convert_hex.c \
				convert_integer.c \
				convert_percent.c \
				convert_pointer.c \
				convert_string.c \
				convert_unsigned_int.c

.PHONY : all bonus clean fclean re conversion $(LIBFT) $(LIBFT_DIR)

all : $(NAME)

$(NAME) : mandatory

mandatory : $(NAME)($(SRCS:.c=.o))

bonus : $(NAME)($(SRCS:.c=.o) $(SRCS_BONUS:.c=.o))

$(NAME)($(SRCS:.c=.o)) $(NAME)($(SRCS:.c=.o) $(SRCS_BONUS:.c=.o)) : $(LIBFT)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

clean :
	rm -f $(SRCS:.c=.o) $(SRCS_BONUS:.c=.o)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all
