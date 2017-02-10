# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/22 09:46:33 by aiwanesk          #+#    #+#              #
#    Updated: 2015/09/22 10:40:32 by aiwanesk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = libft.a

CC = gcc
CFLAGS += -Wall -Werror -Wextra

SRC_PATH = ./src/

SRC_NAME =	ft_lstiter.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstnew.c\
			ft_itoa.c\
			ft_intlen.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isnumber.c\
			ft_isprint.c\
			ft_strequ.c\
			ft_strnequ.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_strcpy.c\
			ft_strncpy.c\
			ft_strcat.c\
			ft_strncat.c\
			ft_strlcat.c\
			ft_strnew.c\
			ft_strdup.c\
			ft_strdel.c\
			ft_strclr.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putendl.c\
			ft_putnbr.c\
			ft_putnbr_base.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putnchar.c\
			ft_putnstr.c\
			ft_putnbr_separator.c\
			ft_atoi.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_strrev.c\
			ft_strsub.c\
			ft_strjoin.c\
			ft_strsplit.c\
			ft_strlen.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strnlen.c\
			ft_strstr.c\
			ft_strnstr.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strtrim.c\
			ft_memcmp.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_memalloc.c\
			ft_memdel.c\
			ft_memchr.c\
			ft_nlen.c\

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC_PATH = ./includes/
INC = $(addprefix -I,$(INC_PATH))


all: $(NAME)
	
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ""
	@echo -e "\033[32m[$(NAME) done]\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@echo -n .
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
