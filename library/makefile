OBJS=\
memory.o

GCCPATH32=../opt/cross/bin/i686-elf-gcc
GCCPATH64=gcc
GCCFLAG=-std=gnu99 -ffreestanding -O2 -Wall -Wextra -I../include

default: $(OBJS)

%.o: %.c
	mkdir -p i686
	mkdir -p x86_64
	$(GCCPATH32) -c $< -o i686/$@ $(GCCFLAG)
	$(GCCPATH64) -c $< -o x86_64/$@ $(GCCFLAG)

clean:
	rm -rf */*.o