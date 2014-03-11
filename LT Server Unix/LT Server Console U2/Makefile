$(shell export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH)


PROGS = test2
OBJS = objserver.o
LIBS = libobjserver.a #libobjserver.so
all: $(LIBS) $(PROGS) $(OBJS)

### shared library
#libobjserver.so: objserver.o
#	gcc -shared -o $@ objserver.o

#static library
libobjserver.a: objserver.o
	ar rc libobjserver.a objserver.o
	ranlib libobjserver.a

	
objserver.o: objserver.cpp
#	g++ -fPIC -c objserver.cpp
	g++ -c objserver.cpp


test2: TheMainServer.cpp
	g++ -o $@ TheMainServer.cpp -L. -lobjserver

	
	
clean:
	rm -f *.0 *~ *.so *.a $(PROGS)


