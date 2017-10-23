
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <fstream>
#include "condition.h"
using namespace std;
char type;
string arr[5];
int pc=0;
void Rcondcheck(){
		if(!(atoi(arr[2].c_str())>=0&&atoi(arr[2].c_str())<=7&& atoi(arr[3].c_str())>=0&&atoi(arr[3].c_str())<=7&&atoi(arr[4].c_str())>=0&&atoi(arr[4].c_str())<=7))
  		{
  		cout<<"Assemble failed, register number can be only between 0-7 at line "<<pc<<endl; 
 		 exit(1);
   		}

}
void Jcondcheck(){
		if(!(atoi(arr[2].c_str())>=0&&atoi(arr[2].c_str())<=7&& atoi(arr[3].c_str())>=0&&atoi(arr[3].c_str())<=7))
  		{
  		cout<<"Assemble failed, register number can be only between 0-7 at line "<<pc<<endl; 
 		 exit(1);
   		}

}
void Icondcheck(){
		if(!(atoi(arr[2].c_str())>=0&&atoi(arr[2].c_str())<=7&& atoi(arr[3].c_str())>=0&&atoi(arr[3].c_str())<=7))
  		{
  		cout<<"Assemble failed, register number can be only between 0-7 at line "<<pc<<endl; 
 		 exit(1);
   		}
if(!(atoi(arr[4].c_str())>=-32768&&atoi(arr[4].c_str())<=32767))
{
	cout<<"Assemble failed, immediate value must be within 16 bits at line "<<pc<<endl;
	exit(1);
}
}
int main(int argc, char *argv[])
{
	int binarycode=0;
	
	

    ifstream file,tmpfile;
 	string line,findhalt;	
	file.open("assembly.txt");	

	
	
	
	
	
	
	
	
	while(getline(file,line)){
binarycode=0;
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < 5){
        ssin >> arr[i];
        i++;
    }
  if( arr[1]=="add" )
  { 
  	Rcondcheck();
  binarycode+=atoi(arr[2].c_str())<<19;
  binarycode+=atoi(arr[3].c_str())<<16;
  binarycode+=atoi(arr[4].c_str()); 
  }
  else if(arr[1]=="nand" )
  {
  			Rcondcheck();
  	binarycode+=1<<22;
    binarycode+=atoi(arr[2].c_str())<<19;
  	binarycode+=atoi(arr[3].c_str())<<16;
  	binarycode+=atoi(arr[4].c_str()); 
  }
   else if( arr[1]=="lw" ){
   	Icondcheck();
   binarycode+=2<<22;
    binarycode+=atoi(arr[2].c_str())<<19;
  binarycode+=atoi(arr[3].c_str())<<16;
  if(atoi(arr[4].c_str())<0){binarycode+=65536 ;}
  binarycode+=atoi(arr[4].c_str()); 
   }
   else if(  arr[1]=="sw" ){
   Icondcheck();
   binarycode+=3<<22;
      binarycode+=atoi(arr[2].c_str())<<19;
  binarycode+=atoi(arr[3].c_str())<<16;
  if(atoi(arr[4].c_str())<0){binarycode+=65536 ;}
  binarycode+=atoi(arr[4].c_str()); 
  }
   else if(arr[1]=="beq" ){
   Icondcheck();
   binarycode+=4<<22;
      binarycode+=atoi(arr[2].c_str())<<19;
  binarycode+=atoi(arr[3].c_str())<<16;
  if(atoi(arr[4].c_str())<0){binarycode+=65536 ;}
  binarycode+=atoi(arr[4].c_str()); 
  }
  else if( arr[1]=="jalr" ){
  	Jcondcheck();
  binarycode+=5<<22;}
  else if( arr[1]=="halt" ){binarycode+=6<<22;}
     else if( arr[1]=="noop"  ){binarycode+=7<<22;}
  
  else{
  cout<<"Assemble failed, unknown instruction at line "<<pc<<endl;
  exit(1);}
cout<<binarycode<<endl;
pc++;
}

		file.close();

return 0;	
}
