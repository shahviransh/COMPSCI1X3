CC=gcc
CFLAGS=-Wall
BUILD_DIR=build

all: main 

main: course.o student.o
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o ./$(BUILD_DIR)/main main.c

course.o: student.o
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o ./$(BUILD_DIR)/course.o course.c

student.o:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o ./$(BUILD_DIR)/student.o student.c

doxygen:
	doxygen Doxyfile

clean:
	rm -f -r *.o main

