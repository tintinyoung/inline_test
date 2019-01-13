srcs+=$(shell find ./test_inline -maxdepth 1 -name "*.c")
objs+=$(subst .c,.o,$(srcs))
bin:=inline
inline_symbols = get_tu_name convert2

define dump_inline_symbols
	for inline_symbol in $(inline_symbols); do \
		for obj in $(bin_and_objs); do \
			echo "in $$obj:" && objdump -t $$obj | grep $$inline_symbol || (echo "no $$inline_symbol found!") ; \
		done; \
	done
endef
