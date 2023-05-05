CC = gcc
CFLAGS = -W -Wall
TARGET = plan
OBJECTS = main.c study.o
all: $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean : 
	rm *.o plan
