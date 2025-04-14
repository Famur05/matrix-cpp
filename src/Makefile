#===========================================================================
CC = g++
FLAGS = -std=c++17 -pedantic -Wall -Werror -Wextra -lm
#===========================================================================
TARGET = s21_matrix_oop.a
#===========================================================================
TEST_FLAGS = -lgtest -lgmock -pthread
#===========================================================================
all: $(TARGET)

$(TARGET):
	$(CC) $(FLAGS) -c *.cc
	ar rcs $(TARGET) *.o
	ranlib $(TARGET)
	rm -rf *.o

test: $(TARGET)
	$(CC) tests/test.cc $(TARGET) $(FLAGS) $(TEST_FLAGS) -o test.out
	./test.out

clang_i:
	clang-format -i -style=Google *.cc *.h tests/*.cc

clang_n:
	clang-format -n -style=Google *.cc *.h tests/*.cc

clean:
	rm -rf *.out *.a *.o

rebuild: clean all
#===========================================================================