# first run once:
# 	export LD_LIBRARY_PATH=/opt/gcc-11.2/lib64

CC=/opt/gcc-11.2/bin/g++-11.2
CFLAGS=-std=c++20 -Wall -Wextra -fmodules-ts

all: func.o main.o app

func.o: func.cxx
	$(CC) $(CFLAGS) -c $< 

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< 	

app: main.o func.o 
	$(CC) -o $@ $^


.PHONY: all clean

clean:
	rm -f *.o
	rm -f app