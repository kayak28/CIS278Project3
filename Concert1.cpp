#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
//function definiton 
bool soldOut(int seats[], int size);
int seatsLeft(int seats[], int size);
bool validSeatNum(int seats[], int size);
int seatVacant(int seatNo, int seats[]);
bool reserveSeat(int seatNo, int seats[]);
int furthestFront(int seats[], int size);
void pairSeats(int seats[], int size);
bool getSeatNo(int& value);
bool cancelSeat(int seatNo, int seats[]);
void seatsStatus(int size, int seats[]);
int main()
{
	//initilaization 
	int const MAXSEATNUM = 10;
	int length =MAXSEATNUM; 
	int seats[length];
	int action = 0;
	int seatNum =0;
	do
	{
		cout  << "1: reserve a seat\n2: cancel reservation\n";
		cout << "3: check sold-out\n4: print pair seat\n"
		     << "5: status of all seats\n6: print how many seats are left\n";
		cout << "Enter negative number  to end";
		cin >> action;
		switch (action)
		{
			case 1:
				//make a resevation
				while(!(getSeatNo(seatNum)));
				reserveSeat(seatNum, seats);
				cout << "\nresevation is done\n";
				break;
			case 2:
				//cancel a reserved seat
				while(!(getSeatNo(seatNum)));
				cancelSeat(seatNum, seats);
				cout << "\ncansel is done\n";
				break;
			case 3:
				//check if there is a empty seat or not
				if(soldOut(seats, length))
				{
					cout << "this hell has already been reserved";
				}
				else
				{
					cout << "this hall is still have a seat";
				}
				cout << "\nsold out is done \n";
				break;
			case 4:	 //find pair seats
				pairSeats(seats, length);
				cout << "\npair is done\n";
				break;
			case 5: // status of all seats
				seatsStatus(length, seats);
				cout << "\nstatus is over\n";
				break;
			case 6:
				seatsLeft(seats, length);
				cout << "seatLeft";
				break;
		} 
	}while(!(action < 0));
   
	cout << "\nthank you for using this reservation program.\n";	
	cout << "\nthe end \n\n\n programmed by Kaya Ota\n";	

	
	

	return 0;
}

bool getSeatNo(int& value)
{
	bool digit = true;
	char seatNum[2];
	int num =0;
	int length = 2;
	int power = 1;
	for(int index = 0; index < length; index++)
	{
		seatNum[index] = 0;
		cout << seatNum[index] << "\n";
		//cout << "seatNum[]= "<<seatNum[index] << "\n"; 
	}
	
	cout << "Please Enter seat number ";
	cin >> seatNum;
/*
	int index;
	while(seatNum[index] != '0')
	{
		if(!isdigit(seatNum[index]))
		{
			digit = false;
			cout <<"digit = " << digit;
			return digit;
		}
		index ++;
		cout << "added index\n";
	}
	value = atoi(seatNum);
	cout << "aft conv\n";
	return digit;
*/
	for(int index = 0; index < length; index++ )
	{
		if(!isdigit(seatNum[index]))
		{
			cout << "contained real chars\n";
			cout << "char=" << seatNum[index] << "\n";
			digit = false;
			cout << "digit =" << digit << "\n";
			break;
		}
		else
		{
			digit = true;
			cout << "it is digit\n"<< "digit" << digit;
		}
	}
	if(digit)
	{
		value = atoi(seatNum);
		cout << "value: "<< value << "digit: "<< digit << "\n"; 
	}
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
	else if(seats[seatNo] ==1)
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

bool cancelSeat(int seatNo, int seats[])
{
	bool cancel = true;
	if(seats[seatNo] == 1)
	{
		cout << "are you sure you are going to cancel?";
		seats[seatNo] = 0;
		cancel = true;
	}
	else
	{
		cout << "this seat is not reserved";
		cancel = false;
	}
	return cancel;
}

int furthestFront(int seats[], int size)
{
	for(int index = size; index >=0;  index--)
	{
		if(seats[index] == 0)
		{
			cout << "the furthest seat from the front is "
			     << index <<"\n";
		}
	}
}
void pairSeats(int seats[], int size)
{
	for(int index = 0 ; index < size; index++)
	{
		if(seats[index] == 0 && seats[index +1] == 0)
		{
			cout << index << "and" << index + 1
			     << "are available pair seat\n";
		}
		else
		{
			cout << "there is no pair seat\n";
		}
	}

}

int seatsLeft(int seats[], int size)
{
	int available = 0;
	for(int index = 0; index < size; index++)
	{
		if(seats[index])
		{
			available++;
		}
	}
	return available;
}
bool validSeatNum(int seatNo, int size)
{
	bool validate = true;
	if(seatNo > 0 && seatNo < size)
	{
		validate = true;
	}
	else 
	{
		validate = false;
	}

}
int seatVacant(int seatNo, int seats[])
{
	bool vacant = true;
	if(seats[seatNo] ==0)
	{
		cout << "seat is vacant";
		vacant = true;
	}
	else if(seats[seatNo] == 1)
	{
		cout << "seat is not vacant";
		vacant = false;
	} 
	return vacant;
	

}

void seatsStatus(int size, int seats[])
{
	for(int index = 0; index < size; index++)
	{
		if(seats[index]==0)
		{
			cout << index <<" vacant\n";
		}
		else
		{
			cout << index << " full\n";
		}
	}

}
