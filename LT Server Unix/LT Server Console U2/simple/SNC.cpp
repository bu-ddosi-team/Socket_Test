

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
#include <signal.h>
#include <sys/wait.h>
#include <exception>
//#include "DsauServer.h"


#define SERVER_PORT	27015
// #define MAX_PENDING	5


#define MAX_PENDING     1
#define MAX_LINE	512


typedef struct Control
{
	int nSweep;
	double dSweep;
	double minF;
	double maxF;
	int nStep;
	int nSample;
	char *C_sweep;
	char *C_step;
	char *C_sample;
	char *C_delay;
	char *C_min;
	char *C_max;	
}Control; 	


extern int startCollecting(int servSocket);
extern int gotRandDebug(int servSocket);
extern int fileCollecting(int servSocket);
extern	double d_getPCVal(char*);
extern	int i_getPCVal(char*);
//////////////////////
extern int writeToAddr(int new_s, char addrloc, Control& param, char *buf);
extern int isValid(int addrloc, int iVal, double dVal);
extern int a_getPCVal(int *iVal, double *dVal, char addrloc, char *buf);
extern int loadSavedSettings(char *fileName, Control& settings);
extern int saveToFile(char *fileName, Control settings);
extern int readFromAddress(int new_s, char addrloc, int *iVal, double *dVal, int *type, Control& settings);
extern int startCollecting(int new_s);
//////////////////////////////////////////////////////////////////////////////////

//#define rdtsc(x)      __asm__ __volatile__("rdtsc \n\t" : "=A" (*(x)))
unsigned long long start, finish;
unsigned long long beg, end;

//

Control param; 
//
int S_Handler(int new_s, char *buf){
	int status, len;			     
	pid_t pid = fork();
	if(pid == 0){
		std::cout << "startCollecting" << std::endl;
//		rdtsc(&start);	
		startCollecting(new_s);
//		rdtsc(&finish);
//		double rtime = ((double)(finish-start))/(double)250000000; 
//		std::cout << "scan performance:" << rtime << std::endl;
		std::cout << "Terminating child start collector" << std::endl;
		_exit(0);
	}
	else{
		std::cout << "parent start collector" << std::endl;
		pid_t pid2 = fork();
		if(pid2 == 0){
			len = recv(new_s, buf, sizeof(buf), 0);
			if(buf[0] == 'c'){
				std::cout << "Killing start collector" << std::endl;
				kill(pid,SIGTERM);
			} 
		}
		waitpid(pid, &status, WNOHANG);
		if(WIFEXITED(status)){
			std::cout << "Killing startCollecting killer" << std::endl;
			kill(pid2,SIGTERM);
		}
	}
	
}
//////////////////////////////////////
int main(int argc, char *argv[])
{
//  Control param; 
//  debuggingalone();
  
  uint32_t ubsend[MAX_LINE];
  struct sockaddr_in sin;
  char buf[MAX_LINE];
  char reply[MAX_LINE];
  int conn, line;
  int len;
  int s, new_s;
  int c_one = 1;
  int rc;
  printf("Starting Server...\n");

  //Initialize the addres data structure
  memset((void *)&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = INADDR_ANY;
  sin.sin_port = htons(SERVER_PORT);

  //Create a socket
  if ((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
    fprintf(stderr, "%s: socket - %s\n", argv[0], strerror(errno));
    exit(1);
  }

  // set the "reuse" option 
  rc = setsockopt( s, SOL_SOCKET, SO_REUSEADDR, &c_one, sizeof(c_one));

  //Bind an address to the socketh 
  if (bind(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
    fprintf(stderr, "%s: bind - %s\n", argv[0], strerror(errno));
    exit(1);
  }

  
  //Set the length of the listen queue  
  if (listen(s, MAX_PENDING) < 0) {
    fprintf(stderr, "%s: listen - %s\n", argv[0], strerror(errno));
    exit(1);
  }

  conn = 0;

  //Loop accepting new connections and servicing them
  while (1) 
  {
    len = sizeof(sin);
    if ((new_s = accept(s, (struct sockaddr *)&sin, (socklen_t*)&len)) < 0) {
      fprintf(stderr, "%s: accept - %s\n",
	      argv[0], strerror(errno));
      fprintf(stderr, "%s: Connection Failed - %s\n");
//      exit(1);
    }
    else
    {
    printf("New connection on fd:%d\n",new_s);
    ++conn;
    line = 0;
/////////////////////////////////////////////////
//////////////////////////////////////////////////
//char f = 'f';
int status;
//srand(time(0));

	char *sendbuf;// = "this is a test";
	int fileSize;
	char f = 'f';
	char buf[MAX_LINE];
	 char reply[MAX_LINE];
 	 int conn, line;
 	 int len;
 	 int s;
  	int strSize = MAX_LINE;

//DsauServer param;
std::cout << "Starting persistent connection" << std::endl;
    	char *sendf= new char[MAX_LINE];
	sprintf( sendf, "%c", f);
	len = strlen( sendf);
	sprintf( reply, "%s", "ffffffffff");
	   
        int argc = 0; int kk = 0;
        char *token;
        char **args;
        char *buf9;		
        std::cout << "NOT FAULT";
	while ( len = recv(new_s, buf, sizeof(buf), 0) && new_s > 0)
	{

	for( kk = 0; kk < argc; kk++)	
	{	
		if(buf[0] == 's'){ 
//			S_Handler(new_s, buf);
				std::cout << "startCollecting" << std::endl;
//				rdtsc(&start);	
				
				startCollecting(new_s);
				std::cout << "endCollecting" << std::endl;
				
//				rdtsc(&finish);
//				double rtime = ((double)(finish-start))/(double)250000000; 					std::cout << "scan performance:" << rtime << std::endl;
//				double throu = (10000/2)/ (rtime*1000000); 
//				std:: cout << "speed estimation:" << throu << std::endl;
				break;
		}

		else if(buf[0] == 'w'){ 

				char addrloc = buf[1];
				writeToAddr(new_s, addrloc, param, buf9);
				send( new_s, reply, strlen(reply), 0);
		}
		else if(buf[0] == 'r'){ 

				char addrloc = buf[1];
				int iVal, type;
				double dVal;
				readFromAddress(new_s, addrloc, &iVal, &dVal, &type, param);
				send( new_s, reply, strlen(reply), 0);
		}			
		else{
			std::cout << "no hits...What to do? \n";
		}
	}
	std::cout << "______________________________________________________\n" << std::endl;	
	std::cout << "waiting on client...\n" << std::endl;
    	memset(buf, 0, MAX_LINE);

	} //end while(recv)
	std::cout << "Closing socket" << std::endl;
    close(new_s);
    }//end accept else
  } //end while(1)p

}






