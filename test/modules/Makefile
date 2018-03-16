##
## Makefile for Unit Tests for cpp_rush3 in /home/abdel/C++_POOL/Rushs/cpp_rush3/test/modules
## 
## Made by Abdel
## Login   <abderrahim.cherkaoui@epitech.eu>
## 
## Started on  Sun Jan 21 04:37:11 2018 Sid
## Last update Sun Jan 21 04:43:11 2018 Sid
##

CC	= g++

RM	= rm -f

OS	= test_OS

SRCS_OS	= ../../modules/OperatingSystem.cpp \
	  ../../modules/AMonitorModule.cpp \
	  ./test_os.cpp

OBJS_OS	= $(SRCS_OS:.cpp=.o)

CPU      = test_CPU

SRCS_CPU = ../../modules/CPU.cpp \
          ../../modules/AMonitorModule.cpp \
          ./test_CPU.cpp

OBJS_CPU = $(SRCS_CPU:.cpp=.o)

RAM      = test_RAM

SRCS_RAM = ../../modules/RAM.cpp \
          ../../modules/AMonitorModule.cpp \
          ./test_ram.cpp

OBJS_RAM = $(SRCS_RAM:.cpp=.o)

USER     = test_USER

SRCS_USER = ../../modules/User.cpp \
          ../../modules/AMonitorModule.cpp \
          ./test_user.cpp

OBJS_USER = $(SRCS_USER:.cpp=.o)

NET      = test_NET

SRCS_NET = ../../modules/Network.cpp \
          ../../modules/AMonitorModule.cpp \
          ./test_network.cpp

OBJS_NET = $(SRCS_NET:.cpp=.o)

CLOCK      = test_CLOCK

SRCS_CLOCK = ../../modules/Clock.cpp \
          ../../modules/AMonitorModule.cpp \
          ./test_clock.cpp

OBJS_CLOCK = $(SRCS_CLOCK:.cpp=.o)

CPPFLAGS = -I ./pp
CPPFLAGS += -W -Wall -Wextra -std=c++11

all: os cpu memory user net clock

os: $(OBJS_OS)
	 $(CC) $(OBJS_OS) -o $(OS) $(LDFLAGS) && echo "\n######### Test OS ########\n" && ./test_OS && echo '\n'

cpu: $(OBJS_CPU)
	$(CC) $(OBJS_CPU) -o $(CPU) $(LDFLAGS) && echo "\n######### Test CPU ########\n" &&  ./test_CPU && echo '\n'

user: $(OBJS_USER)
	$(CC) $(OBJS_USER) -o $(USER) $(LDFLAGS) && echo "\n######### Test USER ########\n" && ./test_USER && echo '\n'

net: $(OBJS_NET)
	$(CC) $(OBJS_NET) -o $(NET) $(LDFLAGS) && echo "\n######### Test NET ########\n" && ./test_NET && echo '\n'

clock: $(OBJS_CLOCK)
	$(CC) $(OBJS_CLOCK) -o $(CLOCK) $(LDFLAGS) && echo "\n######### Test CLOCK ########\n" && ./test_CLOCK && echo '\n'

memory: $(OBJS_RAM)
	$(CC) $(OBJS_RAM) -o $(RAM) $(LDFLAGS) && echo "\n######### Test RAM ########\n" && ./test_RAM && echo '\n'

clean:
	$(RM) $(OBJS_OS) $(OBJS_CPU) $(OBJS_RAM) $(OBJS_USER) $(OBJS_NET) $(OBJS_CLOCK)

fclean: clean
	$(RM) $(OS) $(CPU) $(RAM) $(USER) $(NET) $(CLOCK)

re: fclean all

.PHONY: all clean fclean re
