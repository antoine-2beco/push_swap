# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:13:16 by ade-beco          #+#    #+#              #
#    Updated: 2024/02/19 11:50:20 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PUSH_SWAP	=		push_swap
CHECKER		=		checker

LIBFT		=		libft
LIBFT_PATH	=		./libft/

SRC_PATH	=		./src/
SRCS 		=		push_swap.c stacks_utils.c operations.c operations_shortcuts.c sort.c sort_utils.c sort_operations.c
SRCS_D 		=		$(SRC_PATH)push_swap.c $(SRC_PATH)stacks_utils.c $(SRC_PATH)operations.c $(SRC_PATH)operations_shortcuts.c $(SRC_PATH)sort.c $(SRC_PATH)sort_utils.c $(SRC_PATH)sort_operations.c

OBJECTS		=		$(SRCS_D:.c=.o)

INC			=		-I includes/$(NAME).h $(LIBFT_PATH)$(LIBFT).h

all: 		$(OBJECTS) $(PUSH_SWAP)

%.o:		%.c
					@cc -Wall -Wextra -Werror -c $(INC) $< -o $(<:c=o)

$(PUSH_SWAP): $(OBJECTS)
					@echo "Compiling Libft..."
					@make bonus -C $(LIBFT_PATH) $(LIBFT).a
					@echo "OK !"
					@cp $(LIBFT_PATH)$(LIBFT).a $(PUSH_SWAP)
					@echo "Creating Push_Swap Executable..."
					@ar -rcs $(PUSH_SWAP) $(OBJECTS)
					@cc $(PUSH_SWAP) -Wall -Wextra -Werror -o $(PUSH_SWAP)
					@echo "OK !"

#$(OBJECTS): $(SRCS_D)
#					@echo "Compiling Push_Swap..."
#					cc -Wall -Wextra -Werror -c $(INC) $(SRCS_D)
#					@echo "OK !"

clean:
					@make clean -C $(LIBFT_PATH)
					@echo "Cleaning Push_Swap Objects..."
					@rm -f $(OBJECTS)
					@echo "OK !"

fclean:		clean
					@make fclean -C $(LIBFT_PATH)
					@echo "Cleaning Push_Swap..."
					@rm -f $(PUSH_SWAP)
					@echo "OK !"

re:			fclean all 

.PHONY:		all clean fclean re