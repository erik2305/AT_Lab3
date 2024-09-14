# Compiler and options
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Output executable name
TARGET = interpreter

# Source files
SRCS = main.cpp ast.cpp symbol_table.cpp maze.cpp lexer.cpp parser.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Flex and Bison files
LEXER = lexer.l
PARSER = parser.y

# Bison generates parser.cpp and parser.hpp
parser.cpp parser.hpp: $(PARSER)
	bison -d -o parser.cpp $(PARSER)

# Flex generates lexer.cpp, which depends on parser.hpp
lexer.cpp: $(LEXER) parser.hpp
	flex -o lexer.cpp $(LEXER)

# Default rule to build the target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) -lfl

# Rule to compile each .cpp file into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove compiled files
clean:
	rm -f $(OBJS) $(TARGET) lexer.cpp parser.cpp parser.hpp

.PHONY: all clean
