TARGET = test

all: ${TARGET}

${TARGET}: ${TARGET}.bin
	xxd -c 16 -i ${TARGET}.bin

${TARGET}.bin : ${TARGET}.asm
	pasmo -d ${TARGET}.asm ${TARGET}.bin > ${TARGET}.lst

clean:
	rm -rf ${TARGET}.bin ${TARGET}.lst

