# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:13:16 by ade-beco          #+#    #+#              #
#    Updated: 2024/01/17 17:03:23 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PUSH_SWAP	=		push_swap

LIBFT		=		libft
LIBFT_PATH	=		./libft/

SRC_PATH	=		./src/
SRCS 		=		push_swap.c stacks_utils.c sort_operations.c sort_shortcuts.c
SRCS_D 		=		$(SRC_PATH)push_swap.c $(SRC_PATH)stacks_utils.c $(SRC_PATH)sort_operations.c $(SRC_PATH)sort_shortcuts.c

OBJECTS		=		$(SRCS:.c=.o)

INC			=		-I includes/$(NAME).h $(LIBFT_PATH)$(LIBFT).h

all: 		$(PUSH_SWAP)

$(PUSH_SWAP): $(OBJECTS) $(LIBFT_PATH)
					@echo "Compiling Libft..."
					@make bonus -C $(LIBFT_PATH) $(LIBFT).a
					@echo "OK !"
					@cp $(LIBFT_PATH)$(LIBFT).a $(PUSH_SWAP).a
					@echo "Creating Push_Swap Executable..."
					@ar -rcs $(PUSH_SWAP).a $(OBJECTS)
					@echo "OK !"

$(OBJECTS): $(SRCS_D)
					@echo "Compiling Push_Swap..."
					@cc -Wall -Wextra -Werror -c $(INC) $(SRCS_D)
					@echo "OK !"

clean:
					@make clean -C $(LIBFT_PATH)
					@echo "Cleaning Push_Swap Objects..."
					@rm -f $(OBJECTS)
					@echo "OK !"

fclean:		clean
					@make fclean -C $(LIBFT_PATH)
					@echo "Cleaning Push_Swap..."
					@rm -f $(PUSH_SWAP).a
					@echo "OK !"

re:			fclean all 
.PHONY:		all clean fclean re