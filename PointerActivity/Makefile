test_pointers: main.c
	gcc main.c -o test_pointers -Wall -g read_data.o

main.o:  main.c read_data.o
	gcc main.c -o main.o read_data.o

read_data.o: read_data.c
	gcc read_data.c -c -o read_data.o read_data.h