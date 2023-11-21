# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 08:56:02 by agiguair          #+#    #+#              #
#    Updated: 2023/11/21 07:44:58 by agiguair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Cub3D
CC				= cc
FLAG			= -Wall -Wextra -Werror -g3

#################################### Libft #####################################
LIBFT_PATH		= libs/libft/
LIBFT_FILE		= libft.a
MLX_FILE		= libmlx.a
LIBFT_LIB		= $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
################################### Minilibx ###################################
MLX_FLAG		= -lX11 -lXext
MLX_PATH		= libs/minilibx-linux/
MLX_LIB			= $(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX			= $(MLX_LIB) $(MLX_FLAG)
################################### Includes ###################################
INC_DIR			= includes/
#################################### Source ####################################
SRC_DIR			= sources/
SRC				= $(addprefix $(SRC_DIR), $(C_FILE))
C_FILE			= main.c\
				map_check01.c\
				map_check02.c\
				parsing.c\
				parsing_utils.c\
				parsing_utils2.c\
				event.c\
				free.c\
				player_init.c\
				raycasting.c\
				render.c\
				raycasting_utils.c\
				minimap.c\
				eventmove.c
#################################### Object ####################################
OBJ_PATH		= .obj/
OBJ				= $(SRC:.c=.o)
OBJ_DIR			= $(addprefix $(OBJ_PATH), $(OBJ))

#################################### Rules #####################################
all: lib mlx $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(FLAG) $(OBJ_DIR) $(LIBFT_LIB) $(MLX_EX) -lm -o $(NAME)


$(OBJ_PATH)%.o:%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

lib:
	@make -C $(LIBFT_PATH)

mlx:
	@make -C $(MLX_PATH)

clean:
	make clean -C $(MLX_PATH)
	make clean -C $(LIBFT_PATH)
	rm -fr $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re bonus lib mlx
