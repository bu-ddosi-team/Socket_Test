#undef UNICODE

#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <time.h>
#include <cstdio>
#include <ctime>
#include <queue>

#include <string.h>
#include "CircularBuffer.h"
#include "memFile.h"


using namespace std;
// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"


int __cdecl main(void)
{

	char *sendbuf;// = "this is a test";
	int fileSize;
    ifstream file; 
	//Buffer Init
	memFile<char> membuff(1024);
	CircularBuffer<char, 10> cBuffer;
	queue<string> fifoQ;


	WSADATA wsaData;
    int iResult;
	int parameters;
    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL;
    struct addrinfo hints;
	
	//char *sendbuf;// = "this is a test";
	//int fileSize;
 //   ifstream file; 

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    memset(recvbuf, 0, 512);



	

	// Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Accept a client socket
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // No longer need server socket
    closesocket(ListenSocket);


	clock_t start;
    double duration;
    start = std::clock();
	
	bool inputget = FALSE;
    // Receive until the peer shuts down the connection
	do {
		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0) 
		{	

		}
        else if (iResult == 0)
            printf("Connection closing...\n");
        else  {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }
    } while ( (iResult > 0) && (inputget = FALSE) );

/////////////////////////////////////////////////////////////FILE OPEN HERE
	  int	strSize = 512;
	
file.open("C:\\Users\\Yan Zhang\\Desktop\\Client\\111.txt", ios::in | ios::binary);
	  if (file.is_open())
	  {
		  file.seekg(0,strSize);
		  while(!file.eof())
		  {
		  //file.seekg(0, ios::end);
		  //fileSize = file.tellg();
		  //cout << "The file size is " <<  fileSize << " bytes" << endl;
		  //file.seekg(0, ios::beg); //sets location to the beginning of the file
		  //sendbuf = new char[fileSize];
		  //file.read(sendbuf, fileSize); //write file to buffer
		  //file.close();
			
			  //use .readsome(char* s, streamsize n) in fture?
			sendbuf = new char[strSize];
			file.read(sendbuf, strSize);
//			fifoQ.push(sendbuf);

			
			iResult = send( ClientSocket, sendbuf, fileSize, 0 );
			if (iResult == SOCKET_ERROR) 
			{
				printf("send failed with error: %d\n", WSAGetLastError());
				do{
				iResult = send( ClientSocket, sendbuf, fileSize, 0 );
				} while( iResult != SOCKET_ERROR);
			} 

			
		  }
		  file.close();
	  }

/*	//BEGIN SEND FILE
	while(file.is_open())
	{
		if(!fifoQ.empty){

			iResult = send( ClientSocket, fifoQ.pop(), fileSize, 0 );
			if (iResult == SOCKET_ERROR) {
				printf("send failed with error: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}
		}
	
	}
*/
	    // shutdown the connection since no more data will be sent
    iResult = shutdown(ClientSocket, SD_SEND);

    if (iResult == SOCKET_ERROR) {
        //printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }


	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;


	 double throughput = (double)((((double)fileSize/1000000)/duration)*8);
	cout << "Throughput: " << throughput << endl;
	 
	 // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();

    return throughput;
	
}

