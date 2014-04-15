/*
 * File:	client.c
 * Description:	Simple TCP/IP client from Peterson and Davie
 *
 * expect a server response for every line sent
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>

#include <fstream>
#include <iostream>
#define SERVER_PORT	27015
#define MAX_LINE	1024

using namespace std;

	const char* DEFAULT_PORT = "27015";
	int DEFAULT_BUFLEN = 1024;

	int iResult = 0;
	int iSendResult = 0;
	
	
int  sendThis(string msgstring, int ClientSocket)
		{
			//convert string to char
			char *cinstr=new char[msgstring.size()+1];
			cinstr[msgstring.size()]=0;
			memcpy(cinstr,msgstring.c_str(),msgstring.size());	
			char *recvbuf = new char[DEFAULT_BUFLEN];
			int recvbuflen = DEFAULT_BUFLEN; 
			// Receive until the peer shuts down the connection
			do {
				//send the command/instruction to server
				iSendResult = send( ClientSocket, cinstr, msgstring.size()+1, 0 );
				if (iSendResult < 0) {
					close(ClientSocket);
					return 1;
				}

				iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
				if (iResult > 0) {

					//		printf("Bytes received: %s\n", recvbuf);
					if(recvbuf[0] == 'e')
					{
						//Msg is wrong, exit with error code
						printf("Invalid intruction input");
					}
					else if(recvbuf[0] =='f')
					{       printf("Recv complete. Connection closing...\n");			}
					else{}

				}
				else if (iResult == 0)
					printf("Connection closing...\n");
				else  {
					return 1;
				}

			} while (iResult > 0 && (recvbuf[0] !='e' && recvbuf[0] !='f') );

		}

	int  recvThis(int ClientSocket)
		{		cout << "TETERPOIER" << endl;
			int ret = 0; int num = 0;
			char *recvbuf = new char[DEFAULT_BUFLEN];
			int recvbuflen = DEFAULT_BUFLEN; 
			//Open File for data storage
			ofstream ofile("fwrite_test1", ios::out | ios::binary );
			int index;
			int rcount = 0;
			// Receive until the peer shuts down the connection
			do {
				rcount++;cout << "TETst" << endl;
		//		memset(recvbuf, 0, DEFAULT_BUFLEN);
				iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
				if (iResult > 0) {
				printf("\n");
				ofile.write(recvbuf, iResult);
				num += iResult;
				printf("num:%d  ret:%d \n", num, ret);
				}
				else if (iResult == 0)
					printf("11Connection closing...\n");
				else  {
					close(ClientSocket);
					return 1;
				}

			
		} while (iResult > 0);
		//		fclose(pFile);
		ofile.close();
		cout << "TETERPOIER" << endl;
		delete[] recvbuf;
		return ret;
	}

/*

				for (int i=0; i<DEFAULT_BUFLEN; i++)
				{
					if((recvbuf[i] == 102)  )
					{	
						if(recvbuf[i+1] == 102)
						{
							if(recvbuf[i+2] == 102)
							{
								if(recvbuf[i+3] == 102)
								{
									if(recvbuf[i+4] == 102)
									{		
										if(ret == 0)
										{
											int temp = 512*rcount;cout << "rarwar\n" << endl;
										
											ret = temp - 512 + i;//this is wrong
											printf("num:%d  ret:%d \n", num, ret);
										}
										iResult = 0;
									}
								}
							}
						}
						
					}
				}
*/
int main(int argc, char *argv[])
{
  FILE *fp;
  struct hostent *hp;
  struct sockaddr_in sin;
  char *host;
  char buf[MAX_LINE];
  int s;
  int len;

  if (argc == 2) {
    host = argv[1];
  } else {
    fprintf(stderr, "usage: %s host\n", argv[0]);
    exit(1);
  }

  /*
   * Translate host name into peer's IP address
   */
  if ((hp = gethostbyname(host)) == NULL) {
    fprintf(stderr, "%s: unknown host %s\n", argv[0], argv[1]);
    exit(1);
  }

  /*
   * Initialize the address data structure
   */
  memset((void *)&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  memcpy((void *)&sin.sin_addr, hp->h_addr, hp->h_length);
  sin.sin_port = htons(SERVER_PORT);
	
  /*
   * Create a socket
   */
  if ((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
    perror("socket");
    exit(1);
  }

  /*
   * Create a connection between the socket and the server
   */
  if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
    perror("connect");
    exit(1);
  }


  while (fgets(buf, sizeof(buf), stdin) != NULL) 
  {
     
     sendThis((string)buf, s);
     recvThis(s);
  

      fprintf(stderr, "\n>>");

  }
  
}

/*
 * End client.c
 */
