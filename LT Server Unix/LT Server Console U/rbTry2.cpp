#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

using namespace std;


int main()
{
  ifstream is("binFTest");
  int input;
  char *chk = new char[4];
  int totalnum = 0;
  int *numa = new int[4];

  if(is.good()){
 	
 	is.seekg(0, is.end);
	int fileSize = is.tellg();
 	totalnum = fileSize/4;
  	 int num2[fileSize];
   	is.seekg(0, is.beg);
 	 for(int i = 0; i <totalnum; i++){
 	 	is.get(chk,4);
 	 	cout << chk << endl;
 		num2[i] = (int)chk;
 		cout << num2[i]<<endl;
 	   }
    
   }
    
    
}
