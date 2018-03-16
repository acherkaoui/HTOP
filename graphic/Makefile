##
## Makefile for cpp_rush3 in /home/abdel/C++_POOL/Rushs/cpp_rush3/graphic
## 
## Made by Abdel
## Login   <abderrahim.cherkaoui@epitech.eu>
## 
## Started on  Sun Jan 21 09:49:56 2018 Abdel
## Last update Sun Jan 21 09:49:59 2018 Abdel
##

CC	=	g++

SRC	=	graphic.cpp         \
       ./../modules/AMonitorModule.cpp \
       ./../modules/CPU.cpp \
       ./../modules/Clock.cpp \
       ./../modules/Network.cpp \
       ./../modules/OperatingSystem.cpp \
       ./../modules/RAM.cpp \
       ./../modules/User.cpp    \
       ./HpotMenu.cpp


OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=	-std=c++11 -I./include -W -Wall -Wextra -Werror

LDFLAGS =	-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

NAME	=	my_Hpot

all:	$(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean
