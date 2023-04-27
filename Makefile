# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 17:40:21 by aakhtab           #+#    #+#              #
#    Updated: 2023/04/28 00:44:46 by aakhtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=====COLORS=====#
RESET	= \033[0m
GRAY		= \033[0;90m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
#================

CC			=	cc

SRCS			=	main.c exec.c pipex_tools.c

OBJS			=	$(SRCS:.c=.o)

CFLAGS			=	-Wall -Wextra -Werror

NAME			=	pipex

LIBFT		= my_lib/libft.a


all:	${NAME}


${NAME}:	$(LIBFT) ${OBJS}
			@$(CC) $(CFLAGS) $(SRCS) lib/libft.a -o $(NAME)
			@printf "$(GREEN)\r======> DONE ✅\n$(RESET)"

$(LIBFT)	:
	@make -C lib

${OBJS}:
			@${CC} ${CFLAGS} -c ${SRCS}

clean:	
			@make clean -C lib
			@rm -f $(OBJS)
			@printf "$(YELLOW)\r    [OBJECTS CLEANED 🗑️$(RESET)"

fclean:	clean
			@make fclean -C lib
			@rm -f ${NAME}
			@printf "\r												"
			@printf "$(RED)\r     [EVERYTHING CLEANED 👌]    \n$(RESET)"
			
re:	fclean all

.PHONY: all clean fclean re

