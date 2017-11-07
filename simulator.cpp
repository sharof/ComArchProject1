
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
vector<int> instructions;
int current_instruction,instr_pointer;
int word[65536];
int reg[8]={0,0,0,0,0,0,0,0};
ifstream machinecode,memfile;
string line;
string arr[5];
int imm,count=0;
int main(int argc, char *argv[])
{
	machinecode.open("Translator/machinecode.txt");	
	while(getline(machinecode,line)){
	instructions.push_back(atoi(line.c_str()));	
	}
		machinecode.close();
	for(int i=0;i<=65535;i++)
	{
		word[i]=0;
	}
memfile.open("Translator/memfile.txt");	
while(getline(memfile,line)){
	int i=0;
stringstream ssin(line);
    while (ssin.good() && i < 2){
        ssin >> arr[i];
        i++;
    }
    word[atoi(arr[0].c_str())]=atoi(arr[1].c_str());
}
instr_pointer=0;
current_instruction=instructions.at(instr_pointer);


while(1)
{
	reg[0]=0;count++;
if((current_instruction & (29360128))==0){//AND instruction
	reg[current_instruction &7] = reg[(current_instruction &3670016)>>19]+reg[(current_instruction &458752)>>16];
	instr_pointer++;
current_instruction=instructions.at(instr_pointer);
}
else if((current_instruction & (29360128))==4194304){//NAND instruction
reg[current_instruction & 7] =~ (reg[(current_instruction &3670016)>>19] & reg[(current_instruction &458752)>>16]);	
	instr_pointer++;
current_instruction=instructions.at(instr_pointer);
}
else if((current_instruction & (29360128))==8388608){//LW instruction
          imm=current_instruction&65535;
          if(imm>32767){
          	imm-=65536;
		  }
	reg[(current_instruction &458752)>>16]=word[reg[(current_instruction &3670016)>>19]+imm];
		instr_pointer++;
current_instruction=instructions.at(instr_pointer);
}
else if((current_instruction & (29360128))==12582912){//SW instruction
   imm=current_instruction&65535;
          if(imm>32767){
          	imm-=65536;
		  }
	word[reg[(current_instruction &3670016)>>19]+imm]=reg[(current_instruction &458752)>>16];
		instr_pointer++;
current_instruction=instructions.at(instr_pointer);
}
else if((current_instruction & (29360128))==16777216){//BEQ instruction
	
	if(reg[(current_instruction &3670016)>>19] == reg[(current_instruction &458752)>>16]){
		
		imm=current_instruction&65535;
          if(imm>32767){
          	imm-=65536;
		  }
		instr_pointer+=imm;	
	}
		instr_pointer++;
current_instruction=instructions.at(instr_pointer);	
}
else if((current_instruction & (29360128))==20971520){//JALR instruction
		cout<<"Jump 	"<<instr_pointer<<" 	Stack:"<<reg[5]<<"   	   S1:"<<reg[1]<<"   	   S2:"<<reg[2]<<endl;
	if(reg[(current_instruction &3670016)>>19] == reg[(current_instruction &458752)>>16]){
	reg[(current_instruction &458752)>>16]=instr_pointer+1;
		instr_pointer++;
	}
	else{
	
			reg[(current_instruction &458752)>>16]=instr_pointer+1;
			instr_pointer=reg[(current_instruction &3670016)>>19];
			
	}
	current_instruction=instructions.at(instr_pointer);	
}
else if((current_instruction & (29360128))==25165824){//HALT instruction
break;	
}
else if((current_instruction & (29360128))==29360128){//NOOP instruction
	instr_pointer++;
current_instruction=instructions.at(instr_pointer);
}
/*if(instr_pointer=instructions.size()-1){
break;	
}*/


	
}

cout<<"---------------------------------------------Final Result----------------------------------------------"<<endl;
cout<<"Number of actual actions: "<<count<<endl;
cout<<"Number of instruction from machine code: "<<instructions.size()<<endl;
cout<<"Register[1]: "<<reg[1]<<endl;
cout<<"Register[2]: "<<reg[2]<<endl;
cout<<"Register[3]: "<<reg[3]<<endl;
cout<<"Register[4]: "<<reg[4]<<endl;
cout<<"Register[5]: "<<reg[5]<<endl;
cout<<"Register[6]: "<<reg[6]<<endl;
cout<<"Register[7]: "<<reg[7]<<endl;
cout<<"Last instruction: "<<current_instruction<<endl;
	return 0;
}
