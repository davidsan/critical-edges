CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm
RM = rm -f
SRC = reader.c graph.c scanner.c postscript.c
OBJ = $(SRC:.c=.o)
EXEC = main convertPostscript


all: $(EXEC)

.depend: $(SRC) $(EXEC:=.c)
	 $(CC) -MM $^ > $@

-include .depend

%: %.o $(OBJ) 
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	$(RM) $(OBJ) .depend $(SRC:.c=.h.gch) $(EXEC:=.o)

mrproper:
	$(RM) $(OBJ) $(EXEC) .depend $(SRC:.c=.h.gch) $(EXEC:=.o)

.PHONY: all clean mrproper
