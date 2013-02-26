#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
//function definiton 
bool soldOut(int seats[], int size);
int seatsLeft(int seats[], int size);
bool validSeatNum(int seats[], int size);
int seatVacant(int seatNo, int seats[]);
bool reserveSeat(int seatNo, int seats[]);
int furthestFron(int seats[], int size);
void PairSeats(int seats[], int size);
bool getSeatNo(int& value);
bool cancelSeat(int seatNo, int seats[], int size);

int main()
{
	//initilaization 
	int const MAXSEATNUM = 10;
	int length =MAXSEATNUM; 
	int seats[length];
	int action = 0;
	int seatNum =0;
	
	for(int index = 0; index < length; index++)
	{
		seats[index] =0;
	}
	reserveSeat(5,seats);
	cout << "status" << seats[5] << "\n";
	if(reserveSeat(5, seats))
	{
		cout << "reserved!\n";	
	}
	else
	{
		cout << "try another seat\n";
	}
	if(soldOut(seats, length))
	{
		cout << "already sold out";
	}
	else
	{
		cout << "Not yet";
	}


	if(getSeatNo(seatNum))
	{
		cout << "return = true"<< "\n";
	}
	else 
	{
		cout << "return = false" << "\n";
	}
	cout <<"getNum ="<< getSeatNo(seatNum);

	cout << "seatNum" << seatNum;


	return 0;
}

bool getSeatNo(int& value)
{
	bool digit = true;
	char seatNum[3];
	int num =0;
	int length = 3;
	int power = 2;
	cout << "Enter seat number";
	cin >> seatNum;

	for(int index = 0; index < length; index++ )
	{
		if(!isdigit(seatNum[index]))
		{
			cout << "contained real chars\n";
			digit = false;
			cout << "digit =" << digit << "\n";
			break;
		}
		else
		{
			cout << "it is digit\n"<< "num" << num;
			/*
			num += (seatNum[index] - '0')*pow(10.0, power);
			cout << "power!" << power << "\n";
			--power;
			cout <<"\npower " <<power <<" num" << num << "\n"; 
			digit = true;
			cout << "digit ="<< digit << "\n";
			*/
		}
	}
	value = atoi(seatNum);
	return digit;	
}

bool reserveSeat(int seatNo, int seats[])
{
	bool success = true;
	if(seats[seatNo] == 0)
	{
		cout << "you can reserve this seat!\n";	
		seats[seatNo] = 1;
		success = true;
	}
	else
	{
		cout << "sorry this seat is already reserved\n";
		success =false;
	}
	return success;
}

bool soldOut(int seats[], int size)
{
	bool soldOut = true;
	for(int index = 0; index < size; index++)
	{
		if(seats[index] == 1)
		{
			soldOut = true;
		}
		else
		{
			soldOut = false;
		}
	}
	return soldOut;
}
