
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
char type;
int main(int argc, char *argv[])
{
	int pc=0;
    ifstream file;
 	string line,findhalt;	
	file.open("assembly.txt");	

	
	while(getline(file,line)){
int binarycode=0;
	
	
string arr[5];
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < 5){
        ssin >> arr[i];
        i++;
    }
  if( arr[1]=="add" ){  }
  else if(arr[1]=="nand" ){binarycode+=1<<22;  }
   else if( arr[1]=="lw" ){binarycode+=2<<22;}
   else if(  arr[1]=="sw" ){binarycode+=3<<22;}
   else if(arr[1]=="beq" ){binarycode+=4<<22;}
  else if( arr[1]=="jalr" ){binarycode+=5<<22;}
  else if( arr[1]=="halt" ){binarycode+=6<<22;}
     else if( arr[1]=="noop"  ){binarycode+=7<<22;}
  
  else{exit(1);}
cout<<binarycode<<endl;
}

		file.close();

return 0;	
}
