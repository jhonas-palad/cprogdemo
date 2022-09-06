CC=	gcc
CFLAGS= -g -Wall -Werror
TARGET= main
MODULE_DIR= Module
DEPS=	$(MODULE_DIR)/data.o

all: $(TARGET)

$(TARGET): $(TARGET).o $(DEPS)
	$(CC) $(CFLAGS) $^ -o $@
	$(RM) $<

%.o: %.c
	$(CC) -c $<
	

$(MODULE_DIR)/%.o: $(MODULE_DIR)/%.c Include/%.h
	$(CC) -c $< -o $@

Include/%.h:
	if [ ! -f "$@" ] then \
		echo "No header file of $@";
	fi

make_s: main.s Module/data.s

%.s: %.c 
	$(CC) -S $< -o $@

clean:
	$(RM) *.o main
	$(RM) Module/*.o