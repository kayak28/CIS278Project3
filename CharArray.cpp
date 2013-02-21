#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int number;
	char seatNum[10];
	cout << "Enter number";
	cin >> seatNum; 

	for(int index = 0; index < 10; index++)
	{
		if(isdigit(seatNum[index]))
		{
			cout  << "digit:" << seatNum[index]<<"\n";
			number = seatNum[index] - '0';
			cout << "cast: seatNum[index] -'0' = " << number << "\n" ;
			number = number * 10 + seatNum[index+1];
			cout << "num*10+seat[index +1] = "<< number << "\n";
	
		}
		else
		{
			cout << "this is not digit char \n";
		}
	}


}//main
