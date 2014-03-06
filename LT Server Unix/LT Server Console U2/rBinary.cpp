#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


int main () {

	std::ifstream file ("binFTest", std::ifstream::in | std::ifstream::binary);
	int end;
        int ch;
        int level[4];
        int thetime[4];
        if(file.is_open())
        {
       int *readin = new int[100];
        char *sendbuf = new char[4];
	char *test1;
         while (file.good()) {
         
//		file.get(sendbuf,4);
/*           file.seekg(0,std::ios::end);
           end=file.tellg();
           int numberOfInts=end/2;
           int storage[numberOfInts];
           file.clear();
           file.seekg(0);
           int test = 0;
           
	   file.read((char*)&storage[test], sizeof(2));

           while(file.tellg()!=end){       
               file.read((char*)&storage[test], sizeof(2));
//               std::cout << "Currently at position" << file.tellg() << std::endl;
               test++;
           }

           for(int i=0;i<numberOfInts;i++){
              std::cout << storage[i] << std::endl;
           }


*/

		file.seekg(0, std::ios::end);
		int fileSize = file.tellg();

 		std::cout << fileSize << "  +++++";
		file >> end;
		std::cout << "____" << end << "___" << std::endl;
		file.seekg(0, std::ios::beg); //sets location to the beginning of the file

		test1 = new char[fileSize];//
		file.read(test1, fileSize); //write file to buffer
		std::cout << test1;
 	
//		 file >> ch;
//		 std::cout << ch << std::endl;
  		

//                std::cout << (int)sendbuf << "  +++++" << sizeof(int)<< std::endl;

         }
          file.close();

        }
        else std::cout << "Unable to open file";
        return 0;
}

