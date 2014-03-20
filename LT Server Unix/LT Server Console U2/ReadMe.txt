
dDOSI Server Code


Type make in current directory to build server files. 
Type ./test or sh server.sh to run server.


The main server file is TheMainServer.cpp
The function implementations are defined in DsauServer.cpp

The server function are defined and explained in DsauServer.h (Though the file is not currently used as the function implementations have not been linked with the class yet.)


-------------------------------------------------------------------------------------
Testing without the GUI:-------------------------------------------------------------
You can test server functions with the SocketTest client. Just run the server from the terminal and connect to Port 27015 leaving the IP Address field at 127.0.0.1 on the SocketTest client. 


-------------------------------------------------------------------------------------
Information Regarding Packet Format--------------------------------------------------
The packet is composed of three sections. 
The first section is the message type, which is represented by the first character of the packet.
The second section is the address location, which is represented by the second character of the packet.
The third section is the data section. It composes of the rest of the packet.


-------------------------------------------------------------------------------------
Information Regarding Message Types--------------------------------------------------
message types supported (all lowercase): s, w, r, t, f
s[][]		-get cos and sin values
t[][]		-get a sequence of random numbers with random response messages
f[][]		-get a file from the server
r[char][]	-get the current value at the address location.
w[char][number]	-update value at address location to value defined in data portion of packet.

The s, t, and f message types do not require anything in the address and data sections of the packet.

The r message type currently takes in a char value in the address section of the packet. Currently, the server only recognizes the characters a-f, each representing one of the 6 values below. Any other character value should return an error message to the client.  
Number of Sweeps		'a'
Number of Steps			'b'
Number of Samples		'c'
Delay between Sweeps		'd'
Minimum Frequency		'e'
Maximum Frequency		'f'


The w message type takes in a char value for the address and a string of numbers for the data section. Like r, w only accepts address values between a and f. address values a, b, and c work with integers while d, e, f work with doubles. 

Currently, there are no checks to make sure that the string contained in the data section is numeric. In the case that there is a random character or second ., the server will take the numbers before the error as the value. (e.g. 1.62t84 becomes 1.62).

Each address will only accept values within the range specified for each address location. Otherwise, an error will be returned. These ranges can be modified by changing the following defines in DsauServer.cpp:
#define maxSweep 100
#define minSweep 1
#define maxStep 400
#define minStep 10
#define maxSample 64000
#define minSample 1000
#define maxDelay 100
#define minDelay 1
#define mminF 100
#define mmaxF 100000




















