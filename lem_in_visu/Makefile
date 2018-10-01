#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allallem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 18:42:15 by allallem          #+#    #+#              #
#    Updated: 2018/03/24 07:23:26 by allallem         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	visu

SRCS	=	main.c ft_parser.c ft_work_on_data.c ft_get_link.c ft_take_name.c ft_trace_seg.c ft_generate_first.c ft_put_circle.c ft_game.c ft_go_fm.c ft_trace_fm.c ft_trace_fm_direction.c ft_make_cube.c ft_take_it.c

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBX	=	-L minilibx_macos -lmlx -framework OpenGL -framework appkit

LIB		=	-L ../libft -lft

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C minilibx_macos
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBX) $(LIB)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			make -C minilibx_macos clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
