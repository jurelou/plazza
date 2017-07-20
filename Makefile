
CXX		=	g++

CXXFLAGS	+=	-W -Wall -Wextra -pthread -std=c++11 -I./include

NAME		=	 plazza

SRC		=	main.cpp \
			./src/Process.cpp \
			./src/Mutex.cpp \
			./src/Thread.cpp

OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) -o $@ $^

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
