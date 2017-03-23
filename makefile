CC=gcc
SRC=src
ODIR=obj
BUILD_DIR=build
EXEC_NAME=cc
OPTIONS=-Wall

all: $(ODIR)/board.o $(ODIR)/candy.o
	$(CC) $(ODIR)/Candy.o $(ODIR)/board.o $(SRC)/main.c $(OPTIONS) -o $(BUILD_DIR)/$(EXEC_NAME)

createdirs:
	mkdir $(ODIR)
	mkdir $(BUILD_DIR)

$(ODIR)/board.o: $(SRC)/board.c $(SRC)/board.h $(SRC)/models.h
	$(CC) $(SRC)/board.c $(OPTIONS) -c -o $(ODIR)/board.o

$(ODIR)/candy.o: $(SRC)/Candy.c $(SRC)/Candy.h $(SRC)/models.h
	$(CC) $(SRC)/Candy.c $(OPTIONS) -c -o $(ODIR)/Candy.o

clean:
	rmdir -fr $(ODIR)
	rmdir -fr $(BUILD_DIR)