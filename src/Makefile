CXX=g++
src = $(wildcard *.c??)
obj = $(src:.c??=.o)

myprog=main

#Postgres
LDFLAGS = -lpqxx -lpq -fsanitize=address

myprog: $(obj)
	$(CXX) $(defs) $^ -o ../build/$@ $(LDFLAGS)

build_dir:
	mkdir ../build || true

_set_no_db:
	defs=-DNO_DB

no_db: $(obj) # _set_no_db myprog
	$(CXX) -DNO_DB $^ -o ../build/myprog $(LDFLAGS)

run:
	../build/myprog

.PHONY: clean
clean:
	rm -f $(obj) myprog

