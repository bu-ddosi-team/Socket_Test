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


class DsauServer{
  
	public:
		DsauServer();
		int gotRandDebug(int new_s);
		int fileCollecting(int new_s);
		int startCollecting(int new_s);
		
	double d_getPCVal(char*);
	int i_getPCVal(char*);
	int isValid(int, int); 
	double isValid(int, double);
	
		int writeToAddr(int new_s, char addrloc, DsauServer& settings, char *buf);
		int readFromAddress(int new_s, char addrloc, int *iVal, double *dVal, int *type);				
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




