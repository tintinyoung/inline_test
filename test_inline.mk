test_inline: clean utils.o main.o

clean:
	rm -f *.o
	rm -f test_inline

%.o: %.c
	$(CC) $(OPTIM) --std=$(STD) -DTU=\"$(patsubst %.c,[%],$<)\" -c $< -o $@