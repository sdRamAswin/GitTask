OBJS	= stack.o Conversion.o Evaluation.o InfixToPostfix.o
SOURCE	= stack.c Conversion.c Evaluation.c InfixToPostfix.c
HEADER	= stack.h Conversion.h Evaluation.h
OUT	= op
CC	 = gcc
FLAGS	 = -g -c -Wall

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

%.o: %.c
	$(CC) $(FLAGS) $<

clean:
	rm -f $(OBJS) $(OUT)

