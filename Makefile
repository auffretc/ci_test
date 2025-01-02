COMPILER=gcc
FICHIERS=max
OBJS:=$(FICHIERS:%=%.o)

all: max.o testsuite
	-rm *.o

max.o: max.c
	$(COMPILER) -c max.c -o $@

testsuite: $(OBJS)
	$(COMPILER) max.o testsuite.c -lcunit -o $@

test: testsuite
	./testsuite

clean: $(OBJS)
	-rm *.o
