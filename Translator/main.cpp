
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
vector<string> label;
vector<int> address;
vector<int> imm;
int addr;
char type;
 bool found;
string arr[5];
string frr[5];
int pc=0;
void Rcondcheck(){
		if(!(atoi(arr[2].c_str())>=0&&atoi(arr[2].c_str())<=7&& atoi(arr[3].c_str())>=0&&atoi(arr[3].c_str())<=7&&atoi(arr[4].c_str())>=0&&atoi(arr[4].c_str())<=7))
  		{//reg number check
  		cout<<"Assemble failed, register number can be only between 0-7 at line "<<pc<<endl; 
 		 exit(1);
   		}

}
void Jcondcheck(){
		if(!(atoi(arr[2].c_str())>=0&&atoi(arr[2].c_str())<=7&& atoi(arr[3].c_str())>=0&&atoi(arr[3].c_str())<=7))
  		{//reg numbercheck
  		cout<<"Assemble failed, register number can be only between 0-7 at line "<<pc<<endl; 
 		 exit(1);
   		}
   		
   		
   		
   		
   		
   		

}
int Icondcheck(){
		if(!(atoi(arr[2].c_str())>=0&&atoi(arr[2].c_str())<=7&& atoi(arr[3].c_str())>=0&&atoi(arr[3].c_str())<=7))
  		{
		  //reg number check
  		cout<<"Assemble failed, register number can be only between 0-7 at line "<<pc<<endl; 
 		 exit(1);
		  return 0;
   		}
   		
  if (atoi(arr[4].c_str())== 0 && arr[4] != "0") 		
   		{
   		 found=false;
			   int j;
   			for(int i=0;i<label.size();i++)
   			{
			   if(arr[4]==label.at(i)){found=true;j=i;break;  }
   				
			   }
   			if(found){return address.at(j);   }
   			else{		   
		cout<<"Assemble failed, "<<arr[4]<<" hasn't declared yet!"<<endl;	   
			   exit(1);return 0;}
		   }
   				
   	else{	
if(!(atoi(arr[4].c_str())>=-32768&&atoi(arr[4].c_str())<=32767))
{
	cout<<"Assemble failed, immediate value must be within 16 bits at line "<<pc<<endl;
	exit(1);
}
return 0;
}


}
int main(int argc, char *argv[])
{
	int binarycode=0;
    ifstream file,tmpfile;
 	string line,fakeline;	
 	
 	//serching for .fill things and remember them
 		tmpfile.open("assembly.txt");	
	while(getline(tmpfile,line)){
 	 int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < 5){
        ssin >> arr[i];
        i++;
    }
   if(arr[1]==".fill"){
 	label.push_back(arr[0]);
 	address.push_back(pc);
 	  if (atoi(arr[2].c_str())== 0 && arr[2] != "0") 		
   		{
   			found = false;
          int fakepc=0;
	file.open("assembly.txt");	
	while(getline(file,fakeline)){
 int w = 0;
    stringstream ffin(fakeline);
    while (ffin.good() && w < 5)
	{
        ffin >> frr[w];
        w++;
    }
if(frr[0]==arr[2]){
imm.push_back(fakepc);
//push the address into those vectors too
label.push_back(arr[2]);
address.push_back(fakepc);
imm.push_back(fakepc);
//
found=true;
break;
}
fakepc++;
}
	file.close();
	if(!found){
	cout<<"Assemble failed, there is no such label called "<<arr[2]<<endl;
	exit(1);
		}
		   }
   		else{
 	imm.push_back(atoi(arr[2].c_str()));
	 }
 }
 	
 	pc++;
 }
 	tmpfile.close();
 	
 	pc=0;
 	//time to start program
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
   	
   	addr=Icondcheck();
   binarycode+=2<<22;
    binarycode+=atoi(arr[2].c_str())<<19;
  binarycode+=atoi(arr[3].c_str())<<16;
  
    if (atoi(arr[4].c_str())== 0 && arr[4] != "0") 		
   		{
  binarycode+=addr;
}
        else{
  if(atoi(arr[4].c_str())<0){binarycode+=65536 ;}
  binarycode+=atoi(arr[4].c_str()); 
}
  
  
   }
   else if(  arr[1]=="sw" ){
   addr=Icondcheck();
   binarycode+=3<<22;
      binarycode+=atoi(arr[2].c_str())<<19;
  binarycode+=atoi(arr[3].c_str())<<16;
  
   if (atoi(arr[4].c_str())== 0 && arr[4] != "0") 		
   		{
  binarycode+=addr;
}
  else{
  if(atoi(arr[4].c_str())<0){binarycode+=65536 ;}
  binarycode+=atoi(arr[4].c_str()); 
}
  
  
  }
   else if(arr[1]=="beq" ){
   addr=Icondcheck();
   binarycode+=4<<22;
      binarycode+=atoi(arr[2].c_str())<<19;
  binarycode+=atoi(arr[3].c_str())<<16;
  
   if (atoi(arr[4].c_str())== 0 && arr[4] != "0") 		
   		{		
   for(int i=0;i<label.size();i++){
   	if(label.at(i)==arr[4])
	   {
  if((address.at(i)-pc-1)<0)
  {
  	binarycode+=(address.at(i)-pc+65535);
  }
  else
  {
   binarycode+=(address.at(i)-pc-1);	
  }		 
		 break;	   
	   }
   }			
}
  else{
  if(atoi(arr[4].c_str())<0){binarycode+=65536 ;}
  binarycode+=atoi(arr[4].c_str()); 
}
  
  
  
  }
  else if( arr[1]=="jalr" ){
  Jcondcheck();
  binarycode+=5<<22;
  binarycode+=atoi(arr[2].c_str())<<19;
  binarycode+=atoi(arr[3].c_str())<<16;
  }
  
  else if( arr[1]=="halt" ){
  binarycode+=6<<22;
  }
     else if( arr[1]=="noop"  ){
	 binarycode+=7<<22;
	 }
  else if( arr[1]==".fill"  ){
  	  if (atoi(arr[2].c_str())== 0 && arr[2] != "0") 		
   		{
  	for(int i=0;i<label.size();i++)
  	{
  		if(label.at(i)==arr[2])
  		{
  		binarycode+=address.at(i);	
  			break;
		  }		
	  }
  }
  	else{
  	binarycode+=atoi(arr[2].c_str());
  }
  }
  else{
  cout<<"Assemble failed, unknown instruction at line "<<pc<<endl;
  exit(1);}
cout<<binarycode<<endl;
pc++;
}

		file.close();
cout<<"Assemble successful!"<<endl;
return 0;	
}
