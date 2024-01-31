CXX = g++
CXXFLAGS = -std=c++14 -Wall -I./include
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRC = $(wildcard Code/*.cpp)
OBJ_DIR = obj/
OBJ = $(patsubst Code/%.cpp, $(OBJ_DIR)%.o, $(SRC))
EXEC = OlympicGameGenerator

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)

$(OBJ_DIR)%.o: Code/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -rf $(OBJ_DIR) $(EXEC)

.PHONY: all clean
