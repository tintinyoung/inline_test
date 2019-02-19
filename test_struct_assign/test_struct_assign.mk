#srcs+=$(shell find ./test_struct_assign -maxdepth 1 -name "*.c" -o -name "*.cpp")
srcs+=$(shell find ./test_struct_assign -maxdepth 1 -name "*.c")
objs+=$(patsubst %.c,%.o,$(srcs))
#objs+=$(patsubst %.cpp,%.o,$(srcs))
includes+=-I. -I./test_struct_assign
bin:=struct_assign
