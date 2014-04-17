
PROGS = mtest

all: $(PROGS)

	
mtest: MTserver.cpp DsauServer.cpp
	g++ -o $@ MTserver.cpp DsauServer.cpp -pthread 
		

clean:
	rm -f *.0 *~ *.so *.a *.o $(PROGS)


