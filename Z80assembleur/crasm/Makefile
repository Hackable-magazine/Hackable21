TARGET = test

all: ${TARGET}

${TARGET}: ${TARGET}.bin
	xxd -c 16 -i ${TARGET}.bin

${TARGET}.bin: ${TARGET}.ihx
	makebin -p < ${TARGET}.ihex > ${TARGET}.bin

${TARGET}.ihx : ${TARGET}.asm
	crasm -o ${TARGET}.ihex ${TARGET}.asm > ${TARGET}.lst

clean:
	rm -rf ${TARGET}.ihex ${TARGET}.bin ${TARGET}.lst
