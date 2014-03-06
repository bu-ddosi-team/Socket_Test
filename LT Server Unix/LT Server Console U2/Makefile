$(shell export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH)


PROGS = test2
OBJS = objserver.o
LIBS = libobjserver.so
all: $(LIBS) $(PROGS) $(OBJS)

###
libobjserver.so: objserver.o
	gcc -shared -o $@ objserver.o
	
objserver.o: objserver.cpp
	g++ -fPIC -c objserver.cpp

test2: TheMainServer.cpp
	g++ -o $@ TheMainServer.cpp

#libobjserver.a: objserver.o
#	ar rc libobjserver.a objserver.o
#	ranlib libobjserver.a
	
	
	

clean:
	rm -f *.0 *~ *.so $(PROGS)


