


class TCP1{


public:


			// Initialize Winsock
    // Resolve the server address and port
        // Create a SOCKET for connecting to server
        // Connect to server.
	 // Send an initial buffer
    // shutdown the connection since no more data will be sent
	getHostAddress()			//do we need set port/address
		getHostPort()
		
		getClientAddress()
		getClientPort()

		InitializeSocket()

		Connect()

		send()
		recv()

		Shutdown();




};
	   WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;


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
    iResult = getaddrinfo("192.168.0.2", DEFAULT_PORT, &hints, &result); //"155.41.91.123"
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



	 // Send an initial buffer
	 if(parameters > 100)
	 { sendbuf ="If param is > 100 then the Server should send me text file 111.txt";	 }
	 else if(parameters > 70)
	 { sendbuf ="this should get file 2"; }
	 else if(parameters > 30)
	 { sendbuf ="file3"; }
	 else
	 {	 sendbuf ="4b";	 }
	 //Temporarily using the length of the string as the input to choose files
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
	 clock_t start = std::clock();
	 double duration;
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
	double throughput = (double)(((double)(fileSize/1000000)/duration)*8);
	cout << "Throughput: " << throughput << endl;
    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return throughput;
}
