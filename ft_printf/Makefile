CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -Iconversion -I./
AR = ar
ARFLAGS = crs
VPATH = conversion:libft

LIBFT		=	libft.a
LIBFT_DIR	=	libft
NAME		=	libftprintf.a
SRCS		=	ft_printf.c \
				options.c \
				utils.c \
				character.c \
				decimal.c \
				hex_lower.c \
				hex_upper.c \
				integer.c \
				percent.c \
				pointer.c \
				string.c \
				unsigned_int.c

.PHONY : all bonus clean fclean re conversion

all : $(NAME)

$(NAME) : mandatory

mandatory : $(SRCS:.c=.o) $(LIBFT)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(SRCS:.c=.o)
	touch mandatory

bonus : $(NAME)($(SRCS:.c=.o) $(SRCS_BONUS:.c=.o))

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

clean :
	rm -f $(SRCS:.c=.o) $(SRCS_BONUS:.c=.o)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all
