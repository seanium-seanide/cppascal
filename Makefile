APP=cppascal

SRCDIR=src
OBJDIR=obj
BINDIR=bin
INCLUDEDIR=include

CC=clang++
CFLAGS=-W -Wall -I $(INCLUDEDIR) -g -D_GLIBCXX_DEBUG
LDFLAGS=

GDB=gdb
GDBOPTIONS=--tui

BIN=$(BINDIR)/$(APP)
OBJ=$(OBJDIR)/main.o $(OBJDIR)/Interpreter.o $(OBJDIR)/Token.o

$(BIN): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(INCLUDEDIR)/main.h
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) -o $@ $< 

$(OBJDIR)/Interpreter.o: $(SRCDIR)/Interpreter.cpp $(INCLUDEDIR)/Interpreter.h
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) -o $@ $< 

$(OBJDIR)/Token.o: $(SRCDIR)/Token.cpp $(INCLUDEDIR)/Token.h
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

.PHONY: debug
debug:
	$(GDB) $(GDBOPTIONS) ./$(BIN)
