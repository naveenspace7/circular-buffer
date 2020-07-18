install:
	@cp circular_buffer.hpp /usr/include

run_test:
	@g++ ./tests/test.cpp -lgtest -lpthread -o ./tests/test
	@./tests/test