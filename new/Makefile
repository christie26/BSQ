# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 19:33:41 by yoonsele          #+#    #+#              #
#    Updated: 2022/09/14 21:01:55 by yoonsele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/ft_main.c srcs/ft_validmap.c srcs/ft_func1.c srcs/ft_func2.c srcs/ft_split.c srcs/ft_strncpy.c srcs/ft_dp.c 
OBJS		= ${SRCS:.c=.o}

HEADER		= include/ft_bsq.h
NAME		= bsq

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all:		${NAME}

$(NAME):
			${CC} ${CFLAGS} ${SRCS} -o ${NAME} -include ${HEADER}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
