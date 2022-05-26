CC= g++
CFLAGS= -g -Wall
OBJFILES = main.o 
TARGET = build

build: main.o 
	$(CC) $(CFLAGS) $(OBJFILES) -o build

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp

clean:
	rm $(OBJFILES) $(TARGET)