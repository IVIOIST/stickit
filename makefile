CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRC = src/main.cpp src/PostItBoard.cpp src/ColorUtils.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = stickit

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
