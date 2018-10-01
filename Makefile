#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allallem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 18:42:15 by allallem          #+#    #+#              #
#    Updated: 2018/03/24 07:23:39 by allallem         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	lem_in

SRCS	=	main.c ft_parser.c ft_work_on_data.c ft_get_link.c ft_take_name.c ft_go_fourmis.c ft_throw_fourmis.c ft_look_for_next_room.c

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIB		=	-L libft -lft

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C libft
			make -C lem_in_visu
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			make -C lem_in_visu fclean
			make -C libft fclean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
