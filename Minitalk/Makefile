# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:52:13 by schuah            #+#    #+#              #
#    Updated: 2023/03/01 14:14:02 by schuah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		=	server
CLIENT		=	client	
LIBFT		=	libft.a
CC			=	gcc
RM			=	rm -rf
MKDIR		=	mkdir -p
CFLAGS		=	-Wall -Wextra -Werror
SRCS_FILES	=	server client
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft
OBJS_DIR	=	objs/

all:			
				$(MKDIR) $(OBJS_DIR)
				make libft server client

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

server:			$(OBJS)
				$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SERVER))) -o $(SERVER)

client:			$(OBJS)
				$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(addprefix $(OBJS_DIR), $(addsuffix .o, $(CLIENT))) -o $(CLIENT)

libft:
				make -C $(LIBFT_DIR)

clean:
				$(RM) $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				make fclean -C $(LIBFT_DIR)
				$(RM) $(SERVER) $(CLIENT)

re:				fclean all

.PHONY:			all libft clean fclean re