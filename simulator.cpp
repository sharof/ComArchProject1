
#include <iostream>
#include <string>
#include <cmath>
#include "operator.h"
using namespace std;
int word[65536];
int sp=65535;
int hi,lo;
int main(int argc, char *argv[])
{
	
	for(int i=0;i<=65535;i++)
	{
		word[i]=0;
		//cout<<i<<endl;
	}
//	int binarydigitnum=(floor(log(c)/log(2)));
/*	for(int i=binarydigitnum;i>=0;i--){
	
	b=(c>>i)%2;
	cout<<b<<endl;
}*/
	short int s=-2;
	cout<<s<<endl;
	cout<<convert16to32(s)<<endl;
	return 0;
}
