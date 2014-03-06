
#define SEND_BINARY

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
#define SEND_BINARY

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <fstream>
#include <iostream>
#include <cstdio>
#include <time.h>
#include <ctime>


#define SERVER_PORT	27015
// #define MAX_PENDING	5

// #define SERVER_PORT    5791
#define MAX_PENDING     1
#define MAX_LINE	256

int
main(int argc, char *argv[])
{
  
  uint32_t ubsend[MAX_LINE];
  
  struct sockaddr_in sin;
  char buf[MAX_LINE];
  char reply[MAX_LINE];
  int conn, line;
  int len;
  int s, new_s;
  int c_one = 1;
  int rc;

  /*
   * Initialize the addres data structure
   */
  memset((void *)&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = INADDR_ANY;
  sin.sin_port = htons(SERVER_PORT);

  /*
   * Create a socket
   */
  if ((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
    fprintf(stderr, "%s: socket - %s\n", argv[0], strerror(errno));
    exit(1);
  }

  /* set the "reuse" option */
  rc = setsockopt( s, SOL_SOCKET, SO_REUSEADDR, &c_one, sizeof(c_one));

  /*
   * Bind an address to the socket
   */
  if (bind(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
    fprintf(stderr, "%s: bind - %s\n", argv[0], strerror(errno));
    exit(1);
  }

  /*
   * Set the length of the listen queue
   */
  if (listen(s, MAX_PENDING) < 0) {
    fprintf(stderr, "%s: listen - %s\n", argv[0], strerror(errno));
    exit(1);
  }

  conn = 0;

	char *sendbuf;// = "this is a test";
	int fileSize;
//	ifstream file;
  /*
   * Loop accepting new connections and servicing them
   */
  while (1) {
    len = sizeof(sin);
    if ((new_s = accept(s, (struct sockaddr *)&sin, (socklen_t*)&len)) < 0) {
      fprintf(stderr, "%s: accept - %s\n",
	      argv[0], strerror(errno));
      exit(1);
    }

    printf("New connection\n");
    ++conn;
    line = 0;
/////////////////////////////////////////////////
//////////////////////////////////////////////////
int	strSize = MAX_LINE;
int rnum;
int mnum;
char mtype;
int setting = 10000;
char f = 'f';
srand(time(0));
std::cout << "under srrand" << std::endl;
	while ((len = recv(new_s, buf, sizeof(buf), 0)) > 0)
	{
	std::cout << buf<< std::endl;
	if(buf[0] == 'w'){ 
	    std::cout << "w is hit" << std::endl;
	    while ( line < 1000) {
	      rnum = rand()%setting;
	      mnum = rand()%1000;
		if(mnum == 0){mtype = 'f';}
		else if(mnum == 1){mtype = 'e';}
		else {mtype = 'b';}
	      ++line;
	#ifdef BINARY_DATA
	      for( int i=0; i<MAX_LINE; i++)
		reply[i] = i ^ 0xff;
	      len = MAX_LINE;
	#else
	      sprintf( reply, "%c%d\n", mtype, rnum);
	      len = strlen( reply);
	#endif
	      send( new_s, reply, len, 0);
	    }
	      sprintf( reply, "%c", f);
	      len = strlen( reply);
	      send( new_s, reply, len, 0);
	}
	else if(buf[0] == 's'){ 
  	   std::cout << "s is hit" << std::endl;
	   sprintf( reply, "%c", f);
	   len = strlen( reply);
	   send( new_s, reply, len, 0);
//	   std::ifstream file ("111.txt", std::ifstream::in | std::ios::binary);
//	   if (file.is_open())
//		  {
			//  sendbuf = new char[strSize];
			// send//
		 int my_id[100] = {0};
		 int my_net_id[100];// = htonl(my_id);
//		 send(new_s, (const char*)&my_net_id, 4, 0);
		char integer[100];                  // buffer
		int integerl[100];
		for (int i=0; i<100; i++) {
			integerl[i] = (int)(10000*(double)cos((double)(i/30)+1.6));
			integerl[i] =(int)(10000*(double)cos((double)(i/30)));
		}

			uint32_t un = htonl((int)integerl);
			send(new_s, &un, sizeof(uint32_t)*100, 0);
			std::cout << un <<std::endl;	

//			  file.close();


			      char *sendf= new char[strSize];
			      sprintf( sendf, "%c", f);
			      len = strlen( sendf);
			      send( new_s, sendf, len, 0);
			      std::cout << "test";
//		  }
		std::cout << "test2";
	}
	else{
	
        std::cout << "no hits" << "else";
//	int myInt = something;    ////////////////////////////////////
//	int tmp = htonl((uint32_t)myInt);////////////////////////
//	write(socket, &tmp, sizeof(tmp));/////////////////////////////
//		uint32_t *bbb; 
//				std::cout << bbb;	
//		char *test = new char[512];
//				std::cout << bbb;	
//		sprintf(test, "%c%c%c%c",f,f,f,f);
//		std::cout << bbb;	
//		memcpy(bbb,test,4);
//		std::cout << bbb;

	}
	std::cout << "out of while loop" << std::endl;

	line = 0;
	}
    close(new_s);
  }
}