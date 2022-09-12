# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 13:30:39 by yoonsele          #+#    #+#              #
#    Updated: 2022/09/12 22:46:56 by yoonsele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c ft_functions.c ft_split.c ft_basecamp.c ft_validmap.c 
OBJS		= ${SRCS:.c=.o}

HEADER		= ft_bsq.h
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
