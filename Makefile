CC = sdcc

CFLAGS = -I lib/ -c

LIBS = lib/CH549_pwm.c
SRCS = src/main.c src/func.c
OBJS = $(patsubst src/%.c,build/%.rel,$(SRCS)) $(patsubst lib/%.c,build/lib/%.rel,$(LIBS))

all: main.hex

main.hex: main.ihx
	packihx out/main.ihx > out/main.hex
	python3 scripts/lf2crlf.py out/main.hex

main.ihx: $(OBJS)
	mkdir -p out
	$(CC) $(OBJS) -o out/

build/lib/%.rel: lib/%.c
	mkdir -p build
	mkdir -p build/lib
	$(CC) $(CFLAGS) -o build/lib/ $<

build/%.rel: src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -o build/ $<

clean:
	rm -rf build/*
	rm -rf out/*
