srcs+=$(shell find ./test_generic -maxdepth 1 -name "*.c")
objs+=$(patsubst %.c,%.o,$(srcs))
includes+=-I. -I./test_generic
bin:=generic
options += -DWAY2