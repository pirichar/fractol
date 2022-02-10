# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 11:00:22 by pirichar          #+#    #+#              #
#    Updated: 2022/02/10 16:34:57 by pirichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# LIBFT		= ft
# LIBFTDIR	= libft
# MAKELIBFT	= @$(MAKE) -C $(LIBFTDIR)

SRC			= src
INC			= include
OBJ			= obj
CFILES		= main.c print.c mandle.c
HFILES		= colors.h fractol.h keys.h
OFILES		= $(CFILES:.c=.o)
SRCS		= $(addprefix $(SRC)/, $(CFILES))
OBJS		= $(addprefix $(OBJ)/, $(OFILES))
HEADERS		= $(addprefix $(INC)/, $(HFILES))

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -rf

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -c $< -o $@


$(NAME):	$(OBJ) $(OBJS)
			$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

$(OBJ):
			@mkdir -p $(OBJ)

all:		$(NAME)

clean:
			@$(RM) $(OBJS) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

norme:
			$(MAKELIBFT) norme
			norminette $(SRCS) $(HEADERS)

	
