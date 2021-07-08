CXX=g++
src = $(wildcard *.c??)
obj = $(src:.c??=.o)

myprog=main

#Postgres
LDFLAGS = -lpqxx -lpq

myprog: $(obj)
	$(CXX) $^ -o ../build/$@ $(LDFLAGS)

build_dir:
	mkdir ../build || true

.PHONY: clean
clean:
	rm -f $(obj) myprog

