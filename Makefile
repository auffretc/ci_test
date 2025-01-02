COMPILER=gcc
SRCS:=$(filter-out testsuite.c, $(wildcard *.c))
OBJS:=$(SRCS:%=%.o)

all: $(SRCS)
	gcc -o max.o -c max.c

cppcheck: $(SRC)
	cppcheck max.c

testsuite: $(OBJS)
	$(COMPILER) $(OBJS) testsuite.c -lcunit -o $@
	./@
