

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

#define SERVER_PORT	27015
// #define MAX_PENDING	5

// #define SERVER_PORT    5791
#define MAX_PENDING     1
#define MAX_LINE	256

extern int startCollecting(int servSocket);
extern int gotWDebug(int servSocket);
extern int fileCollecting(int servSocket);

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
int status;
srand(time(0));
std::cout << "under srrand" << std::endl;

	while ((len = recv(new_s, buf, sizeof(buf), 0)) > 0)
	{
	std::cout << buf<< std::endl;
	if(buf[0] == 'w'){ 
		pid_t pid = fork();
		if(pid == 0){
			std::cout << "gotwdebug" << std::endl;
			gotWDebug(new_s);
			std::cout << "Terminating gotwdebug" << std::endl;
			_exit(0);
		}
		else{
			std::cout << "parent gwd" << std::endl;
			pid_t pid2 = fork();
			if(pid2 == 0){
				len = recv(new_s, buf, sizeof(buf), 0);
				if(buf[0] == 'c'){
					std::cout << "Killing gotwdebug" << std::endl;
					kill(pid,SIGTERM);
				} 
			}
			waitpid(pid, &status, WNOHANG);
			if(WIFEXITED(status)){
				std::cout << "killing killer" << std::endl;
				kill(pid2,SIGTERM);
			}	
		}
	}
	else if(buf[0] == 's'){ 
		pid_t pid = fork();
		if(pid == 0){
			std::cout << "startCollecting" << std::endl;
			startCollecting(new_s);
			std::cout << "Terminating collector" << std::endl;
			_exit(0);
		}
		else{
			std::cout << "parent collector" << std::endl;
			pid_t pid2 = fork();
			if(pid2 == 0){
				len = recv(new_s, buf, sizeof(buf), 0);
				if(buf[0] == 'c'){
					std::cout << "Killing collector" << std::endl;
					kill(pid,SIGTERM);
				} 
			}
			waitpid(pid, &status, WNOHANG);
			if(WIFEXITED(status)){
				std::cout << "Killing killer" << std::endl;
				kill(pid2,SIGTERM);
			}
		}
	}
	else if(buf[0] == 'r'){ 
		pid_t pid = fork();
		if(pid == 0){
			std::cout << "fileCollecting" << std::endl;
			fileCollecting(new_s);
			std::cout << "Terminating collector" << std::endl;
			_exit(0);
		}
		else{
			std::cout << "parent collector" << std::endl;
			pid_t pid2 = fork();
			if(pid2 == 0){
				len = recv(new_s, buf, sizeof(buf), 0);
				if(buf[0] == 'c'){
					std::cout << "Killing collector" << std::endl;
					kill(pid,SIGTERM);
				} 
			}
			waitpid(pid, &status, WNOHANG);
			if(WIFEXITED(status)){
				std::cout << "Killing killer" << std::endl;
				kill(pid2,SIGTERM);
			}
		}
	}
	else{
	
	        std::cout << "no hits" << "else";

	}
	std::cout << "out of while loop" << std::endl;

	}
    close(new_s);
  }
}
