# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpsyk <lpsyk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 16:29:33 by lpsyk             #+#    #+#              #
#    Updated: 2021/07/07 10:53:15 by lpsyk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS 		= \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c	\
ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c	\
ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c	\
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c	\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c	\
ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c

SRCS_BONUS	= \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c	\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

%.o: %.c libft.h
	$(CC) -c $(CC_FLAGS) $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus : $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	rm -f libft.o

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) libft.h

