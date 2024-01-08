# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:13:16 by ade-beco          #+#    #+#              #
#    Updated: 2024/01/08 16:17:20 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=		push_swap.a

LIBFT		=		libft.a

SRC_PATH	=		./src/
SRCS 		=		push_swap.c
SRCS_D 		=		$(SRC_PATH)push_swap.c

LIBFT_PATH	=		./libft/

OBJECTS		=		$(SRCS:.c=.o)

INC			=		-I .includes/push_swap.h ./libft/libft.h

all: 		$(NAME)

$(NAME): $(OBJECTS) $(LIBFT_PATH)
					@echo "Compiling Libft..."
					@make bonus -C $(LIBFT_PATH) $(LIBFT)
					@echo "OK !"
					@cp $(LIBFT_PATH)$(LIBFT) $(NAME)
					@echo "Creating Push_Swap Executable..."
					@ar -rcs $(NAME) $(OBJECTS)
					@echo "OK !"

$(OBJECTS): $(SRCS_D)
					@echo "Compiling Push_Swap..."
					@clang -Wall -Wextra -Werror -c $(SRCS_D)
					@echo "OK !"

clean:
					@make clean -C $(LIBFT_PATH)
					@echo "Cleaning Push_Swap Objects..."
					@rm -f $(OBJECTS)
					@echo "OK !"

fclean:		clean
					@make fclean -C $(LIBFT_PATH)
					@echo "Cleaning Push_Swap..."
					@rm -f $(NAME)
					@echo "OK !"

re:			fclean all 
.PHONY:		all clean fclean re