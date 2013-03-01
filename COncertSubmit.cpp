/*Kaya Ota
 *CIS278 Spring 2013
 *Created on 2013/02/27, 23:41
 *File:Concert.cpp
 */
#include <iostream>
#include <cmath>
#include <cstring>
#include<cstdlib>
using namespace std;
//function list
bool soldOut(int seats[], int size);//determines if all  seats are sold
int seatsLeft(int seats[], int size);//count up how many seats are left
bool validSeatNum(int seatNo, int size);//check if user type is valid num or not 
bool seatVacant(int seatNo, int seats[]);//check if a specific seat is vacant or not
bool reserveSeat(int seatNo, int seats[], int size);//make a seat reservation 
int furthestFront(int seats[], int size);//find the furthest seat from front 
void pairSeat(int seats[], int size);//find a pair seat
bool getSeatNo(int& value);//determines if user input is containd real char or char as num
bool cancelSeat(int seatNo, int seats[], int size);//cancel a seat
void showStatus(int seats[], int size);   
//main
int main() 
{
	int const MAXSEATS = 10;//decide how seats array is long
	int  seats [MAXSEATS];//declare array named seats with its length  
	int action = 0;//indicates which action user want
	int cancel;
	int seatNum;//store seatNum
        //initialize variables 
        for(int index = 0; index < MAXSEATS; index++)
        {
		 seats[index] = 0;
        }
	action = 0;
        seatNum = 0;
        do
        {
		 cout << "0: Exist this program.\n"
	              << "1: Check if seats are sold out.\n" 
            	      << "2: Reserve a seat.\n" 
                      << "3: Find the furthest seat available.\n" 
                      << "4: Find seats that are next to each other.\n"
                      << "5: Cancel a reserved seat.\n" 
                      << "6: Print out the number of seats left.\n" 
                      << "7:Print out the status of all seats.\n";
       		 cin >> action;
		 switch(action)
	         {
		case 0:
      			cout << "Exit from this program";
       			cout << "Thank you for using!";
       			cout << "Programmed by Kaya Ota";		       
		case 1:
	               	if(soldOut(seats,MAXSEATS))
               		 {
              			 cout << "This concert is already sold out.\n";
			 }
			 else
			 {
		                 cout << "There are still seats available. ASAP to reserve!\n";
			 }
				break;
           	case 2://reserve seat
     			 while(!getSeatNo(seatNum) || !validSeatNum(seatNum,MAXSEATS));
               		 reserveSeat(seatNum,seats, MAXSEATS);
                	break;
		case 3://cancel seat
               		while(!getSeatNo(seatNum) || !validSeatNum(seatNum, MAXSEATS));
               		cancelSeat(seatNum, seats, MAXSEATS);
            		break;
		case 4:///find pairSeat
                	pairSeat(seats, MAXSEATS);
                	break;
		case 5://find the furthest seat
                	cout <<"Find the furthest seats from the front";
               		furthestFront(seats, MAXSEATS);
               		break;
           	case 6:
                	cout << seatsLeft(seats, MAXSEATS) <<" seats are left.";
                	break;
		case 7:
                	showStatus(seats,MAXSEATS);
               		break;
		}//switch
        }while(action != 0);//while
	return 0;
}
void showStatus(int seats[], int size)
{
     for(int index = 1; index < size; index++)
     {
        if(seats[index] == 0)
        {
            cout << "Seat " <<index<< " is available.\n";
        }
        else if(seats[index] == 1)
        {
            cout <<"Seat " << index<< " is not available.\n";
        }
        else
        {
            cout << "element is invalid";
        }
     }//for
}//show status
bool soldOut(int seats[], int size)
{
     bool soldOut = true;
     int index = 0;
     for(index = 0; index < size;index++)
     {
        if (seats[index] != 0)
        { 
                soldOut = true;         
        }
        else
        {
		soldOut = false;
        }        
     }//for 
        return soldOut;
}
int seatsLeft(int seats[], int size)
{
      int available= 0;        
      for(int index = 0; index < size; index++)
      {
          if(seats[index] == 0)
          {
              available++;
          } 
      }
      return available;
}
bool seatVacant(int seatNo, int seats[])
{
        bool seatVacant = true;
        if(seats[seatNo] == 0)
        {
            seatVacant = true;
        }
        else
        {
            seatVacant = false;
        }   
        return seatVacant;
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
        return validate;

 }
bool reserveSeat(int seatNo, int seats[], int size)
{
        bool reservation = true;
        if(!soldOut(seats,size))
        {
	        seats[seatNo] = 1;
                cout << "Seat "<< seatNo << " is now reserved.\n";
                reservation = true;
        }
        else
        {
		cout << " seat number is sold out\n"; 
                reservation = false;
        }        
        return reservation; 
}
bool cancelSeat(int seatNo, int seats[], int size)
{
      bool cancelSeat = true;
      cout << "Seat Number Test 1 : " << seatNo << "\n";
      if(seats[seatNo] == 1)
      {
          seats[seatNo] = 0;
          cancelSeat = true;
          cout << "Seat Number Test 2 : " << seatNo;
          cout << "\n";
          cout << seats[seatNo];
      }
      else
      {
          cancelSeat = false;
      }
      return cancelSeat;
}
int furthestFront(int seats[], int size)
{
      int index = 0;
      int furthest = 0;
      for(index = 0; index < size; index++)
      {
          if(seats[index] == 0)
          {
              furthest = index;
          }
      }
      cout << furthest << "is an available seat from the front";
}
bool getSeatNo(int& value)
{
      bool validSeat = true;
      int index = 0;
      char seatNum [3];
      for(int initial = 0; initial < 3; initial++)
      {
          seatNum[initial] = '\0';
      }
      cout << "Enter seat number: ";
      cin >>  seatNum;
      while(seatNum[index] !=  '\0')
      {       
          if(!isdigit(seatNum[index]))
          {
              validSeat = false;
              return validSeat;
          }
          index++;
      }      
      value = atoi(seatNum);
      return validSeat;
}
void pairSeat(int seats[], int size)
{
	int index = 0;
	for(index = size; index > 0; index--)
	{
		if(seats[index]==0 && seats[index+1] == 0)
		{
			cout << index  << "&" << index+1 <<" are available for pair seats";
		}
	}
} 
