# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:13:16 by ade-beco          #+#    #+#              #
#    Updated: 2024/02/19 19:30:40 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PUSH_SWAP	=		push_swap
CHECKER		=		checker

LIBFT		=		libft
LIBFT_PATH	=		./libft/

SRC_PATH	=		./src/
SRCS		=		$(SRC_PATH)push_swap.c $(SRC_PATH)stacks_utils.c $(SRC_PATH)operations.c $(SRC_PATH)operations_shortcuts.c $(SRC_PATH)sort.c $(SRC_PATH)sort_utils.c $(SRC_PATH)sort_operations.c

B_SRCS 		=		$(SRC_PATH)checker_bonus.c $(SRC_PATH)stacks_utils.c $(SRC_PATH)operations.c $(SRC_PATH)operations_shortcuts.c $(SRC_PATH)sort_utils.c

OBJECTS		=		$(SRCS:.c=.o)
B_OBJECTS	=		$(B_SRCS:.c=.o)

INC			=		-I includes/$(PUSH_SWAP).h -I $(LIBFT_PATH)$(LIBFT).h
B_INC		=		-I includes/$(CHECKER)_bonus.h -I $(LIBFT_PATH)$(LIBFT).h


all: 			$(OBJECTS) $(PUSH_SWAP)

%.o:			%.c
					@gcc -Wall -Wextra -Werror -c $< -o $(<:c=o)

$(PUSH_SWAP):	$(OBJECTS)
					@echo "Compiling Libft..."
					@make bonus -C $(LIBFT_PATH) $(LIBFT).a
					@cp $(LIBFT_PATH)$(LIBFT).a $(PUSH_SWAP)
					@echo "OK !"
					@echo "Compiling and Creating Push_Swap..."
					@ar -rcs $(PUSH_SWAP) $(OBJECTS)
					@gcc $(PUSH_SWAP) -Wall -Wextra -Werror $(INC) -o $(PUSH_SWAP)
					@echo "OK !"

clean:
					@make clean -C $(LIBFT_PATH)
					@echo "Cleaning Push_Swap Objects..."
					@rm -f $(OBJECTS)
					@echo "OK !"
					@echo "Cleaning Checker Objects..."
					@rm -f $(B_OBJECTS)
					@echo "OK !"

fclean:			clean
					@make fclean -C $(LIBFT_PATH)
					@echo "Cleaning Push_Swap..."
					@rm -f $(PUSH_SWAP)
					@echo "OK !"
					@echo "Cleaning Checker..."
					@rm -f $(CHECKER)
					@echo "OK !"

bonus:			$(B_OBJECTS) $(CHECKER)

$(CHECKER):		$(B_OBJECTS)
					@echo "Compiling Libft..."
					@make bonus -C $(LIBFT_PATH) $(LIBFT).a
					@cp $(LIBFT_PATH)$(LIBFT).a $(CHECKER)
					@echo "OK !"
					@echo "Compiling and Creating Checker..."
					@ar -rcs $(CHECKER) $(B_OBJECTS)
					gcc $(CHECKER) -Wall -Wextra -Werror $(B_INC) -o $(CHECKER)
					@echo "OK !"

re:				fclean all 

.PHONY:			all clean fclean re bonus