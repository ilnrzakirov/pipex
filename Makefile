# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 10:02:27 by bcarlee           #+#    #+#              #
#    Updated: 2021/12/15 10:02:29 by bcarlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	src/pipex.c			src/utils.c			src/error.c\
			src/pipex_func.c	src/ft_split.c		src/open_file.c\
			src/get_next_line.c

SRCS_B	= 	bonus/pipex_bonus.c src/get_next_line.c src/pipex_func.c\
			src/ft_split.c		src/utils.c			src/error.c\
			src/open_file.c

HEADER	=	includes/pipex.h

OBJS	=	$(SRCS:%.c=%.o)

OBJSB	=	$(SRCS_B:%.c=%.o)

CC		=	gcc

INC		=	-I includes 

CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

$(NAME)	:	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY	:	all clean fclean re

all		:	$(NAME)

bonus	:	$(OBJSB) $(HEADER)
	$(CC) $(CFLAGS) $(INC) $(OBJSB) -o $(NAME)

clean	:
	@rm -f $(OBJS) $(OBJSB)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all
