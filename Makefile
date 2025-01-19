# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riyano <riyano@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 17:58:42 by riyano            #+#    #+#              #
#    Updated: 2025/01/19 13:11:02 by riyano           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
NAME = $(SERVER) $(CLIENT)

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
NAME_BONUS = $(SERVER_BONUS) $(CLIENT_BONUS)

SRCS = server.c client.c utils.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = server_bonus.c client_bonus.c utils_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

RM = rm -f

all: $(NAME)

$(SERVER): server.o utils.o
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIBFT_DIR) -lft

$(CLIENT): client.o utils.o
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIBFT_DIR) -lft

bonus: $(NAME_BONUS)

$(SERVER_BONUS): server_bonus.o utils_bonus.o
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIBFT_DIR) -lft

$(CLIENT_BONUS): client_bonus.o utils_bonus.o
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAG) $^ -o $@ -L$(LIBFT_DIR) -lft

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS) $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re
