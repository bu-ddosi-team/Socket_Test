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
#include "DsauServer.h"


#define MAX_LINE	256
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
//TODO: Add Gain and LaserDiode Patter.
#define minGain 0
#define maxGain 100000

/*
	int writeToAddr(int, char, Control, char*);
	int gotRandDebug(int);
	int fileCollecting(int);
	int startCollecting(int);
	int loadSavedSettings(char*, Control&);
	int readFromAddress(char , int *, double *, int *);
*/	
/*			
	double d_getPCVal(char*);
	int i_getPCVal(char*);
	int isValid(int, int); 
	double isValid(int, double);

int isValid(int addrloc, int iVal, double dVal);
int a_getPCVal(int *iVal, double *dVal, char addrloc, char *buf);
int writeToAddr(int new_s, char addrloc, DsauServer& param, char *buf);
int loadSavedSettings(char *fileName, DsauServer& settings);
int saveToFile(char *fileName, DsauServer settings);
int readFromAddress(int new_s,char addrloc, int *iVal, double *dVal, int *type, DsauServer& settings);
int gotRandDebug(int new_s);
int fileCollecting(int new_s);
int startCollecting(int new_s);
*/	
DsauServer::DsauServer()
{
		int nSweep=0;		//Number of Sweeps: pointed to with addrloc 'a'
		int nStep=0;		//Number of Steps: pointed to with addrloc 'b'
		int nSample=0;		//Number of Samples: pointed to with addrloc 'c'
		double dSweep=0;		//Delay between Sweeps: pointed to with addrloc 'd'
		double minF=0;		//Minimum Frequency: pointed to with addrloc 'e'
		double maxF=0;		//Maximum Frequency: pointed to with addrloc 'f'
		char *C_sweep=NULL;		//character format of the above values
		char *C_step=NULL;
		char *C_sample=NULL;
		char *C_delay=NULL;
		char *C_min=NULL;
		char *C_max=NULL;			
		char leds=0;


}
int DsauServer::isValid(char addrloc, int iVal, double dVal)
{
	switch(addrloc)
	{
	      case 'a':
		if((iVal >minSweep) && (iVal < maxSweep))
		{	return 1;	}
		else
		{	return 0;	}
	      case 'b':
		if((iVal > minStep) && (iVal < maxStep))
		{	return 1;	}
		else
		{	return 0;	}	      
	      case 'c':
		if((iVal > minSample) && (iVal < maxSample))
		{	return 1;	}
		else
		{	return 0;	}	      
	      case 'd':
		if((dVal >minDelay) && (dVal < maxDelay))
		{	return 1;	}
		else
		{	return 0;	}
	      case 'e':
		if((dVal > 0) && (dVal < mminF))
		{	return 1;	}
		else
		{	return 0;	}	      
	      case 'f':
		if((dVal > 0) && (dVal < mmaxF))
		{	return 1;	}
		else
		{	return 0;	}
	      case 'g':
		if((dVal > 0) && (dVal < maxGain))
		{	return 1;	}
		else
		{	return 0;	}				      
	      default:
		return 0;
	
	}
}

