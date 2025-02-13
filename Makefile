# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 16:24:14 by moben-ta          #+#    #+#              #
#    Updated: 2025/01/25 14:07:38 by moben-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
LIBFT = ./libft/libft.a
OBJS_FOLD = obj

SRCS = $(wildcard utils/*.c) push_swap.c
OBJS = $(SRCS:%.c=$(OBJS_FOLD)/%.o)

all: $(LIBFT) $(NAME)
	@echo "-- done! --"

$(LIBFT):
	$(MAKE) -C libft

$(OBJS_FOLD)/%.o:%.c push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) -C libft clean
	rm -rf $(OBJS_FOLD)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: clean