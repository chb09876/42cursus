NAME		=	libft.a
HEADER		=	libft.h
SRCS		=	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c
SRCS_BONUS	=	ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c
				
SRCS_ADDON	=	ft_split_free.c
SRCS_GNL	=	get_next_line.c \
				get_next_line_utils.c

CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs

.INTERMEDIATE : $(SRCS:.c=.o) $(SRCS_BONUS:.c=.o) $(SRCS_GNL:.c=.o) $(SRCS_ADDON:.c=.o)
.PHONY : bonus all clean fclean re

all : $(NAME)

$(NAME) : mandatory

mandatory : $(NAME)($(SRCS:.c=.o) $(SRCS_GNL:.c=.o) $(SRCS_ADDON:.c=.o))

bonus : $(NAME)($(SRCS:.c=.o) $(SRCS_BONUS:.c=.o) $(SRCS_GNL:.c=.o) $(SRCS_ADDON:.c=.o))

clean :
	rm -f $(SRCS:.c=.o) $(SRCS_BONUS:.c=.o) $(SRCS_GNL:.c=.o) $(SRCS_ADDON:.c=.o)

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

$(SRCS:.c=.o) $(SRCS_BONUS:.c=.o) $(SRCS_GNL:.c=.o) $(SRCS_ADDON:.c=.o): $(HEADER)