int DsauServer::a_getPCVal(int *iVal, double *dVal, char addrloc, char *buf)
{
	int len = strlen(buf);
	char data[len-2];
	std::string buffer(buf);
	std::string pdata = buffer.substr(2,len-2);
	//Need to add code to check for valid strings instead of just values.
	
	fprintf(stderr, "a_get() iVal =%d dVal =%f \n", *iVal, *dVal);

	//isValid(addrloc, iv, dv)
	if( ((addrloc == 'a') || (addrloc == 'b') || (addrloc == 'c') ) )
	{
		*iVal = atoi(pdata.c_str());
		printf("msg = %s data = %s converted = %d\n", buffer.c_str(),pdata.c_str(), *iVal);
		if(!isValid(addrloc, *iVal, *dVal))
		{
			return 0;
		}
		
		return 1;
	}
	else if( (addrloc == 'd') || (addrloc == 'e') || (addrloc == 'f') )
	{
		
		*dVal = atof(pdata.c_str());
		printf("msg = %s data = %s converted = %f\n", buffer.c_str(),pdata.c_str(), *dVal);
		if(!isValid(addrloc, *iVal, *dVal))
		{
			return 0;
		}

		return 1;
	}
	
	return 0;


}
/*
int DsauServer::get_nSweep(int iVal)
{
	return this->nSweep = iVal;
}
void DsauServer::set_nSweep(int iVal)
{
	
}
*/
int DsauServer::writeToAddr(int new_s, char addrloc, DsauServer& param, char *buf)
{
	int iVal = 0;
	double dVal = 0;
	char *sendf= new char[MAX_LINE];
	switch(addrloc)
	{
		case 'a':	//nsweep		
//	  	  iVal = i_getPCVal(buf);
	  	  if(a_getPCVal(&iVal, &dVal, addrloc, buf))//isValid(addrloc, iVal))
	  	  {  
	  		param.nSweep = iVal; 
	  	 	printf("Setting nSweep to %d\n", iVal);
	  	 	return 1;
		  }
		  else
		  {   
		  fprintf(stderr, "%d is %s \n", iVal, "Not a valid value for number of Sweeps");
		  sprintf( sendf, "%s%s", "eeeee", "Not a valid value for number of Sweeps");
		  }
		  break;
		case 'b':	//nstep
//	  	  iVal = i_getPCVal(buf);
	  	  if(a_getPCVal(&iVal, &dVal, addrloc, buf))//isValid(addrloc, iVal))
	  	  {  
	  	  	param.nStep = iVal; 
	  	 	printf("Setting nStep to %d\n", iVal);	  
	  	 	return 1;	  
	  	  }
		  else
		  {  
		  fprintf(stderr, "%d is %s \n", iVal, "Not a valid value for number of steps");		
		  sprintf( sendf, "%s%s", "eeeee", "Not a valid value for number of Steps");  
		  }
		  break;	
		case 'c':	//nSample
//	  	  iVal = i_getPCVal(buf);
	  	  if(a_getPCVal(&iVal, &dVal, addrloc, buf))//isValid(addrloc, iVal))
	  	  {  
		  	param.nSample = iVal;
	  	 	printf("Setting nSample to %d\n", iVal);	
	  	 	return 1;  	  	 
	  	  }
		  else
		  {  
		  fprintf(stderr, "%d is %s \n",iVal,  "Not a valid value for number of samples");	  
		  sprintf( sendf, "%s%s", "eeeee", "Not a valid value for number of samples");
		  } 
		  break;
		case 'd':	//dsweeep
//	  	  dVal = d_getPCVal(buf);
	  	  if(a_getPCVal(&iVal, &dVal, addrloc, buf))//isValid(addrloc, dVal))
	  	  {  
	  		param.dSweep = dVal; 	 
	  	 	printf("Setting dSweep to %f\n", dVal);	
	  	 	return 1;  	  	  	  
	  	  }
		  else
		  {  
		  fprintf(stderr, "%f is %s \n", dVal, "Not a valid value for sweep delay");	 
		  sprintf( sendf, "%s%s", "eeeee", "Not a valid value for Sweep delay");
		  }
		  break;	
		case 'e':	//minF
//	  	  dVal = d_getPCVal(buf);
	  	  if(a_getPCVal(&iVal, &dVal, addrloc, buf))//isValid(addrloc, dVal))
	  	  {  
	  		param.minF = dVal; 	  
	  	 	printf("Setting minF to %f\n", dVal);	 
	  	 	return 1; 	  	  	  
	  	  }
		  else
		  {  
		  fprintf(stderr, "%f is %s \n", dVal, "Not a valid value for minimum frequency");	  
		  sprintf( sendf, "%s%s", "eeeee", "Not a valid value for minimum frequency");
		  }		
		  break;
		case 'f':	//maxF
//	  	  dVal = d_getPCVal(buf);
	  	  if(a_getPCVal(&iVal, &dVal, addrloc, buf))//isValid(addrloc, dVal))
	  	  {  
	  	 	param.maxF = dVal;   
	  	 	printf("Setting maxF to %f\n", dVal);
	  	 	return 1;	  	  	  	  
	  	  }
		  else
		  { 
		   fprintf(stderr, "%f is %s \n",dVal, "Not a valid value for maximum frequency");	  
		   sprintf( sendf, "%s%s", "eeeee", "Not a valid value for maximum frequency");
		   }		 
		  break;
		case 'g':	//maxF
//	  	  dVal = d_getPCVal(buf);
	  	  if(a_getPCVal(&iVal, &dVal, addrloc, buf))//isValid(addrloc, dVal))
	  	  {  
	  	 	param.maxF = dVal;   
	  	 	printf("Setting gain to %f\n", dVal);
	  	 	return 1;	  	  	  	  
	  	  }
		  else
		  { 
		   fprintf(stderr, "%f is %s \n",dVal, "Not a valid value for gain");	  
		   sprintf( sendf, "%s%s", "eeeee", "Not a valid value for gain");
		   }		 
		  break;		  			  		  	
		default:
		  fprintf(stderr, "%s \n", "Not a valid address");
		  sprintf( sendf, "%s%s", "eeeee", "Not a valid address");
		  send( new_s, sendf, strlen( sendf), 0);		  
		  return -1;
	}	//include print error function for error codes

	send( new_s, sendf, strlen( sendf), 0);
//	sprintf( sendf, "%c%s ", 'e', "Not a Valid Value");
//	send( new_s, sendf, strlen( sendf), 0);
 return 0;
}

