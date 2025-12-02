CC = gcc
CFLAGS = -Wall -O2
OBJS = main.o recursive.o iterative.o
TARGET = hanoi

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
