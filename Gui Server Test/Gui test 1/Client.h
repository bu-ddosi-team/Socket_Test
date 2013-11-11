#include "stdafx.h"
#ifndef CLIENT
#define CLIENT
//
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdio>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

using namespace std;

int parameters;

double ClientRun(int parameters)
{
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    char *sendbuf;// = "this is a test";
	int fileSize;

	char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    memset(recvbuf, 0, 512);

	//Open the file to record requested data
	FILE * pFile;
	pFile = fopen ("fwrite_test.txt", "wb");
    
    int iResult;
    
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo("155.41.24.99", DEFAULT_PORT, &hints, &result); //"155.41.91.123"
    if ( iResult != 0 ) {
		printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, 
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }

        // Connect to server.
        iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }

   	 clock_t start = std::clock();
	 double duration;

	 // Send an initial buffer
	 if(parameters > 100)
	 {
		 sendbuf ="fileSize, 0 );iResult = send( ConnectSocket, sendbuf, fileSize, 0 );";
	 }
	 else if(parameters > 70)
	 {
		 sendbuf ="fourteen1414";
	 }
	 else if(parameters > 30)
	 {
		 sendbuf ="six66";
	 }
	 else
	 {
		 sendbuf ="444";
	 }
	 
	 
	 iResult = send( ConnectSocket, sendbuf, sizeof(sendbuf), 0 );

    if (iResult == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    //printf("Bytes Sent: %ld\n", iResult);

    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);

    if (iResult == SOCKET_ERROR) {
        //printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    // Receive until the peer closes the connection
    do {

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 )
		{
			fwrite (recvbuf , sizeof(char), sizeof(recvbuf), pFile);
			memset(recvbuf, 0, 512);
		}
         // printf("Bytes received: %d\n", iResult);
		else if ( iResult == 0 )
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());

    } while( iResult > 0 );
	fclose(pFile);				//Close the File

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	cout<<"printf: "<< duration <<'\n';
	double throughput = (double)(((double)fileSize/1000000)/duration);
	cout << "Throughput: " << throughput << endl;
    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return throughput;
}

#endif