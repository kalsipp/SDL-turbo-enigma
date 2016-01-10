CC = g++
#CC = clang
FLAGS = -std=c++11 -Wall -pedantic -Wno-unknown-pragmas 
INCLUDES = -I /usr/include/SDL2/ -lSDL2 -lGL -lSDL2_ttf -lSDL2_mixer -lSDL2_image -lGLEW
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
main.out: $(OBJ_FILES)
	$(CC) $(FLAGS)    -o $@ $^  $(INCLUDES)
obj/%.o: src/%.cpp
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)
clean:
	rm -f obj/*.o *.out
