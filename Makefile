# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 15:44:16 by jaehpark          #+#    #+#              #
#    Updated: 2021/06/27 16:58:06 by jaehpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

NAME_B		= checker

CC			= gcc
CFLAGS		= -g3 -fsanitize=address -Wall -Wextra -Werror

INCS		= -Ilibft -I.

SRCS_DIR	= ./srcs
SRCS_NAME	= push_swap.c \
				utils.c \
				init.c \
				operation_a.c \
				operation_b.c \
				operation_ab.c \
				sort.c \
				sort_utils.c \
				pivot_sort.c

SRCS_B_DIR	= ./srcs_b
SRCS_B_NAME	= checker.c \
				utils.c \
				init.c \
				operation_a.c \
				operation_b.c \
				operation_ab.c \
				sort_utils.c

SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))

SRCS_B		= $(addprefix $(SRCS_B_DIR)/, $(SRCS_B_NAME))

OBJS_DIR	= ./objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS_NAME:.c=.o))

OBJS_B_DIR	= ./objs_b
OBJS_B		= $(addprefix $(OBJS_B_DIR)/, $(SRCS_B_NAME:.c=.o))

LIB_DIR		= libft
LIB_NAME	= ft
LIB			= $(addprefix $(LIB_DIR)/, libft.a)

$(NAME)		: $(LIB) $(OBJS)
		$(CC) $(CFLAGS) $(INCS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJS) -o $@

$(NAME_B)	: $(LIB) $(OBJS_B)
		$(CC) $(CFLAGS) $(INCS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJS_B) -o $@

$(LIB)		:
		$(MAKE) -C $(LIB_DIR) bonus

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJS_B_DIR)/%.o : $(SRCS_B_DIR)/%.c
	mkdir -p $(OBJS_B_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all 	: $(NAME)

bonus	: $(NAME_B)

clean	:
		$(MAKE) -C $(LIB_DIR) clean
		rm -rf $(OBJS_DIR) $(OBJS_B_DIR)

fclean	:
		$(MAKE) -C $(LIB_DIR) fclean
		rm -rf $(NAME) $(OBJS_DIR) $(NAME_B) $(OBJS_B_DIR)

re		: fclean all

.PHONY	: all clean fclean re bonus
