# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:52:13 by schuah            #+#    #+#              #
#    Updated: 2023/02/24 12:25:04 by schuah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		=	server
CLIENT		=	client
LIBFT		=	libft.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		+=	-fsanitize=address -g3
SRCS_FILES	=	server \
				client
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft
OBJS_DIR	=	objs/

all:			
				mkdir -p $(OBJS_DIR)
				make libft server client

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

server:			$(OBJS)
				$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) objs/$(SERVER).o -o $(SERVER)

client:			$(OBJS)
				$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) objs/$(CLIENT).o -o $(CLIENT)

bonus:			all

libft:
				make -C $(LIBFT_DIR)

clean:
				rm -rf $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				make fclean -C $(LIBFT_DIR)
				rm -rf $(SERVER) $(CLIENT)

re:				fclean all

.PHONY:			all server client bonus libft clean fclean re