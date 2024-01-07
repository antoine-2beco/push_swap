# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:13:16 by ade-beco          #+#    #+#              #
#    Updated: 2024/01/07 15:43:30 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=		push_swap.a

LIBFT		=		libft.a

SRCS 		=		./push_swap.c

LIBFT_PATH	=		./libft/

OBJS		=		$(SRCS:.c=.o)

CC			=		cc -Wall -Wextra -Werror -g

LIBC		=		ar rcs

INC			=		-I ./includes/push_swap.h ./Libft/libft.h

all: 		$(NAME)

$(NAME): $(OBJECTS) $(LIBFT_PATH)
					@echo "Compiling ..."
					@make -C $(LIBFT_PATH) $(LIBFT)
					@cp $(LIBFT_PATH)$(LIBFT) .
					@mv $(LIBFT) $(NAME)
					@$(LIBC) $(NAME) $(OBJS)
					@echo "Compiling Done !"

$(OBJECTS): $(SRCS)
					@echo "Making Objects..."
					@$(CC) $(FLAGS) -c $(SRCS)
					@echo "Making Done..."

clean:
					@echo "Cleaning objects..."
					@rm -f $(OBJS)
					@echo "Cleaned up!"

fclean:		clean
					@echo "Cleaning..."
					@rm -f $(NAME)
					@echo "Cleaned up!"

re:			fclean all 
.PHONY:		all clean fclean re