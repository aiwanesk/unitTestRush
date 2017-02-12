NAME = tests_libft

HDIR = ./includes/
SDIR = ./ft_atoi/
ODIR = ./objects/

SRC =	00_ft_atoi_launcher.c\
		01_basic_test.c\
		02_neg_test.c\
		03_emptystring_test.c\
		04_intmin_test.c\
		05_intmax_test.c\
		06_overflow_test.c\
		07_zero_test.c\
		08_plusplus_test.c\
		09_plus_test.c\
		10_plusneg_test.c\
		11_negneg_test.c\
		12_negzero_test.c\
		13_pluszero_test.c\
		14_letters_test.c\

SRC2 = main_test.c

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

SRC_C := $(addprefix $(SDIR), $(SRC))
SRC_O := $(addprefix $(ODIR), $(OBJ))

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

$(NAME): $(SRC_O) $(OBJ2)
	@$(CC) -o $(NAME) $(SRC_O) $(OBJ2) $(LIB_FTPRINTF)libftprintf.a  $(LIB_FT)libft.a  $(FT_FRAM)libunit.a $(FRAM)
	@echo "$(CYAN)[$(NAME)]$(GREY) Executable created.$(NORMAL)"

$(SRC_O): $(SRC_C) $(SRC2)
	@make -C $(LIB_FTPRINTF)
	@echo "$(CYAN)[$(NAME)]$(GREY) Libft compiled.$(NORMAL)"
	@make -C $(FT_FRAM)
	@echo "$(CYAN)[$(NAME)]$(GREY) Libunit compiled.$(NORMAL)"
	@$(CC) $(FLAGS) -c $(SRC_C) $(SRC2) -I $(HDIR)
	@if [ -d $(ODIR) ]; then\
		echo "$(CYAN)[$(NAME)]$(GREY) Objects Directory already exists.$(NORMAL)";\
		else\
		mkdir $(ODIR);\
		fi
	@mv $(OBJ) $(OBJ2) $(ODIR)
	@echo "$(CYAN)[$(NAME)]$(GREY) Objects created.$(NORMAL)"

re: fclean all

clean:
	@rm -f $(SRC_O) $(OBJ2)
	@rm -rf $(ODIR)
	@echo "$(CYAN)[$(NAME)]$(RED) All objects file deleted.$(NORMAL)"
	@make clean -C $(LIB_FTPRINTF)
	@echo "$(CYAN)[$(NAME)]$(RED) Libft cleaned.$(NORMAL)"

fclean:
	@rm -f $(SRC_O) $(OBJ2)
	@rm -rf $(ODIR)
	@echo "$(CYAN)[$(NAME)]$(RED) All objects file deleted.$(NORMAL)"
	@rm -f $(NAME)
	@echo "$(CYAN)[$(NAME)]$(RED) Executable deleted.$(NORMAL)"
	@make fclean -C $(LIB_FTPRINTF)
	@echo "$(CYAN)[$(NAME)]$(RED) Libft cleaned.$(NORMAL)"

test: $(NAME)
	./$(NAME)

propre: all clean
