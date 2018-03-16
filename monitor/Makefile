CC	=	g++

SRC	=	main.cpp                \
        ./modules/HpotMenu.cpp  \
        ./../../modules/.cpp


OBJ	=	$(SRC:.cpp=.o)

CFLAGS	=	-I./include

LDFLAGS =	-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

NAME	=	hpot

all:	$(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean