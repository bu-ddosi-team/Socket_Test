

class DsauServer{
  
	public:
		//Constructor. Note the current code is currently using a struct named Control. Just replace "DsauServer" with "Control" in this file when refering to cpp functions.
		DsauServer();
		
		//loadSavedSettings opens the file containing setting information and loads the data into the DsauServer object. 
	static	int loadSavedSettings(char *fileName, DsauServer& settings);
				
		//writeToAddr currently writes a value into one of the corresponding parameter values specified by addrloc.		
	static	int writeToAddr(int new_s, char addrloc, DsauServer& settings, char *buf);

		//readFromAddress currently displays and sends to the client the value of the parameter specified by addrloc. The iVal, dVal, and type parameters are currently unused in TheMainServer.		
	static	int readFromAddress(int new_s, char addrloc, int *iVal, double *dVal, int *type, DsauServer& settings);				
	
		//isValid checks if the value the user wants to write to the address location is valid or not. Returns false if not valid. 		
	static	int isValid(char addrloc, int iVal, double dVal);
		
		
		//a_getPCVal reads in the packet data and extracts the numeric characters from the data section of the packet. It then converts it into an int or double format depending on the addrloc. The obtained value (iVal or dVal) is then passed into isValid before the value updating the corresponding parameter value with the new value. 	
	static	int a_getPCVal(int *iVal, double *dVal, char addrloc, char *buf);
		
		
		//saveToFile saves the parameter settings for the DsauServer object into a file.		
	static	int saveToFile(char *fileName, DsauServer settings);



		//gotRandDebug tells the server to send to the client a string of random numbers with randomized response message types for each random number sent. (currently uses only f, b, and e.
	static	int gotRandDebug(int new_s);
		
		//fileCollecting reads in a specified file and sends it to the client.
	static	int fileCollecting(int new_s);
		
		//startCollecting calculates sin and cos values and sends it to the client. This is to simulate getting data from the board.		
	static	int startCollecting(int new_s);
		
	//Functions not implemented yet
	/***
	//functions that deal with direct communication with the zynq?
	.
	.
	.
	.
	***/		
	//ignore these functions for now.
static	double d_getPCVal(char* buf);
static	int i_getPCVal(char* buf);
static	int isValid(char addrloc, int iVal); 
static	double isValid(char addrloc, double dVal);

	private:
		int nSweep;		//Number of Sweeps: pointed to with addrloc 'a'
		int nStep;		//Number of Steps: pointed to with addrloc 'b'
		int nSample;		//Number of Samples: pointed to with addrloc 'c'
		double dSweep;		//Delay between Sweeps: pointed to with addrloc 'd'
		double minF;		//Minimum Frequency: pointed to with addrloc 'e'
		double maxF;		//Maximum Frequency: pointed to with addrloc 'f'
		char *C_sweep;		//character format of the above values
		char *C_step;
		char *C_sample;
		char *C_delay;
		char *C_min;
		char *C_max;			
		char leds;
};




