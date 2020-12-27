/*
 * The_Monty_Hall_Probelm.cpp
 *
 *  Created on: 9/1/2020
 *      Author: yunzheyu 015287714
 */

#include <iostream>
#include <fstream>
#include<cstdlib> // use to create a random number via rand()%n +1;
#include<ctime>
#include<iomanip> //if we use setprecision to setup space, we must use this

/***** Completed on 4th September 23:42 *****/

using namespace std;
typedef int Door;


const int SIMULATION_COUNT = 100;
//void simulate(int i, int x, int y);
void simulate(int i, int &x, int &y);//if we don't use &, the out put will be 0;
/*simulate:
 * It can calculate the total number of times of first win or second win
 * and it can control the times not great than 100!
 */



Door hideCar();
/** 				hide car:
 * put the brand new car behind to a door randomly (create a random door )
 */


Door openDoor(int HideCar, int MakeFirstChoice);
/**  openDoor:
 * Open a door from three randomly
 */


Door makeFirstChoice();
/** makeFirstChoice:
 * open a door randomly at the first time.
 */


Door makeSecondChoice(int MakeFirstChoice, int Door_opened);
/** makeSecondChoice
 * After monty opens the door, you can stay or makeSecondChoice between rest 2 doors
 * int this part, I try create a random number from first_guess door and third door
 * do not mention to second door
 */


int main()
{
    int win1 = 0, win2 = 0;
	cout<<"   #     HideCar   First  Opened  Second    Win    Win"<<endl;
	cout<<"          here    choice    door  choice  first second"<<endl;
	cout<<endl;

    // Run the simulations.
    for (int i = 1; i <= SIMULATION_COUNT; i++) simulate(i, win1, win2);
    cout<<"   "<<win1<<" wins if stay with the first choice"<<endl;
    cout<<"   "<<win2<<" wins if stay with the first choice"<<endl;
    double ratio = 1.0*win1/win2;
    cout<<"Win ratio of switch over stay: "<<setprecision(3)<<ratio<<endl;

}

Door hideCar(){
	int hideCar = rand()%3+1; // Create a random door number, and let us assume the car behind this door
	return hideCar;


}//hide car

Door openDoor(int HideCar, int MakeFirstChoice){

	int Door_opened;
    if(HideCar == MakeFirstChoice){
    	for(int i =0;; i++){ // use a huge loop to make sure if hidecar is equal to opendoor
    	int OpenDoor = random()%3+1;
    	if(OpenDoor!=HideCar){
    		Door_opened = OpenDoor;
    		break;
    	}
    	}
    }else{
    	for(int i=0;;i++){
    		int OpenDoor = random()%3+1;
    		if(OpenDoor!=HideCar && OpenDoor!=MakeFirstChoice){
    			Door_opened = OpenDoor;
    			break;
    		}
    	}
    }

    return Door_opened;
}//openDoor





void simulate(int i, int &x, int &y)
{
    int HideCar = hideCar();
    int MakeFirstChoice = makeFirstChoice();
    int OpenDoor = openDoor(HideCar,MakeFirstChoice);
    string status_win1 = "  ";
    string status_win2 = "  ";
	int MakeSecondChoice = makeSecondChoice(MakeFirstChoice, OpenDoor);
	if(HideCar == MakeFirstChoice){
		status_win1 = "yes";
		x++;//calculate times of win1
	}else if(HideCar == MakeSecondChoice){
		status_win2 ="yes";
		y++;//calculate times of win2
	}
	cout<<setw(4)<<i<<setw(8)<<HideCar<<setw(10)<<MakeFirstChoice<<setw(8)<<OpenDoor<<setw(8)<<MakeSecondChoice;
	cout<<setw(8)<<status_win1<<setw(8)<<status_win2<<endl;

}//simulate


Door makeFirstChoice(){
	int makeFirstChoice = rand()%3+1; // randomly to choice a door at firt time
	return makeFirstChoice;
}//firstchoice


Door makeSecondChoice(int MakeFirstChoice, int Door_opened){
	int SecondChoice = random()%3+1;
	int SecondDoor;
	while(SecondChoice==Door_opened){//if second choice = opened door ,let us choice it again until they are not equal
	 SecondChoice = random()%3+1;
 }
 	 	 SecondDoor = SecondChoice;
 	 	 return SecondDoor;
}
