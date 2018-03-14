СPP_FLAGS=-Werror -Wall -std=c++11
all: bin/huffman

./bin/huffman: ./src/main.cpp ./bin/decoding.o ./bin/coding.o ./bin/work_with_tree.o ./bin/list_node.o ./bin/list.o ./bin/tree_node.o
	g++ $(CPP_FLAGS) ./src/main.cpp ./bin/decoding.o ./bin/coding.o ./bin/work_with_tree.o ./bin/list_node.o ./bin/list.o ./bin/tree_node.o -o ./bin/huffman

./bin/decoding.o: ./src/decoding.cpp ./src/decoding.h
	g++ $(CPP_FLAGS) -c ./src/decoding.cpp -o ./bin/decoding.o

./bin/coding.o: ./src/coding.cpp ./src/coding.h
	g++ $(CPP_FLAGS) -c ./src/coding.cpp -o ./bin/coding.o
	
./bin/work_with_tree.o: ./src/work_with_tree.cpp ./src/work_with_tree.h
	g++ $(CPP_FLAGS) -c ./src/work_with_tree.cpp -o ./bin/work_with_tree.o

./bin/list_node.o: ./src/list_node.cpp ./src/list_node.h 
	g++ $(CPP_FLAGS) -c ./src/list_node.cpp -o ./bin/list_node.o

./bin/list.o: ./src/list.cpp ./src/list.h 
	g++ $(CPP_FLAGS) -c ./src/list.cpp -o ./bin/list.o

./bin/tree_node.o: ./src/tree_node.cpp ./src/tree_node.h
	g++ $(CPP_FLAGS) -c ./src/tree_node.cpp -o ./bin/tree_node.o

	
clean:
	rm -fr ./bin/*
.PHONY: clean all
