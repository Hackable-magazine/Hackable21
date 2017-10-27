TARGET = test

AS = z80-unknown-coff-as
LD = z80-unknown-coff-ld

all: ${TARGET}

${TARGET}: ${TARGET}.bin
	xxd -c 16 -i ${TARGET}.bin

${TARGET}.bin: ${TARGET}.coff
	z80-unknown-coff-objcopy -I coff-z80 -O binary ${TARGET}.coff ${TARGET}.bin

${TARGET}.coff: ${TARGET}.o
	$(LD) -T z80.ld --cref ${TARGET}.o -o ${TARGET}.coff -Map ${TARGET}.map

${TARGET}.o: ${TARGET}.asm
	$(AS) -adhlns=${TARGET}.lst -z80 ${TARGET}.asm -o ${TARGET}.o

clean:
	rm -rf ${TARGET}.bin ${TARGET}.lst ${TARGET}.map ${TARGET}.o ${TARGET}.coff
