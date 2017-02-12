# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/22 09:46:05 by aiwanesk          #+#    #+#              #
#    Updated: 2015/09/23 15:09:14 by aiwanesk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, $(LIBFT_PATH)$(LIBFT_NAME)

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH ?= ./libft/
LIBFT_NAME = libft.a

SRC_PATH = ./srcs/

SRC_NAME = ft_printf.c			\
		   flag.c				\
		   c_conv.c\
		   maj_s_conv.c		\
		   b_conv.c\
		   id_conv.c\
		   n_conv.c\
		   o_conv.c\
		   p_conv.c\
		   s_conv.c\
		   u_conv.c\
		   x_conv.c\
		   handle_arg.c			\
		   flag_handle.c		\
		   handle_wild_str.c			\
		   tools.c				\
		   handle_utils_prec.c	\
		   apply_modifier.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

INCLUDES = $(LIBFT_PATH)includes ./includes/

INC_CC = $(foreach DIR,$(INCLUDES),-I$(DIR) )
CFLAGS += $(INC_CC)


# ----------------------------------------------------------------------------
# MISC |
# ----------------------------------------------------------------------------
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@echo -n .
	@$(CC) $(CFLAGS) -o $@ -c $<


# ----------------------------------------------------------------------------
# RULES |
# ----------------------------------------------------------------------------
all: $(LIBFT_PATH)$(LIBFT_NAME) $(NAME)

bin:
	gcc main.c $(INC_CC) -L./ $(NAME) -lftprintf

$(LIBFT_PATH)$(LIBFT_NAME):
	@$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJ)
	@cp $(LIBFT_PATH)$(LIBFT_NAME) $(NAME)
	@$(AR) rcs $(NAME) $^
	@echo ""
	@echo "[\033[32m$(NAME) done\033[0m]"
	
clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all