int DsauServer::loadSavedSettings(char *fileName, DsauServer& settings){
	int buf_size = 128;
	char pset1[128];	char pset4[128];
	char pset2[128];	char pset5[128];
	char pset3[128];	char pset6[128];
	char pset7[128];
	fprintf(stderr, "opening %s \n", fileName);
	std::ifstream ifile (fileName, std::ifstream::in );
		ifile.getline(pset1, 128);
		ifile.getline(pset2, 128);
		ifile.getline(pset3, 128);
		ifile.getline(pset4, 128);
		ifile.getline(pset5, 128);
		ifile.getline(pset6, 128);
	ifile.close(); 
	
	 settings.C_sweep  = pset1;
	 settings.C_step   = pset2;
	 settings.C_sample = pset3;
	 settings.C_delay  = pset4;
	 settings.C_min    = pset5;
	 settings.C_max    = pset6;
	 settings.C_gain   = pset7;
	 
	 settings.nSweep   = atoi(pset1); 
	 settings.nStep    = atoi(pset2);
	 settings.nSample  = atoi(pset3);	
	 settings.dSweep   = atof(pset4);
	 settings.minF 	   = atof(pset5);
	 settings.maxF     = atof(pset6);
	 settings.gain     = atof(pset7);
/*	
	fprintf(stdout, "nsweep = %s \n", pset1);
	fprintf(stdout, "nsweep = %s \n", pset2);
	fprintf(stdout, "nsweep = %s \n", pset3);
	fprintf(stdout, "nsweep = %s \n", pset4);
	fprintf(stdout, "minF = %s \n", pset5);
	fprintf(stdout, "maxF = %s \n", pset6);
*/

}

int DsauServer::saveToFile(char *fileName, DsauServer settings)
{
	if(settings.C_sweep == NULL || settings.C_step == NULL || settings.C_sample == NULL || settings.C_delay == NULL || settings.C_min == NULL || settings.C_max == NULL)
	{
	  fprintf(stderr, "Unable to save settings to file. One or more values are NULL \n");
	}
 	std::ofstream ofile(fileName, std::ofstream::out);
	ofile << settings.C_sweep;
	ofile << settings.C_step;
	ofile << settings.C_sample;
	ofile << settings.C_delay;
	ofile << settings.C_min;
	ofile << settings.C_max;
	ofile << settings.C_gain;
 	ofile.close();
 	printf("Settings Saved\n");
  return 0;

}

