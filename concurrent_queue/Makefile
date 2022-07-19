CC = g++
CFLAGS = -Wall -g -L /opt/homebrew/Cellar/boost/1.79.0/lib -I /opt/homebrew/Cellar/boost/1.79.0/include
VERSION = -std=c++17




output: main.o test.o concurrent_queue.o
	$(CC) $(VERSION) -Wall main.o test.o -o output

main.o: main.cpp
	$(CC) $(VERSION) $(CFLAGS) -c main.cpp 

#concurrent_queue.o: concurrent_queue.h
test.o: test.cpp test.h
	$(CC) $(VERSION) $(CFLAGS) -c test.cpp

concurrent_queue.o: concurrent_queue.cpp concurrent_queue.h
	$(CC) $(VERSION) $(CFLAGS) -c concurrent_queue.cpp


.PHONY: clean
clean:
	rm -rf *.o output



