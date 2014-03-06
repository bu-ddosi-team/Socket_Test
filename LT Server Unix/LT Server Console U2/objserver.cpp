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


struct sockserv
{
	/* data */
};
#define MAX_LINE	256
//Temp main
int main( int argc, char* argv[])
{

	int var1, var2;
	pid_t pid;
	
	pid = fork();
	
	
	if(pid == 0)//do child. startCollecting
	{
		printf("%s\n","Starting Collection");	
//		startCollecting();
	
	}
	else //resume
	{
	
	
	}


}

int gotWDebug(int new_s)
{
	char *sendbuf;// = "this is a test";
	int fileSize;
	char f = 'f';
	char buf[MAX_LINE];
	  char reply[MAX_LINE];
 	 int conn, line;
 	 int len;
 	 int s;
  	int strSize = MAX_LINE;
  	
  	int rnum;
int mnum;
char mtype;
int setting = 10000;


	    std::cout << "w is hit" << std::endl;
	    while ( line < 1000) {
	      rnum = rand()%setting;
	      mnum = rand()%1000;
		if(mnum == 0){mtype = 'f';}
		else if(mnum == 1){mtype = 'e';}
		else {mtype = 'b';}
	      ++line;

	      sprintf( reply, "%c%d\n", mtype, rnum);
	      len = strlen( reply);

	      send( new_s, reply, len, 0);
	    }
	      sprintf( reply, "%c", f);
	      len = strlen( reply);
	      send( new_s, reply, len, 0);
}



int startCollecting(int new_s)
{

	char *sendbuf;// = "this is a test";
	int fileSize;
	char f = 'f';
	char buf[MAX_LINE];
	  char reply[MAX_LINE];
 	 int conn, line;
 	 int len;
 	 int s;
  	int strSize = MAX_LINE;
  	
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






