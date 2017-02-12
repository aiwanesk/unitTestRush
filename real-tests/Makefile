NAME = tests_libft

HDIR = ./includes/
SDIR = ./ft_atoi/
SDIR2= ./ft_strlen/
ODIR = ./objects/

SRC =	$(SDIR)00_ft_atoi_launcher.c\
		$(SDIR)01_basic_test.c\
		$(SDIR)02_neg_test.c\
		$(SDIR)03_emptystring_test.c\
		$(SDIR)04_intmin_test.c\
		$(SDIR)05_intmax_test.c\
		$(SDIR)06_overflow_test.c\
		$(SDIR)07_zero_test.c\
		$(SDIR)08_plusplus_test.c\
		$(SDIR)09_plus_test.c\
		$(SDIR)10_plusneg_test.c\
		$(SDIR)11_negneg_test.c\
		$(SDIR)12_negzero_test.c\
		$(SDIR)13_pluszero_test.c\
		$(SDIR)14_letters_test.c\
		$(SDIR2)00_ft_strlen_launcher.c\
		$(SDIR2)01_strlenbasic_test.c\
		$(SDIR2)02_empty_test.c\

SRC2 = main_test.c

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

LIB_FTPRINTF = ./../printf/
LIB_FT = ./../printf/libft/
FT_FRAM = ./../framework/

CC = gcc
FLAGS = -Wall -Wextra -Werror

RED = \033[31m
CYAN = \033[36m
NORMAL = \033[00m
GREY = \033[90m

.PHONY: clean fclean all re propre

all: $(NAME)

$(NAME): $(OBJ2) $(OBJ)
	@make -C $(LIB_FTPRINTF)
	@echo "$(CYAN)[$(NAME)]$(GREY) Libft compiled.$(NORMAL)"
	@make -C $(FT_FRAM)
	@echo "$(CYAN)[$(NAME)]$(GREY) Libunit compiled.$(NORMAL)"
	@$(CC) -o $(NAME) $(OBJ) $(OBJ2) $(LIB_FTPRINTF)libftprintf.a  $(LIB_FT)libft.a  $(FT_FRAM)libunit.a $(FRAM)
	@echo "$(CYAN)[$(NAME)]$(GREY) Executable created.$(NORMAL)"

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $< -I $(HDIR)

re: fclean all

clean:
	@rm -f $(OBJ) $(OBJ2)
	@echo "$(CYAN)[$(NAME)]$(RED) All objects file deleted.$(NORMAL)"
	@make clean -C $(LIB_FTPRINTF)
	@echo "$(CYAN)[$(NAME)]$(RED) Libft cleaned.$(NORMAL)"

fclean:
	@rm -f $(OBJ) $(OBJ2)
	@echo "$(CYAN)[$(NAME)]$(RED) All objects file deleted.$(NORMAL)"
	@rm -f $(NAME)
	@echo "$(CYAN)[$(NAME)]$(RED) Executable deleted.$(NORMAL)"
	@make fclean -C $(LIB_FTPRINTF)
	@echo "$(CYAN)[$(NAME)]$(RED) Libft cleaned.$(NORMAL)"
	@rm -f log_result

test: $(NAME)
	./$(NAME)

propre: all clean
