NAME = tests_fmk

HDIR = ./includes/
SDIR = ./tests/
ODIR = ./objects/

SRC = main_test.c\
	 00_tests_launcher.c\
	 01_ok_test.c\
	 02_ko_test.c\
	 03_segv_test.c\
	 04_bus_test.c\

OBJ = $(SRC:.c=.o)

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

$(NAME): $(SRC_O)
	@$(CC) -o $(NAME) $(SRC_O) $(LIB_FTPRINTF)libftprintf.a  $(LIB_FT)libft.a  $(FT_FRAM)miniframework.a $(FRAM)
	@echo "$(CYAN)[$(NAME)]$(GREY) Executable created.$(NORMAL)"

$(SRC_O): $(SRC_C)
	@make -C $(LIB_FTPRINTF) 
	@echo "$(CYAN)[$(NAME)]$(GREY) Libft compiled.$(NORMAL)"
	@$(CC) $(FLAGS) -c $(SRC_C) -I $(HDIR)
	@if [ -d $(ODIR) ]; then\
	  echo "$(CYAN)[$(NAME)]$(GREY) Objects Directory already exists.$(NORMAL)";\
	  else\
	  mkdir $(ODIR);\
	fi
	@mv $(OBJ) $(ODIR)
	@echo "$(CYAN)[$(NAME)]$(GREY) Objects created.$(NORMAL)"

re: fclean all

clean:
	@rm -f $(SRC_O)
	@rm -rf $(ODIR)
	@echo "$(CYAN)[$(NAME)]$(RED) All objects file deleted.$(NORMAL)"
	@make clean -C $(LIB_FTPRINTF)
	@echo "$(CYAN)[$(NAME)]$(RED) Libft cleaned.$(NORMAL)"

fclean:
	@rm -f $(SRC_O)
	@rm -rf $(ODIR)
	@echo "$(CYAN)[$(NAME)]$(RED) All objects file deleted.$(NORMAL)"
	@rm -f $(NAME)
	@echo "$(CYAN)[$(NAME)]$(RED) Executable deleted.$(NORMAL)"
	@make fclean -C $(LIB_FTPRINTF)
	@echo "$(CYAN)[$(NAME)]$(RED) Libft cleaned.$(NORMAL)"

propre: all clean
