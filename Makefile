SRC = main.cpp InsertNode.cpp Counter.cpp FreeNode.cpp PrintTree.cpp \
	  FoundNode.cpp PrintInfo.cpp PrintGraph.cpp DeleteNode.cpp

HEADER = Tree.h
OBJ = ${SRC:.cpp=.o}
# CFLAGCS = -Wall -Wextra -Werror -std='c++98'
CC = clang++
NAME = tree

%.o:		%.cpp
		$(CC) $(CFLAGCS) -c -o $@ $<

all: $(NAME)

${NAME}: ${OBJ} ${HEADER}
	$(CC) $(CFLAGCS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

debug:
	$(CC) -g $(CFLAGCS) $(SRC) -o $(NAME)

re: fclean all

.PHONY : all clean fclean re