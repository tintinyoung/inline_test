
reverse = $(if $(wordlist 2,2,$(1)),$(call reverse,$(wordlist 2,$(words $(1)),$(1))) $(firstword $(1)),$(1))

srcs += main.c
objs += main.o
ordered_objs=$(sort $(objs))
reversed_objs=$(call reverse,$(ordered_objs))
bin_and_objs = $(ordered_objs) $(bin)

.PHONY: clean ordered_build reversed_build debug

ordered_build: clean ordered_bin
reversed_build: clean reversed_bin

ordered_bin: $(ordered_objs)
	$(CC) $(ordered_objs) -o $(bin)
	echo "run test:" && ./$(bin)

reversed_bin: $(reversed_objs)
	$(CC) $(reversed_objs) -o $(bin)
	echo "run test:" && ./$(bin)

clean:
	rm -f $(objs)
	rm -f $(bin)

debug:
	echo $(srcs)

%.o: %.c
	$(CC) $(OPTIM) -Winline -Wall --std=$(STD) -DTU=\"$(patsubst %.c,[%],$<)\" -c $< -o $@