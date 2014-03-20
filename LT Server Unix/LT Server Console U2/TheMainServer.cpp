

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
#define MAX_LINE	256


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
extern int gotRandDebug(int new_s);
extern int fileCollecting(int new_s);
extern int startCollecting(int new_s);
//////////////////////////////////////////////////////////////////////////////////





Control param; 
/*
void debuggingalone()
{
  int ival, type;
  double dval;
  
  char test[] = "sd.13.s0";
  printf("Starting test...%s\n",test);
//  double test1 = i_getPCVal(test);
  if(writeToAddr(1, test[1], param, test))
  {
     printf("Write Successful... " );
    fprintf(stderr,"addr val at '%c' = %d\n",test[1], param.nSweep);
  }
  else
  {
    printf("Write Failed \n" );
  }

 
  printf("----------------------------------------\n");
  readFromAddress(1, test[1], &ival, &dval, &type, param);

}
*/
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
//try{
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
      exit(1);
    }

    printf("New connection\n");
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

std::cout << "Starting persistent connection" << std::endl;

	while ((len = recv(new_s, buf, sizeof(buf), 0)) > 0)
	{
		std::cout << "Message received: \"" << buf<< "\"" << std::endl;
		
		if(buf[0] == 's'){ 			     
			pid_t pid = fork();
			if(pid == 0){
				std::cout << "startCollecting" << std::endl;
				startCollecting(new_s);
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
		else if(buf[0] == 'w'){ 
			pid_t pid = fork();
			if(pid == 0){
				char addrloc = buf[1];
				writeToAddr(new_s, addrloc, param, buf);
				saveToFile("Control_Settings", param);
				_exit(0);
			}
			else{
				std::cout << "parent addr writer" << std::endl;
				pid_t pid2 = fork();
				if(pid2 == 0){
					len = recv(new_s, buf, sizeof(buf), 0);
					if(buf[0] == 'c'){
						std::cout << "Killing writer" << std::endl;
						kill(pid,SIGTERM);
					} 
				}
				waitpid(pid, &status, WNOHANG);
				if(WIFEXITED(status)){
					std::cout << "Killing writer killer" << std::endl;
					kill(pid2,SIGTERM);
				}
			}
		}
		else if(buf[0] == 'r'){ 
			pid_t pid = fork();
			if(pid == 0){
				char addrloc = buf[1];
				int iVal, type;
				double dVal;
				readFromAddress(new_s, addrloc, &iVal, &dVal, &type, param);
				_exit(0);
			}
			else{
				std::cout << "parent addr reader" << std::endl;
				pid_t pid2 = fork();
				if(pid2 == 0){
					len = recv(new_s, buf, sizeof(buf), 0);
					if(buf[0] == 'c'){
						std::cout << "Killing reader" << std::endl;
						kill(pid,SIGTERM);
					} 
				}
				waitpid(pid, &status, WNOHANG);
				if(WIFEXITED(status)){
					std::cout << "Killing reader killer" << std::endl;
					kill(pid2,SIGTERM);
				}
			}
		}
		else if(buf[0] == 't'){ 
			pid_t pid = fork();
			if(pid == 0){
				std::cout << "gotRandDebug" << std::endl;
				gotRandDebug(new_s);
				std::cout << "Terminating child writeToAddr" << std::endl;
				_exit(0);
			}
			else{
				std::cout << "parent gotRandDebug" << std::endl;
				pid_t pid2 = fork();
				if(pid2 == 0){
					len = recv(new_s, buf, sizeof(buf), 0);
					if(buf[0] == 'c'){
						std::cout << "Killing gotRandDebug" << std::endl;
						kill(pid,SIGTERM);
					} 
				}
				waitpid(pid, &status, WNOHANG);
				if(WIFEXITED(status)){
					std::cout << "killing gotRandDebug killer" << std::endl;
					kill(pid2,SIGTERM);
				}	
			}
		}
		else if(buf[0] == 'f'){ 
			pid_t pid = fork();
			if(pid == 0){
				std::cout << "fileCollecting" << std::endl;
				fileCollecting(new_s);
				std::cout << "Terminating child file collector" << std::endl;
				_exit(0);
			}
			else{
				std::cout << "parent file collector" << std::endl;
				pid_t pid2 = fork();
				if(pid2 == 0){
					len = recv(new_s, buf, sizeof(buf), 0);
					if(buf[0] == 'c'){
						std::cout << "Killing file collector" << std::endl;
						kill(pid,SIGTERM);
					} 
				}
				waitpid(pid, &status, WNOHANG);
				if(WIFEXITED(status)){
					std::cout << "Killing fileCollector killer" << std::endl;
					kill(pid2,SIGTERM);
				}
			}
		}				
		else{
			std::cout << "no hits...What to do? \n";
		}
	std::cout << "______________________________________________________\n" << std::endl;	
	std::cout << "waiting on client...\n" << std::endl;
    	memset(buf, 0, MAX_LINE);
	} //end while(len>0)
    close(new_s);
  } //end while(1)p

//  }//end try
//  catch(int e) {	std::cout << "int exception...\n" << std::endl;		}
//  catch(char e){	std::cout << "char exception...\n" << std::endl;	}
//  catch (const std::exception& e)  {    std::cout << e.what() << std::endl;  }
//  catch(...){	std::cout << "default exception...\n" << std::endl;	}


}