int DsauServer::readFromAddress(int new_s, char addrloc, int *iVal, double *dVal, int *type, DsauServer& settings){
//we'll be simulating reading from the zynq with reading from a txt file. If we are using xml for settings data, we'll need to add code to handle it but it will be much more convient for accessing data.

 	loadSavedSettings("Control_Settings.txt", settings);
	char *sendf= new char[MAX_LINE];	
	switch(addrloc)
	{
		case 'a':	//nsweep		
	  	  *iVal = settings.nSweep;
	  	  printf("Sweep number is %d \n", *iVal);
		  sprintf( sendf, "%c%d", 'b', *iVal);	  	  
		  *type = 1;
		  break;
		case 'b':	//nstep
	  	  *iVal = settings.nStep;
	  	  printf("Step Number is %d \n", *iVal);
		  sprintf( sendf, "%c%d", 'b',*iVal);
		  *type = 2;
		  break;	
		case 'c':	//nSample
	  	  *iVal = settings.nSample;
	  	  printf("Sample Number %d \n", *iVal);
	  	  sprintf( sendf, "%c%d", 'b',*iVal);
		  *type = 3;
		  break;
		case 'd':	//dsweeep
	  	  *dVal = settings.dSweep;
	  	  printf("Sweep Delay is %f \n", *dVal);
	  	  sprintf( sendf, "%c%f", 'b',*dVal);
		  *type = 4;
		  break;	
		case 'e':	//minF
	  	  *dVal = settings.minF;
	  	  printf("Min Frequency is %f \n", *dVal);
	  	  sprintf( sendf, "%c%f", 'b',*dVal);		 
		  *type = 5;
		  break;
		case 'f':	//maxF
	  	  *dVal = settings.maxF;
	  	  printf("Max Frequency is %f \n", *dVal);
	  	  sprintf( sendf, "%c%f", 'b',*dVal);
		  *type = 6;		 
		  break;
		case 'g':	//gain
	  	  *dVal = settings.gain;
	  	  printf("Gain is %f \n", *dVal);
	  	  sprintf( sendf, "%c%f", 'b',*dVal);
		  *type = 6;		 
		  break;		  			  		  	
		default:
		  fprintf(stderr, "%s \n", "Not a valid address");
		  sprintf( sendf, "%s%s", "eeeee", "Not a valid address");
		  send( new_s, sendf,strlen( sendf), 0);
		  return 0;
	
	}
	
	/***
	//Server code to send back response? or do something else?
	***/
//	fprintf(stderr, "%s \n", sendf);
	send( new_s, sendf, strlen( sendf), 0);
	sprintf( sendf, "%c", 'f');
//	fprintf(stderr, "%s \n", sendf);	
	send( new_s, sendf, strlen( sendf), 0);
		
	
return 1;
}

int DsauServer::gotRandDebug(int new_s)
{
	char *sendbuf;// = "this is a test";
	int fileSize;
	char f = 'f';
	char buf[MAX_LINE];
	char reply[MAX_LINE];
 	int conn, line;
 	int len;
 	int s;
  	int strSize = MAX_LINE;
  	
  	int rnum;
	int mnum;
	char mtype;
	int setting = 10000;


//	    std::cout << "w is hit" << std::endl;
	    while ( line < 1000) {
	      rnum = rand()%setting;
	      mnum = rand()%1000;
		if(mnum == 0){mtype = 'f';}
		else if(mnum == 1){mtype = 'e';}
		else {mtype = 'b';}
	      ++line;
	      sprintf( reply, "%c%d\n", mtype, rnum);
	      len = strlen( reply);
	      send( new_s, reply, len, 0);
	    }
	      sprintf( reply, "%c", f);
	      len = strlen( reply);
	      send( new_s, reply, len, 0);

}


/*
int DsauServer::startCollecting(int new_s)
{

	char *sendbuf;// = "this is a test";
	int fileSize;
	char f = 'f';
	char buf[MAX_LINE];
	  char reply[MAX_LINE];
 	 int conn, line;
 	 int len;
 	 int s;

  	
//  	   std::cout << "s is hit" << std::endl;
	   sprintf( reply, "%c", f);
	   len = strlen( reply);
	   send( new_s, reply, len, 0);

		 int my_id[100] = {0};
		 int my_net_id[100];// = htonl(my_id);
//		 send(new_s, (const char*)&my_net_id, 4, 0);
		int integerl[100];
		for (int i=0; i<100; i++) {


			if (i%2==0) {
//				integerl[i] = (int)(10000*(double)cos((double)(i/30)+1.6));
				integerl[i]=(int)(10000*(double)cos((double)(i/10.0)+1.57));	
			}
			else {
//				integerl[i] =(int)(10000*(double)cos((double)(i/30)));
				integerl[i]=(int)(10000*(double)cos((double)(i/10.0)));
			}
		}
	//uint32_t un = htonl((int)integerl);
	send(new_s, &integerl, sizeof(uint32_t)*100, 0);
	char *sendf= new char[MAX_LINE];
	sprintf( sendf, "%c", f);
	len = strlen( sendf);
	send( new_s, sendf, len, 0);

}
*/
int DsauServer::startCollecting(int new_s)
{
	char *sendbuf;// = "this is a test";
	int fileSize;
	char f = 'f';
	char buf[MAX_LINE];
	  char reply[MAX_LINE];
 	 int conn, line;
 	 int len;
 	 int s;

	   sprintf( reply, "%c", f);
	   len = strlen( reply);
	   send( new_s, reply, len, 0);
	   memset(reply, 0, MAX_LINE);
		
	int sendcount = 800;
	
	int i = 0; 					
	int16_t stest[sendcount];	
	int16_t scw[sendcount];
	int ijk = 0;
	int loopcount = sendcount;
	int forcount = 100;
	bool moreData = true;
	while(moreData == true)
	{	
		if(loopcount < 100)
		{
		forcount = loopcount;
		moreData = false;
		}
		for (i = 0; i < forcount; i++) {
		stest[i] = ijk;
			if (ijk%2==0) {
				scw[i]=(int)(10000*(double)cos((double)(ijk/30.0)+1.6));						
			}
			else {
				scw[i]=(int)(10000*(double)cos((double)(ijk/30.0)));
			}
			ijk++;
		}
		for(int iii = 0; iii < forcount; iii++){
		std::cout <<stest[iii]<<"  "<<forcount<<"  "<<loopcount<<std::endl;
		}
	//	send(new_s, &stest, sizeof(uint16_t)*forcount, 0);
		send(new_s, &scw, sizeof(uint16_t)*forcount, 0);		
		loopcount -= forcount;		
	}
	

//	   sprintf( reply, "%s", "fffff");
//	   len = strlen( reply);
//	   send( new_s, reply, len, 0);
	return 0;
	
}

