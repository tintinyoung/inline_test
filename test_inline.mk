test_inline: clean utils.o main.o
	$(CC) utils.o main.o -o test_inline
	-objdump -t utils.o | grep get_tu_name
	-objdump -t main.o  | grep get_tu_name
	-objdump -t test_inline | grep get_tu_name
	-objdump -t utils.o | grep convert2
	-objdump -t main.o  | grep convert2
	-objdump -t test_inline | grep convert2
	./test_inline

clean:
	rm -f *.o
	rm -f test_inline

%.o: %.c
	$(CC) $(OPTIM) --std=$(STD) -DTU=\"$(patsubst %.c,[%],$<)\" -c $< -o $@