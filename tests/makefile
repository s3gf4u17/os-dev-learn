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
	@tput setaf 1 && tput bold
	@-./bin/$@
	@tput sgr0

clean:
	rm -rf bin