int DsauServer::fileCollecting(int new_s)
{

	char *sendbuf;// = "this is a test";
	int fileSize;
	char f = 'f';
	char buf[MAX_LINE];
	char reply[MAX_LINE];
 	int conn, line;
 	int len;
 	int s;


 // 	   std::cout << "s is hit" << std::endl;
	   sprintf( reply, "%c", f);
	   len = strlen( reply);
	   send( new_s, reply, len, 0);
	   std::ifstream file ("sincoswaves.txt", std::ifstream::in | std::ios::binary);
	   while (!file.eof())
		  {
			  sendbuf = new char[MAX_LINE];
			 
			  file.read(sendbuf, MAX_LINE);
			  int sss = send( new_s, sendbuf, len, 0);

				std::cout << sendbuf<< std::endl;

			      char *sendf= new char[MAX_LINE];
			      sprintf( sendf, "%c", f);
			      len = strlen( sendf);
			      send( new_s, sendf, len, 0);

		  }
	file.close();
	std::cout << "Closing file" << std::endl;
}


/////////////////////////////////////////////////////////////////////////////////////
//Deprecrated?

int DsauServer::isValid(char addrloc, int iVal){
//check nsweep, nstep, nsample
//define ranges, but later move them to correct area.
#define mSweep 100
#define mStep 400
#define mSample 64000
	switch(addrloc)
	{
	      case 'a':
		if((iVal > 0) && (iVal < mSweep))
		{	return 1;	}
		else
		{	return 0;	}
	      case 'b':
		if((iVal > 0) && (iVal < mStep))
		{	return 1;	}
		else
		{	return 0;	}	      
	      case 'c':
		if((iVal > 0) && (iVal < mSample))
		{	return 1;	}
		else
		{	return 0;	}	      
	      default:
		return 0;
	
	}
	return 0;
}
double DsauServer::isValid(char addrloc, double dVal){
//check delay, minf, maxf
//define ranges, but later move them to correct area.
#define mDelay 1
#define mminF 100
#define mmaxF 100000

	switch(addrloc)
	{
	      case 'd':
		if((dVal > 0) && (dVal < mDelay))
		{	return 1;	}
		else
		{	return 0;	}
	      case 'e':
		if((dVal > 0) && (dVal < mminF))
		{	return 1;	}
		else
		{	return 0;	}	      
	      case 'f':
		if((dVal > 0) && (dVal < mmaxF))
		{	return 1;	}
		else
		{	return 0;	}	      
	      default:
		return 0;
	
	}
	return 0;

}
double DsauServer::d_getPCVal( char *buf){
	int len = strlen(buf);
	char data[len-2];
	std::string buffer(buf);
	std::string pdata = buffer.substr(2,len-2);
//	memmove(pdata,(const void*) *(buf+2), len-2);
	double pval = atof(pdata.c_str());
//  	warning, pval will stop at any non numeric character
	printf("msg = %s data = %s converted = %f\n", buffer.c_str(),pdata.c_str(), pval);
	
	return pval;
}

int DsauServer::i_getPCVal( char *buf){
	int len = strlen(buf);
	char data[len-2];
	std::string buffer(buf);
	std::string pdata = buffer.substr(2,len-2);
	int pval = atoi(pdata.c_str());
//  	warning, pval will stop at any non numeric character	
	printf("msg = %s data = %s converted = %d\n", buffer.c_str(),pdata.c_str(), pval);

	return pval;
}




