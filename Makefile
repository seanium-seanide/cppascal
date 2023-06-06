APP=cppascal

CC=clang++
CFLAGS=-W -Wall
LDFLAGS=

SRCDIR=src
OBJDIR=obj
BINDIR=bin

BIN=$(BINDIR)/$(APP)
OBJ=$(OBJDIR)/main.o $(OBJDIR)/Interpreter.o $(OBJDIR)/Token.o

$(BIN): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/main.h
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) -o $@ $< 

$(OBJDIR)/Interpreter.o: $(SRCDIR)/Interpreter.cpp $(SRCDIR)/Interpreter.h
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) -o $@ $< 

$(OBJDIR)/Token.o: $(SRCDIR)/Token.cpp $(SRCDIR)/Token.h
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) -o $@ $< 

.PHONY: clean
clean:
	rm -rf $(BIN)
	rmdir $(BINDIR)
	rm -rf $(OBJ)
	rmdir $(OBJDIR)

.PHONY: run
run:
	./$(BIN)
