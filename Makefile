.PHONY: clean fclean all re test testfclean testclean testre

all: miniFramework

miniFramework:
	make -C ./framework/

test:
	make -C ./printf/
	make -C ./framework/
	make -C ./tests/

testfclean:
	make fclean -C ./framework/

testclean:
	make clean -C ./framework/

testre:
	make re -C ./printf/
	make re -C ./framework/
	make re -C ./tests//

re:
	make re -C ./framework/

clean:
	make clean -C ./framework/

fclean:
	make fclean -C ./framework/
