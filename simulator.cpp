
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "operator.h"
#include <sstream>
#include <fstream>
using namespace std;
vector<int> instructions;
int current_instruction;
int word[65536];
int reg[8]={0,0,0,0,0,0,0,0};
ifstream machinecode,memfile;
string line;
string arr[5];
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
current_instruction=instructions.at(0);


while(current_instruction & (29360128)!=25165824)
{





	
}


cout<<instructions.size()<<endl;
cout<<reg[1]<<endl;
cout<<reg[2]<<endl;
cout<<reg[3]<<endl;
cout<<reg[4]<<endl;
cout<<reg[5]<<endl;
cout<<reg[6]<<endl;
cout<<reg[7]<<endl;
cout<<current_instruction<<endl;
	return 0;
}
