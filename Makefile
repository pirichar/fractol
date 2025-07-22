# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 11:00:22 by pirichar          #+#    #+#              #
#    Updated: 2025/07/21 18:05:00 by Gemini            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC			= src
INC			= include
OBJ			= obj
CFILES		= main.c print.c mandle.c julia.c clr_pallet.c keypress.c keypress2.c zoom.c\
			burning_ship.c mouse.c ft_strcmp.c ft_strjoin.c menu.c ft_itoa.c clr_rotation.c render.c
HFILES		= colors.h fractol.h keys.h
OFILES		= $(CFILES:.c=.o)
SRCS		= $(addprefix $(SRC)/, $(CFILES))
OBJS		= $(addprefix $(OBJ)/, $(OFILES))
HEADERS		= $(addprefix $(INC)/, $(HFILES))

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g -O3
LDFLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit -pthread
RM			= rm -rf

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -c $< -o  $@


$(NAME):	$(OBJ) $(OBJS)
			$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ):
			@mkdir -p $(OBJ)

all:		$(NAME)

clean:
			@$(RM) $(OBJS) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

norme:
			norminette $(SRCS) $(HEADERS)

	
