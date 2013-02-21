#include<iostream>
#include<cstring>

using namespace std;
//method definiton 
bool soldOut(int seats[], int size);
int seatsLeft(int seats[], int size);
bool validSeatNum(int seatNo, int size);
bool seatVacant(int seatNo, int seats[]);
bool reserveSeat(int seatNo, int seats[], int size);
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
	cout << "How many seats are in the hall??";
	cin >> length;
      
	int seats[MAXSEATS];
	length = MAXSEATS - 1;
	
	
	for(int index = 0; index < length; index++)
	{
		seats[index] = 0;
		cout << seats[index];
	} 

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
int furthestFront(int seats[], int size)
{
	int index;
	if(!soldOut(seats, size))
	{	
		for(index = 0; index < size; index++)
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
		cout << "All seats are already reseaved";
	}
}
bool getSeatNo(int& value)
{	
	bool isDigit = false;
	char seatNum [10];
	char setNumber;
	cout << "Enter seat number";
	cin >>  
	//check array is contained digit or not
	for(int index = 0; index < 10; index++)
	{
		if(!isdigit(seatNum[index]))
		{
			isDigit = false;
			return isDigit;
		}
	}
	
}












