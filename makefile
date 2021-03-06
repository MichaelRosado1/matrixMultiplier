CC= g++ -std=c++11 
CFLAGS= -g -Wall -pthread
OBJFILES = main.o matrix.o
TARGET = build

build: main.o matrix.o 
	$(CC) $(CFLAGS) $(OBJFILES) -o build

main.o: main.cpp 
	$(CC) -c $(CFLAGS) main.cpp

matrix.o: matrix.cpp
	$(CC) -c $(CFLAGS) matrix.cpp

clean:
	rm $(OBJFILES) $(TARGET)
