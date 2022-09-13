# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 13:30:39 by yoonsele          #+#    #+#              #
#    Updated: 2022/09/13 23:33:23 by yoonsele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_main.c ft_func1.c ft_func2.c ft_basecamp.c ft_dp.c ft_strcpy.c ft_common.c
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
