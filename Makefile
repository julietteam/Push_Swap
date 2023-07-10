# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 15:14:25 by juandrie          #+#    #+#              #
#    Updated: 2023/07/10 21:45:04 by julietteand      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c radix.c move.c utils.c 


OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = Libft

LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re
