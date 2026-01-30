# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipang <mipang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 21:12:34 by mipang            #+#    #+#              #
#    Updated: 2025/02/28 23:47:02 by mipang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = src
SRC_FILES = src/ft_atoi.c \
	src/ft_bzero.c \
	src/ft_calloc.c \
	src/ft_isalnum.c \
	src/ft_isalpha.c \
	src/ft_isascii.c \
	src/ft_isdigit.c \
	src/ft_isprint.c \
	src/ft_itoa.c \
	src/ft_lstadd_back_bonus.c \
	src/ft_lstadd_front_bonus.c \
	src/ft_lstclear_bonus.c \
	src/ft_lstdelone_bonus.c \
	src/ft_lstiter_bonus.c \
	src/ft_lstlast_bonus.c \
	src/ft_lstmap_bonus.c \
	src/ft_lstnew_bonus.c \
	src/ft_lstsize_bonus.c \
	src/ft_memchr.c \
	src/ft_memcmp.c \
	src/ft_memcpy.c \
	src/ft_memmove.c \
	src/ft_memset.c \
	src/ft_putchar_fd.c \
	src/ft_putendl_fd.c \
	src/ft_putnbr_fd.c \
	src/ft_putstr_fd.c \
	src/ft_split.c \
	src/ft_strchr.c \
	src/ft_strdup.c \
	src/ft_striteri.c \
	src/ft_strjoin.c \
	src/ft_strlcat.c \
	src/ft_strlcpy.c \
	src/ft_strlen.c \
	src/ft_strmapi.c \
	src/ft_strncmp.c \
	src/ft_strnstr.c \
	src/ft_strrchr.c \
	src/ft_strtrim.c \
	src/ft_substr.c \
	src/ft_tolower.c \
	src/ft_toupper.c \
	src/get_next_line/get_next_line.c \
	src/get_next_line/get_next_line_utils.c \
	src/ft_printf/ft_printf.c \
	src/ft_printf/ft_pf_handle_hex_generic.c \
	src/ft_printf/ft_pf_handle_int.c \
	src/ft_printf/ft_pf_handle_pointer.c \
	src/ft_printf/ft_pf_handle_str.c \
	src/ft_printf/ft_pf_handle_unsigned_int.c \
	src/ft_printf/ft_printf_format.c \
	src/ft_printf/num_to_hex.c 

OBJS_DIR = objs
OBJS = $(patsubst $(SRC)/%.c,$(OBJS_DIR)/%.o,$(SRC_FILES))

BONUS_SRCS = src/ft_lstadd_back_bonus.c \
	src/ft_lstadd_front_bonus.c \
	src/ft_lstclear_bonus.c \
	src/ft_lstdelone_bonus.c \
	src/ft_lstiter_bonus.c \
	src/ft_lstlast_bonus.c \
	src/ft_lstmap_bonus.c \
	src/ft_lstnew_bonus.c \
	src/ft_lstsize_bonus.c
BONUS_OBJS = $(patsubst $(SRC)/%.c,$(OBJS_DIR)/%.o,$(BONUS_SRCS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I$(SRC)/get_next_line -I$(SRC)/ft_printf -I$(SRC)/ft_printf/includes

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
