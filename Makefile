# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pminialg <pminialg@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/10 11:33:32 by pminialg      #+#    #+#                  #
#    Updated: 2024/01/11 11:45:15 by pminialg      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

all:
	@$(MAKE) -C ./libft all
	@printf "$(PURPLE).o files created in ./libft\n$(RESET)"
	@cc -Wall -Wextra -Werror src/server.c libft/libft.a -o server
	@printf "$(GREEN)server ready\n$(RESET)"
	@cc -Wall -Wextra -Werror src/client.c libft/libft.a -o client
	@printf "$(GREEN)client ready\n$(RESET)"

clean:
	@$(MAKE) -C ./libft clean
	@printf "$(PURPLE)All .o files removed from ./libft\n$(RESET)"
	@rm -f server
	@printf "$(RED)server removed\n$(RESET)"
	@rm -f client
	@printf "$(RED)client removed\n$(RESET)"

fclean: clean
	@$(MAKE) -C ./libft fclean

re:
	@$(MAKE) fclean
	@$(MAKE) all

bonus: fclean
	@$(MAKE) -C ./libft all
	@printf "$(PURPLE).o files created in ./libft\n$(RESET)"
	@cc -Wall -Wextra -Werror src_bonus/server_bonus.c libft/libft.a -o server
	@printf "$(GREEN)server for bonus ready\n$(RESET)"
	@cc -Wall -Wextra -Werror src_bonus/client_bonus.c libft/libft.a -o client
	@printf "$(GREEN)client for bonus ready\n$(RESET)"

#Colors:
RED 		=	\e[1;31m
GREEN		=	\e[1;32m
PURPLE		= 	\e[1;35m
RESET		=	\e[0m

.PHONY: all clean fclean re bonus
