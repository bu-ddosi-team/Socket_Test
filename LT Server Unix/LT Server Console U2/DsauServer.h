

class DsauServer{
  
	public:
		DsauServer();
		int gotRandDebug(int new_s);
		int fileCollecting(int new_s);
		int startCollecting(int new_s);
		

		int writeToAddr(int new_s, char addrloc, DsauServer& settings, char *buf);
		int readFromAddress(int new_s, char addrloc, int *iVal, double *dVal, int *type, DsauServer& settings);				
		int isValid(int addrloc, int iVal, double dVal);
		int a_getPCVal(int *iVal, double *dVal, char addrloc, char *buf);
		int loadSavedSettings(char *fileName, DsauServer& settings);
		int saveToFile(char *fileName, DsauServer& settings);


	//Functions not implemented yet
	/***
	int getSweepNumber();
	void setSweepNumber(); //+ 5 etc
	.
	.
	.
	***/		
	
	double d_getPCVal(char* buf);
	int i_getPCVal(char* buf);
	int isValid(int addrloc, int iVal); 
	double isValid(int addrloc, double dVal);
			
	private:
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
		char leds;
};




