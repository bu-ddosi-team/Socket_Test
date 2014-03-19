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



#define MAX_LINE	256

class DsauServer{
  
	public:
		DsauServer();
		int gotRandDebug(int);
		int fileCollecting(int);
		int startCollecting(int);
			
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

};


struct Control
{
	int nSweep; //a
	int nStep;//b
	int nSample;//c		
	double dSweep;//d
	double minF;//e
	double maxF;//f


		
}; 	
	char *C_sweep;
	char *C_step;
	char *C_sample;
	char *C_delay;
	char *C_min;
	char *C_max;

	int writeToAddr(int, char, Control, char*);
	int gotRandDebug(int);
	int fileCollecting(int);
	int startCollecting(int);
//Make template classes for these.
	double d_getPCVal(char*);
	int i_getPCVal(char*);
	int isValid(int, int); //you can combine both isValids if you pass by reference
	double isValid(int, double);
	int loadSavedSettings(char*, Control&);
	int readFromAddress(char , int *, double *, int *);




int isValid(int addrloc, int iVal, double dVal)
{
#define mSweep 100
#define mStep 400
#define mSample 64000
#define mDelay 1
#define mminF 100
#define mmaxF 100000

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
}

int a_getPCVal(int *iVal, double *dVal, char addrloc, char *buf)
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

int writeToAddr(int new_s, char addrloc, Control& param, char *buf)
{
	int iVal = 0;
	double dVal = 0;
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
		  {   fprintf(stderr, "%d is %s \n", iVal, "Not a valid value for number of Sweeps");}
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
		  {  fprintf(stderr, "%d is %s \n", iVal, "Not a valid value for number of steps");		  }
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
		  {  fprintf(stderr, "%d is %s \n",iVal,  "Not a valid value for number of samples");	  } 
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
		  {  fprintf(stderr, "%f is %s \n", dVal, "Not a valid value for sweep delay");	  }
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
		  {  fprintf(stderr, "%f is %s \n", dVal, "Not a valid value for minimum frequency");	  }		
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
		  {  fprintf(stderr, "%f is %s \n",dVal, "Not a valid value for maximum frequency");	  }		 
		  break;			  		  	
		default:
		  fprintf(stderr, "%s \n", "Not a valid address");
		  return -1;
	}	//include print error function for error codes
 return 0;
}

int loadSavedSettings(char *fileName, Control& settings){
	int buf_size = 128;
	char pset1[128];	char pset4[128];
	char pset2[128];	char pset5[128];
	char pset3[128];	char pset6[128];
	fprintf(stderr, "opening cs \n");
	std::ifstream ifile (fileName, std::ifstream::in );
//	while(!ifile.eof() && ifile.is_open() ){
		ifile.getline(pset1, 128);
		ifile.getline(pset2, 128);
		ifile.getline(pset3, 128);
		ifile.getline(pset4, 128);
		ifile.getline(pset5, 128);
		ifile.getline(pset6, 128);
	ifile.close(); 
	 C_sweep  = pset1;
	 C_step   = pset2;
	 C_sample = pset3;
	 C_delay  = pset4;
	 C_min    = pset5;
	 C_max    = pset6;	
/*	
	fprintf(stdout, "nsweep = %s \n", pset1);
	fprintf(stdout, "nsweep = %s \n", pset2);
	fprintf(stdout, "nsweep = %s \n", pset3);
	fprintf(stdout, "nsweep = %s \n", pset4);
	fprintf(stdout, "minF = %s \n", pset5);
	fprintf(stdout, "maxF = %s \n", pset6);
*/

}
int saveToFile(char *fileName, Control settings)
{
	if(C_sweep == NULL || C_step == NULL || C_sample == NULL || C_delay == NULL || C_min == NULL || C_max == NULL)
	{
	  fprintf(stderr, "Unable to save settings to file. One or more values are NULL \n");
	}
 	std::ofstream ofile(fileName, std::ofstream::out);
	ofile << C_sweep;
	ofile << C_step;
	ofile << C_sample;
	ofile << C_delay;
	ofile << C_min;
	ofile << C_max;
 	ofile.close();
 	printf("Settings Saved\n");
  return 0;

}
int readFromAddress(char addrloc, int *iVal, double *dVal, int *type){
//we'll be simulating reading from the zynq with reading from a txt file. If we are using xml for settings data, we'll need to add code to handle it but it will be much more convient for accessing data.
	Control settings;
 	loadSavedSettings("Control_Settings.txt", settings);
	
	
	switch(addrloc)
	{
		case 'a':	//nsweep		
	  	  *iVal = settings.nSweep;
		  *type = 1;
		  break;
		case 'b':	//nstep
	  	  *iVal = settings.nStep;
		  *type = 1;
		  break;	
		case 'c':	//nSample
	  	  *iVal = settings.nSample;
		  *type = 1;
		  break;
		case 'd':	//dsweeep
	  	  *dVal = settings.dSweep;
		  *type = 2;
		  break;	
		case 'e':	//minF
	  	  *dVal = settings.minF;
		  *type = 2;
		  break;
		case 'f':	//maxF
	  	  *dVal = settings.maxF;
		  *type = 2;		 
		  break;			  		  	
		default:
		  fprintf(stderr, "%s \n", "Not a valid address");
		  return -1;
	
	}
return 1;
}

int gotRandDebug(int new_s)
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



int startCollecting(int new_s)
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
	char *sendf= new char[strSize];
	sprintf( sendf, "%c", f);
	len = strlen( sendf);
	send( new_s, sendf, len, 0);

}



int fileCollecting(int new_s)
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

 // 	   std::cout << "s is hit" << std::endl;
	   sprintf( reply, "%c", f);
	   len = strlen( reply);
	   send( new_s, reply, len, 0);
	   std::ifstream file ("sincoswaves.txt", std::ifstream::in | std::ios::binary);
	   while (!file.eof())
		  {
			  sendbuf = new char[strSize];
			 
			  file.read(sendbuf, strSize);
			  int sss = send( new_s, sendbuf, len, 0);

				std::cout << sendbuf<< std::endl;

			      char *sendf= new char[strSize];
			      sprintf( sendf, "%c", f);
			      len = strlen( sendf);
			      send( new_s, sendf, len, 0);

		  }
	file.close();
	std::cout << "Closing file" << std::endl;
}


/////////////////////////////////////////////////////////////////////////////////////
//Deprecrated?

int isValid(int addrloc, int iVal){
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
double isValid(int addrloc, double dVal){
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
double d_getPCVal( char *buf){
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

int i_getPCVal( char *buf){
	int len = strlen(buf);
	char data[len-2];
	std::string buffer(buf);
	std::string pdata = buffer.substr(2,len-2);
	int pval = atoi(pdata.c_str());
//  	warning, pval will stop at any non numeric character	
	printf("msg = %s data = %s converted = %d\n", buffer.c_str(),pdata.c_str(), pval);

	return pval;
}




