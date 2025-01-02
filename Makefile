COMPILER=gcc
SRCS:=$(filter-out testsuite.c, $(wildcard *.c))
OBJS:=$(patsubst %.c, %.o, $(SRCS)) 

build: $(SRCS) $(OBJS)
	gcc -o max.o -c max.c

cppcheck: $(SRCS)
	cppcheck max.c

testsuite: $(OBJS)
	$(COMPILER) $(OBJS) testsuite.c -lcunit -o $@
	./@
