
dDOSI Server Code

Building the Server:-----------------------------------------------------------------
Type make in current directory to build server files. 
Type ./test or sh server.sh to run server.


The main server file is TheMainServer.cpp
The function implementations are defined in DsauServer.cpp

The server functions are defined and explained below as well as in DsauServer.h (Though the file is not currently used as the function implementations have not been linked with the class yet.)


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

s t f -------------------------------------------------------------------------------
The s, t, and f message types do not require anything in the address and data sections of the packet.

r------------------------------------------------------------------------------------
The r message type currently takes in a char value in the address section of the packet. Currently, the server only recognizes the characters a-f, each representing one of the 6 values below. Any other character value should return an error message to the client.  
Number of Sweeps		'a'
Number of Steps			'b'
Number of Samples		'c'
Delay between Sweeps		'd'
Minimum Frequency		'e'
Maximum Frequency		'f'

TODO:
Gains				'g'
Laser Diode Settings		'h'

w------------------------------------------------------------------------------------
The w message type takes in a char value for the address and a string of numbers for the data section. Like r, w only accepts address values between a and f. address values a, b, and c work with integers while d, e, f work with doubles. 

Currently, there are no checks to make sure that the string contained in the data section is numeric. In the case that there is a random character or second '.', the server will take the numbers before the error as the value. (e.g. 1.62t84 becomes 1.62). This will be added later.

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



-------------------------------------------------------------------------------------
Information on Server Functions:-----------------------------------------------------

All the functions return an int to use for error code handling, though this has not been implemented for most of them yet.

Parameters to note:
int new_s:	 	The Socket file descripter for the current connection.
char buf:		Packet that was recieved from the client
char addrloc:		Address specificied by the second character in buf
DsauServer Settings: 	Class object containing the parameters.
int iVal:		Integer Value of a parameter found at 'a', 'b', or 'c' 
double dVal:		Double Value of a parameter found at  'd', 'e', or 'f' 
int type:		Type of response. Ignored for now.

Functions:
int loadSavedSettings(char *fileName, DsauServer& settings);-------------------------
	loadSavedSettings opens the file containing setting information and loads the data into the DsauServer object. This will probably be replaced later on with functions that communicate with the firmware to get the actual information.

int readFromAddress(int new_s, char addrloc, int *iVal, double *dVal, int *type, DsauServer& settings);-------------------------------------------------------------	
	readFromAddress currently displays and sends to the client the value of the parameter specified by addrloc. The iVal, dVal, and type parameters are currently unused in TheMainServer. 

int writeToAddr(int new_s, char addrloc, DsauServer& settings, char *buf);-----------
	writeToAddr currently writes a value into one of the corresponding parameter values specified by addrloc.


int isValid(int addrloc, int iVal, double dVal);-------------------------------------
	isValid checks if the value the user wants to write to the address location is valid or not. Returns false if not valid. 


int a_getPCVal(int *iVal, double *dVal, char addrloc, char *buf);--------------------
	a_getPCVal reads in the packet data and extracts the numeric characters from the data section of the packet. It then converts it into an int or double format depending on the addrloc. The obtained value (iVal or dVal) is then passed into isValid before the value updating the corresponding parameter value with the new value. This will probably be updated to include better handling of non numeric characters as well as additional functions to communicate with the firmware to do actual writes instead of simulations.


int saveToFile(char *fileName, DsauServer& settings);--------------------------------
	saveToFile saves the parameter settings for the DsauServer object into a file.


int startCollecting(int new_s);------------------------------------------------------
	startCollecting calculates sin and cos values and sends it to the client. This is to simulate getting data from the board.

int gotRandDebug(int new_s);---------------------------------------------------------
	gotRandDebug tells the server to send to the client a string of random numbers with randomized response message types for each random number sent. (currently uses only f, b, and e. I should probably include every possible character for full testing).

int fileCollecting(int new_s);-------------------------------------------------------
	fileCollecting reads in a specified file and sends it to the client.










