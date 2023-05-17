# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrami <mrami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 02:09:36 by mrami             #+#    #+#              #
#    Updated: 2023/05/15 18:50:41 by mrami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
cc = cc
HEADER = fdf.h
CFlags = -Wall -Wextra -Werror
MLx_Frime = -lmlx -framework OpenGL -framework AppKit
CFiles = fdf.c get_next_line.c get_next_line_utils.c fdf_helper.c ft_split.c ft_draw.c
OFiles = $(CFiles:.c=.o)
# -----------------------------------
all: $(NAME)

$(NAME): $(OFiles)
		$(cc) $(CFlags) $(MLx_Frime) $(CFiles) -o $(NAME)
%.c: %.o $(HEADER)
	$(cc) $(CFlags) -c $<
# ------------------------------------
clean:
		rm -rf $(OFiles)
fclean: clean
		rm -rf $(NAME)
# ------------------------------------
re: fclean all
# -----------------------------------
.PHONY: all clean fclean re