TARGET = build/dencrypt-test
SRCS = src/main.c
OBJS = build/main.o

minitower_INC = ../comm/usercode/libminitower/include

.PHONY: all
all: $(TARGET)

$(TARGET): $(SRCS) $(wildcard ../comm/usercode/libminitower/src/*.c)
	gcc -o $@ $^ -I$(minitower_INC)
