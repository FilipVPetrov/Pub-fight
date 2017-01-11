
CC=g++

CFLAGS= -std=c++11 -pthread
LDFLAGS= -lpthread
INCLUDE= ../include/Duell.h \
         ../include/Fighter.h \
         ../include/Pub.h

src= Duell.cpp \
     Pub.cpp \
     main.cpp

all:
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDE) $(src) -o Pub
