CC = gcc
CFLAGS = -g -Wall -Werror
SOLDOPT = -Wl,-rpath=. -I./Include
TARGET = main
TARGETSRC = Program/main.c
SOLIBS = Source/my_mbstowcs.c

all: $(TARGET)

# $(CC) $(CFLAGS) $(SOLDOPT) -L. -o $@ $^ -lmylib
$(TARGET): $(PROGBINS) libmylib.so
	$(CC) $(CFLAGS) $(SOLDOPT) -o $@ $^

libmylib.so: $(SOLIBS)
	$(CC) -fPIC -shared -o $@ $^

bin/%: Program/%.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BINS) d_mbstowcs *.out *.so