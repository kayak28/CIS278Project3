#include<iostream>
#include<cstring>
#include "math.h"
using namespace std;
//method definiton 
bool soldOut(int seats[], int size);
int seatsLeft(int seats[], int size);
bool validSeatNum(int seatNo, int size);
bool seatVacant(int seatNo, int seats[]);
bool reserveSeat(int seatNo, int seats[], int size);
bool cancelSeat(int seatNo, int seats[],int size)
int furthestFront(int seats[], int size);
void pair(int seats[], int size);
bool getSeatNo(int& value);
/*whare parameters int seats[] = int array of storing concert seat info
*		   int size capacity of array 'seats'
*		   int seatNo a paticular seat number 
*/

int main()
{
	const int  MAXSEATS = 15;
	int length;
	int action = 0;
      	int seatNum = 0 ;
	int seats[MAXSEATS];
	length = MAXSEATS - 1;

	do{
		cout << "the start";
		cout << "what action do you want to do?" 
		     << "1: reserve a seat\n2: cancel reservation";
		cout << "3: check sold-out\n4: print pair seat"
		     << "5: status of all seats\n6: print how many seats are left"; 
		cin >> action;
		if(action == 1|| action ==2 )
		{//selection 1 or 2 need seatNo.
			do
			{
				getSeatNo(seatNum);
			}while(!getSeatNo(seatNum))
			if(action == 1)
			{//make a reservation
				reserveSeat(seatNum, seats[], length);
			}
			else if(action == 2)
			{//cancel?
				
			}
		}
		else if(action == 3)
		{//print our if the concert is sold out or not
			if(soldOut(seat[], length))
			{
				cout << "Sorry this concert is already sold out";
			}
			else
			{
				cout << "there is " << seatLeft(seat[], size) << " vacant seats, please reservation ASAP"; 
			} 
		}
		else if(action == 4)
		{//print pair seat
			cout << pair(); 
		}
		else if(action == 5)
		{//status of all seats
			
		}	
		else if(action == 6)
		{//print how many seats are left
			cout << "there is" << seatLeft(seat[], size) << "left";
		}	
	}while(action < 0)
	
	cout << "thank you for using this reservation program."	
	cout<< "the end \n\n\n programmed by Kaya Ota";	 

	return 0;
}//main

bool soldOut(int seats[], int size)
{
	bool fullness = false;//assuming there is at least one empty seat
	for(int index = 0; index < size; index++)
	{
		if(seats[index] == 1)
		{
			fullness = true;
			return fullness;
			//immediately  return if there is an empty seat 	
		}//if	
	}
	//if index reaches the last index of array, indicating no empty seats
	return fullness;
}//soldOut()
int seatsLeft(int seats[], int size)
{
	int availableSeats = 0;//track number of available seats
	for(int index = 0; index < size; index++)
	{
		if(seats[index] == 0)
		{
			availableSeats++; 	
		}
	}

	return availableSeats;
}
bool validSeatNum(int seatNo, int size)
{
	bool validity = false; 
	if(0 <= seatNo && seatNo < size)
	{
		validity = true;
	}
	return validity;
}
bool seatVacant(int seatNo, int seats[])
{	
	bool vacantSeat = false;// assuming no vacant seat there
	if(seats[seatNo] == 0)//indicate seatNo is available  
	{
			vacantSeat = true;
	}
	else
	{
		cout << "Sorry your seat number is invalid.";
	}
	return vacantSeat;
}
bool reserveSeat(int seatNo, int seats[], int size)
{
	bool reservation = false;
	if(!soldOut(seats,size ))//it is true when soldOut retutns false
	{
		if(validSeatNum(seatNo, size))
		{
			seats[seatNo] = 1;
			reservation = true;
		}
		else
		{
			cout << "your seat number is not valid";
		}
	}
	else
	{
		cout << "Sorry all seats have been sold out already";
	}
	return reservation;
}
bool cancelSeat(int seatNo, int seats[],int  size)
{
	bool cancel = false;
	if(seats[seatNo] == 1)
	{
		seats[seatNo]== 0;
		cancel = true;
	}
	else
	{
		cout<< seatNo <<"has not reserved.";
		cancel = false;
	}
	return cancel;

}
int furthestFront(int seats[], int size)
{
	int index;
	if(!soldOut(seats, size))
	{	
		for(index = 0; index > size; index--)
		{	
			if(seats[index] == 0)
			{
				cout << index
				     << " is the available furthest front.";
			}

		}	
	}
	else
	{
		
		cout << "All seats for this concert have already sold out";
	} 
	return index;
}
void pair(int seats[], int size)
{ 	
	int index;
	if(!soldOut(seats, size))
	{
		for(index = 0; index < size-1  ; index++)
		{
			if(seats[index] == 0 && seats[index+1] == 0)
			{
				cout << index << "&&" << index+1 
				     << "are currrently available.";
			}

		}
	}
	else 
	{
		cout << "there is no pair seats";
	}
}
bool getSeatNo(int& value)
{	
	bool valid = false;
	bool isDigit = false;
	char seatNum [3];
	int num = 0 ;
	int power = 2;
	cout << "Enter seat number";
	cin >>  seatNum;
	//check array is contained digit char or not
	for(int index = 0; index < 3; index++)
	{
		if(!isdigit(seatNum[index]))
		{
			isDigit = false;
			return isDigit;
		}
	}
	for(int index = 0; index < 3 ; index++)
	{
		//num = seatNum[index] - '0';//convert char to int
		num +=( seatNum[index] - '0') *pow(10.0, power);
		power--;
	//	cout << "num" << num; 
	}
	cout << num << "\n"; 	
	if(num < 15)
	{
		valid = true;
	}		
	else
	{
		valid = false;
	}
	return valid;
}












