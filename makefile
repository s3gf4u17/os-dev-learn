TARGET=i686-elf
PREFIX=$(shell pwd)/opt/cross

library: library/*
	cd library && make --always-make

tests: tests/*
	cd tests && make --always-make

dependencies:
	sudo apt install\
		build-essential\
		bison\
		flex\
		libgmp3-dev\
		libmpc-dev\
		libmpfr-dev\
		texinfo\
		libisl-dev\
		qemu-system-x86

clean:
	rm -rf tmp/ opt/
	cd library && make clean --always-make
	cd tests && make clean --always-make

environment:
	@printf "`tput setaf 10 bold`Getting Binutils 2.43 source code`tput sgr0`\n"
	wget https://ftp.gnu.org/gnu/binutils/binutils-2.43.tar.xz --directory-prefix=tmp/
	@printf "`tput setaf 10 bold`Getting GCC 14.2.0 source code`tput sgr0`\n"
	wget https://ftp.fu-berlin.de/unix/languages/gcc/releases/gcc-14.2.0/gcc-14.2.0.tar.xz --directory-prefix=tmp/
	@printf "`tput setaf 10 bold`Extracting Binutils 2.43 source code`tput sgr0`\n"
	tar -xf tmp/binutils-2.43.tar.xz --directory tmp/
	@printf "`tput setaf 10 bold`Extracting GCC 14.2.0 source code`tput sgr0`\n"
	tar -xf tmp/gcc-14.2.0.tar.xz --directory tmp/
	@printf "`tput setaf 10 bold`Building Binutils 2.43 source code`tput sgr0`\n"
	@rm -rf tmp/binutils && mkdir tmp/binutils
	@cd tmp/binutils && ../binutils-2.43/configure --target=$(TARGET) --prefix="$(PREFIX)" --with-sysroot --disable-nls --disable-werror
	@cd tmp/binutils && make -j16 && make install
	@printf "`tput setaf 10 bold`Building GCC 14.2.0 source code`tput sgr0`\n"
	@rm -rf tmp/gcc && mkdir tmp/gcc
	@cd tmp/gcc && ../gcc-14.2.0/configure --target=$(TARGET) --prefix="$(PREFIX)" --disable-nls --enable-languages=c,c++ --without-headers
	@cd tmp/gcc && make all-gcc -j16 && make all-target-libgcc -j16 && make install-gcc && make install-target-libgcc
	@rm -rf tmp/
	@printf "`tput setaf 15 setab 25 bold` FINISHED `tput sgr0`\n"

build:
	rm -rf build/ && mkdir build
	opt/cross/bin/i686-elf-as src/boot.s -o build/boot.o
	opt/cross/bin/i686-elf-gcc -c src/kernel.c -o build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	opt/cross/bin/i686-elf-gcc -T src/linker.ld -o build/myos.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o -lgcc

run: build
	qemu-system-i386 -kernel build/myos.bin