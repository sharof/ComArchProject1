
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int word[65536];
bool b;
int c=1024;
int main(int argc, char *argv[])
{
	
	for(int i=0;i<65536;i++)
	{
		word[i]=2147483647;
		//cout<<i<<endl;
	}
	int binarydigitnum=(floor(log(c)/log(2)));
/*	for(int i=binarydigitnum;i>=0;i--){
	
	b=(c>>i)%2;
	cout<<b<<endl;
}*/
	
	return 0;
}
