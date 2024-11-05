SRC = $(wildcard src/*.c)
INC = include/
OBJ = $(patsubst %.c, %.o, $(SRC))
TEST_SRC = $(wildcard test/*.c)
TEST_OBJ = $(patsubst %.c, %.o, $(TEST_SRC))
TEST_EXEC = $(patsubst test/%.c, %.elf, $(TEST_SRC))
main.elf: $(OBJ)
	gcc $^ -o $@
%.o: %.c
	gcc -c $^ -I $(INC) -o $@
%.elf: test/%.o $(OBJ)
	gcc $(filter-out src/main.o, $^) -I $(INC) -o $@ 
run_tests: $(TEST_EXEC)
	@echo "Running all tests..."
	@for test in $(TEST_EXEC); do \
	    echo "Running $$test..."; \
	    ./$$test; \
	done
clean:
	rm -f $(OBJ) $(TEST_OBJ) main.elf $(TEST_EXEC)
	
