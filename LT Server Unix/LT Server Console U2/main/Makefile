PROGS = test

all:$(PROGS) 

test: TheMainServer.cpp DsauServer.cpp
	g++ -o $@ TheMainServer.cpp DsauServer.cpp
	
clean:
	rm -f *.0 *~ *.so *.a *.o $(PROGS)


