# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 19:33:41 by yoonsele          #+#    #+#              #
#    Updated: 2022/09/14 20:35:46 by yoonsele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_new_main.c ft_validmap.c ft_func1.c ft_func2.c ft_split.c ft_strncpy.c ft_dp.c 
OBJS		= ${SRCS:.c=.o}

HEADER		= ft_bsq2.h
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
