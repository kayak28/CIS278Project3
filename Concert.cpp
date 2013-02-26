#include<iostream>
#include<cstring>
#include "math.h"
using namespace std;
//method definiton 
bool soldOut(int seats[], int size);//95, check if all seats are sold out or not
int seatsLeft(int seats[], int size);//110, return how many seats are still left
bool validSeatNum(int seatNo, int size);//132, valify the seatNum is valid or not
bool seatVacant(int seatNo, int seats[]);//145 find empty seats
bool reserveSeat(int seatNo, int seats[], int size);//147, make a resevation
bool cancelSeat(int seatNo, int seats[],int size);//166 cancel seats
int furthestFront(int seats[], int size);//182, find the furthestFront
void seatsPair(int seats[], int size);//204, find two seats are next by
bool getSeatNo(int& value);//228 get seatNum and validate.
bool seatsStatus(int seats[], int size);//264 determine each seats are full or not.
/*whare parameters int seats[] = int array of storing concert seat info
*		   int size capacity of array 'seats'
*		   int seatNo a paticular seat number 
*/

int main()
{
	const int  MAXSEATS = 4;
	int length;
	int action = 0;
      	int seatNum = 0 ;
	int seats[MAXSEATS];
	length = MAXSEATS ;
	//initialize seats array
	for(int index = 0; index < length; index++)
	{
		seats[index] = 0;
	}	


	do{
		cout << "the start\n";
	//       	cout << "what action do you want to do?\n" 
	//	     << "1: reserve a seat\n2: cancel reservation\n";
	//	cout << "3: check sold-out\n4: print pair seat\n"
	//	     << "5: status of all seats\n6: print how many seats are left\n";
	//	cout << "Enter 7 to end"; 
	//	cin >> action;
	//	cout <<"your action is" << action << "\n";
		
		cout << "check sold out or not\n";
		if(soldOut(seats, length))
		{
			cout << "No seats";
		}
		else
		{
			cout << "not full";
		}
		for(int index = 0; index < length; index++)
		{
			seats[index] = 1;
		}
		if(soldOut(seats,length))
		{
			cout << "No seats available";
		}
		else
		{

			cout << "empty";
		}
	//	getSeatNo(seatNum);
	//	reserveSeat(seatNum, seats,length);
	//	cout << "\n resevation is all done\n";	

		for(int index = 0; index < length; index++)
		{
		 	cout << "status:" <<  seats[index];
		}	

	/*	switch (action)
		{
			case 1:
				//make a resevation
				getSeatNo(seatNum);
				reserveSeat(seatNum, seats, length);
				cout << "\nresevation is done\n";
				break;
			case 2: 
				//cancel a reserved seat
				getSeatNo(seatNum);
				cancelSeat(seatNum, seats, length);
				cout << "\ncansel is done\n";
				break;
			case 3:
				//check if there is a empty seat or not
				soldOut(seats, length);
				cout << "\nsold out is done \n";
				break;
			case 4: //find pair seats
				seatsPair(seats, length);
				cout << "\npair is done\n";
				break;
			case 5: // status of all seats
				seatsStatus(seats, length);
				cout << "\nstatus is over\n";
		 		for(int index = 0; index < length; index++)
				{
					if(seatsStatus(seats,length))
					{
						cout << index << "vacant\n";
					}
					else
					{
						cout << index << "full\n";
					}
						
				}
				break;
			case 6: 
				seatsLeft(seats, length);
				cout <<  "seatLeft";
				break;	
		} */
	}while(!(action < 0));
   
	cout << "\nthank you for using this reservation program.\n";	
	cout << "\nthe end \n\n\n programmed by Kaya Ota\n";	 

	return 0;
}//main

bool soldOut(int seats[], int size)
{
	bool fullness = true;//let all seats are full
	for(int index = 0; index < size; index++)
	{
		if(seats[index] == 0)
		{
			fullness = false;
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
		vacantSeat = false;
		cout << "Sorry your seat number is not vacant .";
	}
	return vacantSeat;
}
bool reserveSeat(int seatNo, int seats[], int size)
{
	bool reservation = false;
	//if(soldOut(seats,size ))//it is true when soldOut retutns false
//	{
		if(seats[seatNo] == 0)
		{
			seats[seatNo] = 1;
			reservation = true;
			cout << "resevation is scuseeded\n";
			cout << "status:" << seats[seatNo];
		}
		else
		{
			cout << "your seat number is not valid";
		}
//	}
//	else
//	{
//		cout << "Sorry all seats have been sold out already";
//	}
	return reservation;
}
bool cancelSeat(int seatNo, int seats[],int  size)
{
	bool cancel = false;
	if(seats[seatNo] == 1)
	{
		seats[seatNo] = 0;
		cancel = true;
		cout << "status:" << seats[seatNo];
		cout << "cancel is finished";
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
void seatsPair(int seats[], int size)
{ 	
	int index;
	if(!soldOut(seats, size))
	{
		for(index = 0; index < size-1  ; index++)
		{
			if(seats[index] == 0 && seats[index+1] == 0)
			{
				cout << index << "&" << index+1 
				     << "are currrently available.";
			}
			else
			{
				cout << "pair seats are sold out";
			}

		}
	}
	else 
	{
		cout << "All seats are sold out, sorry,";
	}
}
bool getSeatNo(int& value)
{	
	bool valid = false;
	bool isDigit = false;
	char seatNum [3];
	int num = 0 ;
	int power = 2;
	cout << "Enter seat number :";
	cin  >>  seatNum;
	cout << "your seat number is" << seatNum;
	//check array is contained digit char or not
	for(int index = 0; index < 3; index++)
	{
		if(isdigit(seatNum[index]))
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
		cout << "seatNum = " << num; 	
	}

	cout << "seatNo ="<< num << "\n"; 	
	if(num < 4 && num >= 0)
	{
		valid = true;
		value = num;
		cout << "num is less than 15 ";
	}		
	else
	{
		valid = false;
		cout << "num is bigger than 15";
	}
	return valid;
}
bool seatsStatus(int seats[], int size)
{
	bool status = false;
	for(int index = 0; index < size; index++)
	{
		if(seats[index] == 0)
		{
			status = true;	
		}
		else if(seats[index] == 1)
		{
			status = false;
		}
	}
	return status;
}
