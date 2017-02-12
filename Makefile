.PHONY: clean fclean all re test testfclean testclean testre realtest realtestfclean realtestclean realtestre

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

realtest:
	make -C ./printf/
	make -C ./framework/
	make -C ./real-tests/

realtestfclean:
	make fclean -C ./framework/

realtestclean:
	make clean -C ./framework/

realtestre:
	make re -C ./printf/
	make re -C ./framework/
	make re -C ./real-tests//

re:
	make re -C ./framework/

clean:
	make clean -C ./framework/

fclean:
	make fclean -C ./framework/
	make fclean -C ./printf/
	make fclean -C ./tests/
	make fclean -C ./real-tests/
