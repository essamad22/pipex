# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 17:40:21 by aakhtab           #+#    #+#              #
#    Updated: 2023/04/28 17:34:16 by aakhtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=====COLORS=====#
RESET	= \033[0m
GRAY		= \033[0;90m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
PURPLE		= \033[0;35m
S1			= "==========================================="
#================

CC			=	cc

SRCS			=	main.c exec.c pipex_tools.c

OBJS			=	$(SRCS:.c=.o)

CFLAGS			=	-Wall -Wextra -Werror 
#-g -fsanitize=address

NAME			=	pipex

LIBFT		= my_lib/libft.a


all:	${NAME}


${NAME}:	$(LIBFT) ${OBJS}
			@$(CC) $(CFLAGS) $(SRCS) lib/libft.a -o $(NAME)
			@printf "$(GREEN)======> DONE ✅\n$(RESET)"
			@printf "$(PURPLE)$(S1)||\n$(S1)||\n"
			@printf "$(PURPLE)                                           ||\n"
			@printf "    ██████╗ ██╗██████╗ ███████╗██╗  ██╗    ||\n"
			@printf "    ██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝    ||\n"
			@printf "    ██████╔╝██║██████╔╝█████╗   ╚███╔╝     ||\n"
			@printf "    ██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗     ||\n"
			@printf "    ██║     ██║██║     ███████╗██╔╝ ██╗    ||\n"
			@printf "    ╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝    ||\n"
			@printf "$(PURPLE)                                  FINISHED ||\n"
			@printf "$(S1)||\n$(S1)||$(RESET)\n"

$(LIBFT)	:
	@make -C lib

##---- need to modier----------
%.o	: %.c
	@${CC} ${CFLAGS} -c $< -o $@
##-----------------------------

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

