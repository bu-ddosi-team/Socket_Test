$(shell export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH)


PROGS = test otest client mtest
OBJS = DsauServer.o odscpp.o
LIBS = libDsauServer.a libods.a#libDsauServer.so
all: $(LIBS) $(PROGS) $(OBJS)

### shared library
#libDsauServer.so: DsauServer.o
#	gcc -shared -o $@ DsauServer.o

#static library
libDsauServer.a: DsauServer.o
	ar rc libDsauServer.a DsauServer.o
	ranlib libDsauServer.a

	 ###should be objTest
DsauServer.o: DsauServer.cpp DsauServer.h
#	g++ -fPIC -c DsauServer.cpp
	g++ -c DsauServer.cpp


test: TheMainServer.cpp DsauServer.o
	g++ -o $@ TheMainServer.cpp -L. -lDsauServer

libods.a: odscpp.o
	ar rc libods.a odscpp.o
	ranlib libods.a

odscpp.o: odscpp.cpp
	g++ -c odscpp.cpp
	
otest: SNC.cpp odscpp.o
	g++ -o $@ SNC.cpp -L. -lods	
	
mtest: MTserver.cpp DsauServer.o
	g++ -o $@ MTserver.cpp -pthread -L. -lDsauServer
		
client: ClientTester.cpp
	g++ -o $@ ClientTester.cpp
	
clean:
	rm -f *.0 *~ *.so *.a *.o $(PROGS)


