# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riyano <riyano@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 17:58:42 by riyano            #+#    #+#              #
#    Updated: 2025/01/17 19:34:22 by riyano           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft

$(CLIENT): $(OBJS_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft

#bonus: $(OBJS) $(BOBJS)
#	ar rcs $(NAME) $(OBJS) $(BOBJS)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
