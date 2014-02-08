
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
	if(buf[0] == 's'){ 
	    std::cout << "s is hit" << std::endl;
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
	else if(buf[0] == 'w'){ 
  	   std::cout << "w is hit" << std::endl;
	   sprintf( reply, "%c", f);
	   len = strlen( reply);
	   send( new_s, reply, len, 0);
	   std::ifstream file ("111.txt", std::ifstream::in | std::ios::binary);
	   if (file.is_open())
		  {
			//  sendbuf = new char[strSize];
			// send
		char integer[100];                  // buffer
		for (int i=0; i<100; i++) {
			if (i%2==0) {			
			
			(integer[i]) =(int)(10000*(double)cos((double)(i/30)+1.6));;       
			
			}
			else{
			(integer[i]) =(char)(10000*(double)cos((double)(i/30)));
			}
			send( new_s, integer, 100, 0 );        // send it
		}
/*			
			  int sBuf[100];
			  for (int i=0; i<100; i++) {
			  	if (i%2==0) {
//					sBuf[i]=i;
			  		sBuf[i]=(char)(10000*(double)cos((double)(i/30)+1.6));
//			  		sBuf[i]=(int)(10000*(double)sin((double)(i/30)));
			  	}
				else {
			  		sBuf[i]=(char)(10000*(double)cos((double)(i/30)));
			  	}
			  }
			  	
				int sss = send( new_s, (char*)sBuf, 100, 0);
*/
			  file.close();

//	sleep(5);
			      char *sendf= new char[strSize];
			      sprintf( sendf, "%c", f);
			      len = strlen( sendf);
			      send( new_s, sendf, len, 0);
			      std::cout << "test";
		  }
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
/***************************************************************************************
int main(int argc, char *argv[])
{
//	pthread_t t1, t2;
//	pthread_create( &t1, NULL, theserver, NULL);
//	pthread_create( &t2, NULL, datain, NULL);



 struct sockaddr_in sin;
  char buf[MAX_LINE];
  char reply[MAX_LINE];
  int conn, line;
  int len;
  int s, new_s;
  int c_one = 1;
  int rc;

  //
  // Initialize the addres data structure
  ///
  memset((void *)&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = INADDR_ANY;
  sin.sin_port = htons(SERVER_PORT);

  //
 // Create a socket
  //
  if ((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
    fprintf(stderr, "%s: socket - %s\n", argv[0], strerror(errno));
    exit(1);
  }

 // set the "reuse" option
  rc = setsockopt( s, SOL_SOCKET, SO_REUSEADDR, &c_one, sizeof(c_one));

  //
   // Bind an address to the socket
   //
  if (bind(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
    fprintf(stderr, "%s: bind - %s\n", argv[0], strerror(errno));
    exit(1);
  }

  //
   // Set the length of the listen queue
   //
  if (listen(s, MAX_PENDING) < 0) {
    fprintf(stderr, "%s: listen - %s\n", argv[0], strerror(errno));
    exit(1);
  }

  conn = 0;


   //Loop accepting new connections and servicing them

  while (1) {
    len = sizeof(sin);
    if ((new_s = accept(s, (struct sockaddr *)&sin, &len)) < 0) {
      fprintf(stderr, "%s: accept - %s\n",
	      argv[0], strerror(errno));
      exit(1);
    }
    ++conn;
    line = 0;
    while ((len = recv(new_s, buf, sizeof(buf), 0)) > 0) {
      ++line;
      if (len >= MAX_LINE) {
	len = MAX_LINE - 1;
      }
      buf[len] = 0;
      fputs(buf, stdout);
      // now send the reply
      sprintf( reply, "Connection %d Line %d length=%d\n",
	       conn, line, len);
      len = strlen( reply);
      send( new_s, reply, len, 0);
    }
    close(new_s);
  }

	return 0;
}//////////////////////
*///////////////////////////////////////////////////////////////////////////////////


////////////////////////////

//int * theserver(void)
//{


//	WSADATA wsaData;
//    int iResult;
//	int parameters;
//    SOCKET ListenSocket = INVALID_SOCKET;
//    SOCKET ClientSocket = INVALID_SOCKET;

//    struct addrinfo *result = NULL;
//    struct addrinfo hints;
//
//	//char *sendbuf;// = "this is a test";
//	//int fileSize;
// //   ifstream file;

//    int iSendResult;
//    char recvbuf[DEFAULT_BUFLEN];
//    int recvbuflen = DEFAULT_BUFLEN;
//    memset(recvbuf, 0, 512);



//

//	// Initialize Winsock
//    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
//    if (iResult != 0) {
//        printf("WSAStartup failed with error: %d\n", iResult);
//        return 1;
//    }

//    ZeroMemory(&hints, sizeof(hints));
//    hints.ai_family = AF_INET;
//    hints.ai_socktype = SOCK_STREAM;
//    hints.ai_protocol = IPPROTO_TCP;
//    hints.ai_flags = AI_PASSIVE;

//    // Resolve the server address and port
//    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
//    if ( iResult != 0 ) {
//        printf("getaddrinfo failed with error: %d\n", iResult);
//        WSACleanup();
//        return 1;
//    }

//    // Create a SOCKET for connecting to server
//    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
//    if (ListenSocket == INVALID_SOCKET) {
//        printf("socket failed with error: %ld\n", WSAGetLastError());
//        freeaddrinfo(result);
//        WSACleanup();
//        return 1;
//    }

//    // Setup the TCP listening socket
//    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
//    if (iResult == SOCKET_ERROR) {
//        printf("bind failed with error: %d\n", WSAGetLastError());
//        freeaddrinfo(result);
//        closesocket(ListenSocket);
//        WSACleanup();
//        return 1;
//    }

//    freeaddrinfo(result);

//    iResult = listen(ListenSocket, SOMAXCONN);
//    if (iResult == SOCKET_ERROR) {
//        printf("listen failed with error: %d\n", WSAGetLastError());
//        closesocket(ListenSocket);
//        WSACleanup();
//        return 1;
//    }

//    // Accept a client socket
//    ClientSocket = accept(ListenSocket, NULL, NULL);
//    if (ClientSocket == INVALID_SOCKET) {
//        printf("accept failed with error: %d\n", WSAGetLastError());
//        closesocket(ListenSocket);
//        WSACleanup();
//        return 1;
//    }

//    // No longer need server socket
//    closesocket(ListenSocket);


//	clock_t start;
//    double duration;
//    start = std::clock();
//
//	bool inputget = FALSE;
//    // Receive until the peer shuts down the connection
//	do {
//		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
//		if (iResult > 0)
//		{
//			//if(iResult <= 4)
//			//{
//			//	file.open("C:\\Users\\Yan Zhang\\Desktop\\Client\\111.txt", ios::in | ios::binary);
//			//	inputget = TRUE;
//			//}
//			//else if(iResult <= 8)
//			//{
//			//	file.open("C:\\Users\\Yan Zhang\\Desktop\\Client\\444.txt", ios::in | ios::binary);
//			//	inputget = TRUE;
//			//}
//			//else if(iResult <= 16)
//			//{
//			//	file.open("C:\\Users\\Yan Zhang\\Desktop\\Client\\333.txt", ios::in | ios::binary);
//			//	inputget = TRUE;
//			//}
//			//else if(iResult <= 32 )
//			//{
//			//	file.open("C:\\Users\\Yan Zhang\\Desktop\\Client\\222.txt", ios::in | ios::binary);
//			//	inputget = TRUE;
//			//}
//			//else
//			//{
//			//	file.open("C:\\Users\\Yan Zhang\\Desktop\\Client\\555.txt", ios::in | ios::binary);
//			//	inputget = TRUE;
//			//}

//		}
//        else if (iResult == 0)
//            printf("Connection closing...\n");
//        else  {
//            printf("recv failed with error: %d\n", WSAGetLastError());
//            closesocket(ClientSocket);
//            WSACleanup();
//            return 1;
//        }
//    } while ( (iResult > 0) && (inputget = FALSE) );

///////////////////////////////////////////////////////////////FILE OPEN HERE
///*	  int	strSize = 512;
//	  if (file.is_open())
//	  {
//		  file.seekg(0,strSize);
//		  while(!file.eof())
//		  {
//		  //file.seekg(0, ios::end);
//		  //fileSize = file.tellg();
//		  //cout << "The file size is " <<  fileSize << " bytes" << endl;
//		  //file.seekg(0, ios::beg); //sets location to the beginning of the file
//		  //sendbuf = new char[fileSize];
//		  //file.read(sendbuf, fileSize); //write file to buffer
//		  //file.close();
//
//			  //use .readsome(char* s, streamsize n) in fture?
//			sendbuf = new char[strSize];
//			file.read(sendbuf, strSize);
//			fifoQ.push(sendbuf);

//			iResult = send( ClientSocket, sendbuf, fileSize, 0 );
//			if (iResult == SOCKET_ERROR)
//			{
//				printf("send failed with error: %d\n", WSAGetLastError());
//				closesocket(ClientSocket);
//				WSACleanup();
//				return 1;
//			}

//
//		  }
//		  file.close();
//	  }
//*/
//	//BEGIN SEND FILE
//	while(file.is_open())
//	{
//		if(!fifoQ.empty){

//			iResult = send( ClientSocket, fifoQ.pop(), fileSize, 0 );
//			if (iResult == SOCKET_ERROR) {
//				printf("send failed with error: %d\n", WSAGetLastError());
//				closesocket(ClientSocket);
//				WSACleanup();
//				return 1;
//			}
//		}
//
//	}
//	    // shutdown the connection since no more data will be sent
//    iResult = shutdown(ClientSocket, SD_SEND);

//    if (iResult == SOCKET_ERROR) {
//        //printf("shutdown failed with error: %d\n", WSAGetLastError());
//        closesocket(ClientSocket);
//        WSACleanup();
//        return 1;
//    }


//	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;


//	 double throughput = (double)((((double)fileSize/1000000)/duration)*8);
//	cout << "Throughput: " << throughput << endl;
//
//	 // shutdown the connection since we're done
//    iResult = shutdown(ClientSocket, SD_SEND);
//    if (iResult == SOCKET_ERROR) {
//        printf("shutdown failed with error: %d\n", WSAGetLastError());
//        closesocket(ClientSocket);
//        WSACleanup();
//        return 1;
//    }

//    // cleanup
//    closesocket(ClientSocket);
//    WSACleanup();

//    return throughput;
//
//}
//


/*
void * datain(void)
{

	//char *sendbuf;// = "this is a test";
	//int fileSize;
 //   ifstream file;

	int	strSize = 512;

	  if (file.is_open())
	  {
		  file.seekg(0,strSize);
		  while(!file.eof() && (fifoQ.size() > 10) )
		  {
			  //use .readsome(char* s, streamsize n) in fture?
			sendbuf = new char[strSize];
			file.read(sendbuf, strSize);
			fifoQ.push(sendbuf);
			file.seekg((strSize+1), (strSize+512) );
		  }
		  file.close();
	  }

}
*/



