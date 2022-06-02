# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 15:55:20 by vfranco-          #+#    #+#              #
#    Updated: 2022/03/27 17:13:28 by vfranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang
FILES 		=	get_next_line_utils.c get_next_line.c
OBJS 		=	$(FILES:.c=.o)
FLAGS 		=	-Wall -Wextra -Werror
NAME 		=	libgnl.a
RM 			=	rm -f

###################################################################

all:		$(NAME)
				
$(NAME):	$(OBJS)
				ar rc $(NAME) $(OBJS)

%.o:		%.c 
				$(CC) -c $(FLAGS) $<

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re