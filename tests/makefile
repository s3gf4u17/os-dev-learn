OBJS=\
memory.o

TESTS=\
memory_copy

GCCPATH64=gcc
GCCFLAG=-std=gnu99 -ffreestanding -O2 -Wall -Wextra -I../include

default: $(TESTS)

%: %.c
	@mkdir -p bin
	@$(GCCPATH64) $< -o bin/$@ $(GCCFLAG) $(patsubst %.o, ../library/x86_64/%.o, $(OBJS))
	@./bin/$@ && ([ $$? -eq 0 ] && echo "$@`tput setaf 8 && tput bold` SUCCESS`tput sgr0`") || echo "$@`tput setaf 1 && tput bold` FAILURE`tput sgr0`"

clean:
	rm -rf bin