gparameters =-m32 -mtune=i386 -fno-use-cxa-atexit -nostdlib -fno-rtti -fno-exceptions -fno-leading-underscore
asparameters=--32
ldparameters=-m elf_i386 
objectfiles=loader.o gdt.o kernel.o
WR=../sourceDir/installDir/bin/i686-elf-g++

%.o:%.cpp
	$(WR) $(gparamaters) -o $@ -c $<
%.o:%.s
	as $(asparameters) -o $@ -c $<

kartKernel.bin:linker.ld $(objectfiles)
	ld $(ldparameters) -T $< -o $@ $(objectfiles)
install: kartKernel.bin
	sudo cp kartKernel.bin /boot/kartKernel.bin
kartKernel.iso:kartKernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot
	echo 'set timeout=0'  >>iso/boot/grub/grub.cfg
	echo 'set default=0'  >>iso/boot/grub/grub.cfg
	echo ''  >>iso/boot/grub/grub.cfg
	echo 'menuentry "kartOS"{'  >>iso/boot/grub/grub.cfg
	echo ' 	multiboot /boot/kartKernel.bin'  >>iso/boot/grub/grub.cfg
	echo '	boot'  >>iso/boot/grub/grub.cfg
	echo '}'  >>iso/boot/grub/grub.cfg
	grub-mkrescue --output=kartKernel.iso iso
	rm -rf iso
run: kartKernel.iso
	(killall VirtualBox && sleep 1)|| true
	VirtualBox --startvm "kartOS" &
