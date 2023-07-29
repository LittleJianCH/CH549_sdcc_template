CC = sdcc

CFLAGS = -I lib/ -o build/ -c

SRCS = src/main.c src/func.c 
OBJS =$(patsubst src/%.c,build/%.rel,$(SRCS))

all: main.hex

main.hex: main.ihx
	packihx out/main.ihx > out/main.hex
	python3 scripts/lf2crlf.py out/main.hex

main.ihx: $(OBJS)
	mkdir -p out
	$(CC) $(OBJS) -o out/

build/%.rel: src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) $<

clean:
	rm -rf build/*
	rm -rf out/*
