$(shell export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH)


PROGS = test
OBJS = DsauServer.o
LIBS = libDsauServer.a #libDsauServer.so
all: $(LIBS) $(PROGS) $(OBJS)

### shared library
#libDsauServer.so: DsauServer.o
#	gcc -shared -o $@ DsauServer.o

#static library
libDsauServer.a: DsauServer.o
	ar rc libDsauServer.a DsauServer.o
	ranlib libDsauServer.a

	 ###should be objTest
DsauServer.o: DsauServer.cpp
#	g++ -fPIC -c DsauServer.cpp
	g++ -c DsauServer.cpp


test: TheMainServer.cpp DsauServer.o
	g++ -o $@ TheMainServer.cpp -L. -lDsauServer

	
	
clean:
	rm -f *.0 *~ *.so *.a $(PROGS)


