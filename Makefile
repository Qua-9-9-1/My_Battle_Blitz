#/
## Quentin Duval 2024
## Free Projects
## GitHub: @Qua-9-9-1
## Email:  quentduva@gmail.com
#\

CXX := g++
CXXFLAGS := -Isrc/includes -Iexternal/sol2/include -I/usr/include/lua5.4 -std=c++2a -Wall -Wextra -g3
SRCS := $(shell find src -name '*.cpp') main.cpp
OBJS := $(SRCS:.cpp=.o)
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lpthread
LUA_SCRIPTS := $(shell find scripts -name '*.lua')
LUA_LIBS := -llua5.4
TARGET := my_MicroGames

all: check_deps $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(SFML_LIBS) $(LUA_LIBS)
	mv $(TARGET) ./bin

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../$(TARGET)

re: fclean all

check_deps:
	@command -v lua >/dev/null 2>&1 || { echo >&2 "Lua is not installed. Please install Lua."; exit 1; }
	@command -v g++ >/dev/null 2>&1 || { echo >&2 "g++ is not installed. Please install g++."; exit 1; }
	@pkg-config --exists sfml-all || { echo >&2 "SFML is not installed. Please install SFML."; exit 1; }

install_deps:
	sudo apt update
	sudo apt install -y lua5.4 liblua5.4-dev g++ libsfml-dev
