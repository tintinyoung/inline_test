srcs:=$(shell find . -maxdepth 1 -name "*.c")
objs:=$(subst .c,.o,$(srcs))
bin:=test_inline
inline_symbols = get_tu_name convert2

reverse = $(if $(wordlist 2,2,$(1)),$(call reverse,$(wordlist 2,$(words $(1)),$(1))) $(firstword $(1)),$(1))

ordered_objs=$(sort $(objs))
reversed_objs=$(call reverse,$(ordered_objs))
bin_and_objs = $(ordered_objs) $(bin)

define dump_inline_symbols
	for inline_symbol in $(inline_symbols); do \
		for obj in $(bin_and_objs); do \
			echo "in $$obj:" && objdump -t $$obj | grep $$inline_symbol || (echo "no $$inline_symbol found!") ; \
		done; \
	done
endef

.PHONY: clean ordered_build reversed_build

ordered_build: clean $(ordered_objs) $(bin)
reversed_build: clean $(reversed_objs) $(bin)

$(bin): $(objs)
	$(CC) $(objs) -o $(bin)
	$(call dump_inline_symbols)
	echo "run test:" && ./test_inline

clean:
	rm -f *.o
	rm -f test_inline

%.o: %.c
	$(CC) $(OPTIM) --std=$(STD) -DTU=\"$(patsubst %.c,[%],$<)\" -c $< -o $@