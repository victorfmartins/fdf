# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 15:48:25 by vfranco-          #+#    #+#              #
#    Updated: 2022/05/23 02:42:17 by vfranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang
FILES_PATH	=	.
FILES 		=	gnl_main.c \
				fdf_core.c
OBJS_PATH	=	objs
OBJS 		=	$(addprefix $(OBJS_PATH)/,$(notdir $(FILES:.c=.o)))
FLAGS 		= 	-Wall -Wextra -Werror
LIBRARIES	= 	-lbsd -lmlx -lXext -lX11 -lm
LIBFT_PATH	= 	.dependencies/libft
LIBFT		=	$(LIBFT_PATH)/libft.a
GNL_PATH	= 	.dependencies/gnl
GNL 		= 	$(GNL_PATH)/libgnl.a
NAME 		=	fdf
RM 			=	rm -f
# MINILIBX	= 	$(shell ls .dependencies/minilibx-linux/)

###################################################################

##all:		$(OBJS_PATH) $(NAME)

all: $(OBJS_PATH) $(NAME)
	
$(OBJS_PATH):
				mkdir -p $(OBJS_PATH)

$(NAME):	$(OBJS) $(LIBFT) $(GNL)
				$(CC) $(FLAGS) $(OBJS) $(LIBRARIES) $(LIBFT) $(GNL) -o fdf

$(OBJS_PATH)/%.o:	$(FILES_PATH)/%.c
				$(CC) -c $(FLAGS) $< -o $(addsuffix .o, $(OBJS_PATH)/$(basename $(@F)))

$(LIBFT):
				make -C $(LIBFT_PATH)

$(GNL):
				make -C $(GNL_PATH)
				
clean:
				$(RM) $(OBJS)

fclean:		clean
				make fclean -C $(LIBFT_PATH)
				make fclean -C $(GNL_PATH)
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re $(LIBFT) $(GNL) 