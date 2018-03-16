##
## Makefile for cpp_rush3 in /home/sid/C++_POOL/Rushs/cpp_rush3
## 
## Made by Abdel
## Login   <abderrahim.cherkaoui@epitech.eu>
## 
## Started on  Sun Jan 21 09:48:05 2018 Abdel
## Last update Sun Jan 21 09:54:44 2018 Abdel
##

NAME	= hpot
NAMECOURSE = hpotCourse

CC	= g++

RM	= rm -f

SRCS	= ./core/Core.cpp \
	  ./core/Parser.cpp \
	  ./modules/AMonitorModule.cpp \
	  ./modules/CPU.cpp \
	  ./modules/Clock.cpp \
	  ./modules/Network.cpp \
	  ./modules/OperatingSystem.cpp \
	  ./modules/Processes.cpp \
	  ./modules/RAM.cpp \
	  ./modules/User.cpp \
	  ./terminal/terminal.cpp \
	  ./core/main.cpp

COURSE	= ./core/Core.cpp \
	  ./core/Parser.cpp \
	  ./modules/AMonitorModule.cpp \
	  ./modules/CPU.cpp \
	  ./modules/Clock.cpp \
	  ./modules/Network.cpp \
	  ./modules/OperatingSystem.cpp \
	  ./modules/Processes.cpp \
	  ./modules/RAM.cpp \
	  ./modules/User.cpp \
	  ./terminal/terminal.cpp \
	  ./terminal/main.cpp \

OBJS	= $(SRCS:.cpp=.o)
OBJCOURSE	= $(COURSE:.cpp=.o)

CPPFLAGS = -I ./core -I ./graphic -I ./modules -I ./terminal
CPPFLAGS += -W -Wall -Wextra -std=c++11

all: $(NAME)

course: $(NAMECOURSE)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -lncurses -o $(NAME) $(LDFLAGS)



$(NAMECOURSE): $(OBJCOURSE)
	 $(CC) $(OBJCOURSE) -lncurses -o $(NAMECOURSE) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

recourse: fcleancourse course

myHpot:
	make -C ./graphic

fclean: clean
	$(RM) $(NAME)

fcleancourse: clean
	$(RM) $(NAMECOURSE)

re: fclean all

.PHONY: all clean fclean re fcleancourse course recourse
