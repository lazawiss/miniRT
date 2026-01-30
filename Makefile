# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 13:02:31 by mipang            #+#    #+#              #
#    Updated: 2026/01/27 21:25:16 by lzannis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -Iinclude -Iminilibx

SRCS_MATHS = \
			maths/utils_maths/utils_maths.c \
			maths/utils_maths/interval.c \
			maths/point.c \
			maths/ray_sphere.c \
			maths/ray_plane.c \
			maths/ray_cylinder.c \
			maths/ray_cylinder_utils.c \
			maths/ray_utils.c \
			maths/vector.c \
			maths/vector1.c 

SRCS_RENDERER = \
				render/exec.c \
				render/exec1.c \
				render/set_camera.c 
				
SRCS_WINDOW = \
		src/utils_src/atof.c \
		src/utils_src/time.c \
		src/close.c \
		src/window.c \
		src/key_hook.c \
	src/color.c \
	src/color_utils.c \
	src/color1.c \
	src/color2.c

		
SRC_PARSING_CORE = \
	parsing/core/parser.c \
	parsing/core/dispatch.c

SRC_PARSING_IDENTIFIERS = \
	parsing/parsers/parsers_identifier/parser_A.c \
	parsing/parsers/parsers_identifier/parser_C.c \
	parsing/parsers/parsers_identifier/parser_L.c \
	parsing/parsers/parsers_identifier/parser_SP.c \
	parsing/parsers/parsers_identifier/parser_PL.c \
	parsing/parsers/parsers_identifier/parser_CY.c

SRC_PARSING_VALUES = \
	parsing/parsers/parser_color.c \
	parsing/parsers/parser_vec3.c \
	parsing/parsers/parser_int.c \
	parsing/parsers/parser_double.c

SRC_SCENE = \
	parsing/scene/scene_add.c \
	parsing/scene/scene_init.c

SRC_UTILS = \
	parsing/utils/check_utils.c \
	parsing/utils/error_utils.c \
	parsing/utils/token_utils.c

SRC_MAIN = \
	src/main.c

SRCS = \
	$(SRC_PARSING_CORE) \
	$(SRC_PARSING_IDENTIFIERS) \
	$(SRC_PARSING_VALUES) \
	$(SRC_SCENE) \
	$(SRC_UTILS) \
	$(SRC_MAIN)
	
FILES = $(SRCS) $(SRCS_WINDOW) $(SRCS_RENDERER) $(SRCS_MATHS)
OBJS =$(FILES:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -lXext -lX11 -lm -lbsd

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

mlx:
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) mlx
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re
