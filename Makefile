# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:13:16 by ade-beco          #+#    #+#              #
#    Updated: 2024/01/08 11:38:22 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=		push_swap.a

LIBFT		=		libft.a

SRCS 		=		push_swap.c

LIBFT_PATH	=		./libft/

OBJECTS		=		$(SRCS:.c=.o)

INC			=		-I ./push_swap.h ./libft/libft.h

all: 		$(NAME)

$(NAME): $(OBJECTS) $(LIBFT_PATH)
					@echo "Compiling Libft..."
					@make -C $(LIBFT_PATH) $(LIBFT)
					@echo "Compiling Libft Done !"
					@make clean -C $(LIBFT_PATH)
					@cp $(LIBFT_PATH)$(LIBFT) $(NAME)
					@echo "Creating Push_Swap Executable..."
					@ar -rcs $(NAME) $(OBJECTS)
					@echo "Push_Swap Executable Done !"

$(OBJECTS): $(SRCS)
					@echo "Compiling Push_Swap..."
					@clang -Wall -Wextra -Werror -c $(SRCS)
					@echo "Compiling Push_Swap Done !"

clean:
					@echo "Cleaning Push_Swap Objects..."
					@rm -f $(OBJECTS)
					@echo "Cleaned Push_Swap up !"

fclean:		clean
					@echo "Cleaning Push_Swap..."
					@rm -f $(NAME)
					@echo "Cleaned Push_Swap up !"

re:			fclean all 
.PHONY:		all clean fclean re