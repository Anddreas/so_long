# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: handrias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 15:40:44 by handrias          #+#    #+#              #
#    Updated: 2023/02/01 16:08:22 by handrias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
MLX = mlx
# MLX_PATH = mlx/libmlx.a
CFLAGS = -Wall -Wextra -Werror  #-g -fsanitize=address -g 
LFLAGS = -L$(MLX) -lmlx -framework OpenGL -framework AppKit
SRCS =  main.c						\
		gnl/get_next_line.c			\
		gnl/get_next_line_utils.c	\
		map.c						\
		check1.c					\
		check2.c					\
		check3.c					\
		check4.c					\
		player_move.c				\
		player_move.1.c				\
		check_and_exit.c			\
		count_steps.c				\
		coins_and_lastcheck.c		\
		utils/ft_split.c			\
		utils/ft_strncmp.c			\
		utils/ft_strdup2.c			\
		utils/ft_strrchr.c			\
		utils/ft_strtrim.c			\
		utils/ft_itoa.c				\
		utils/ft_memcpy.c			\
		utils/ft_strjoin.c			\
		# utils/ft_atoi.c				\

SRCSB =	

OBJS        = $(SRCS:.c=.o)
OBJSBONUS   = $(SRCSB:.c=.o)

%.o : %.c Makefile
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	# $(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@	

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME) 

lib : 
	make -C libft

mlx :
	make -C $(MLX)

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft
	make clean -C mlx

clean:	
	rm -rf $(OBJS)
	rm -rf $(OBJSBONUS)
	make clean -C mlx

re: fclean all

.PHONY: all clean fclean re bonus lib mlx
#$(MLX_PATH)