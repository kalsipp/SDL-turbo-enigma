CC = g++
#CC = clang
FLAGS = -std=c++11 
INCLUDES = -I /usr/include/SDL2/ -lSDL2 -lGL -lSDL2_ttf 
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
main.out: $(OBJ_FILES)
	$(CC) $(FLAGS)    -o $@ $^  $(INCLUDES)
obj/%.o: src/%.cpp
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)
clean:
	rm -f obj/*.o *.out
