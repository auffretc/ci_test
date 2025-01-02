COMPILER=gcc
SRCS:=$(filter-out testsuite.c,$(wildcard *.c))
OBJS:=$(FICHIERS:%=%.o)

all: $(SRCS)
	gcc -o $@ -c $^

cppcheck: $(SRC)
	cppcheck $(SRCS)

testsuite: $(OBJS)
	$(COMPILER) max.o testsuite.c -lcunit -o $@
	./@
