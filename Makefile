COMPILER=gcc
SRCS:=$(filter-out testsuite.c, $(wildcard *.c))
OBJS:=$(patsubst %.c, %.o, $(SRCS)) 

build: $(SRCS)
	$(COMPILER) -o max.o -c max.c

cppcheck: $(SRCS)
	cppcheck max.c

testsuite: build testsuite.c
	$(COMPILER) $(OBJS) testsuite.c -lcunit -o $@
	./$@
