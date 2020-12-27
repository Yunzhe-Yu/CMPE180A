/*
 * WarAndPeace.cpp
 *
 *  Created on: 9/8/2020
 *      Author: yunzheyu
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<iomanip>

using namespace std;

// Names to search for.
const string ALEXEEVICH  = "Makar Alexeevich";
const string ALEXEEVICH1  = "Makar";
//const string ALEXEVICH1 = "Makar\n";
//search for the Name which be seperated into 2 lines
//I tried to use above lines but it does not work
const string BAZDEEV     = "Joseph Bazdeev";
const string BAZDEEV1     = "Joseph";
const string DRUBETSKOY  = "Boris Drubetskoy";
const string DRUBETSKOY1  = "Boris";

//open the txt file "WarAndPeace.txt" in the directory
const string INPUT_FILE_NAME = "WarAndPeace.txt";

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    cout<<" LINE  POSITION  NAME"<<endl;
    /****Test file!!****/
  /*  int count = 0;
    string line;
    while(getline(input,line)){
    	count++;
    }
    cout<<"Total Lines: "<<count;*/
    string line;
    int linenumber = 1;
    int countnumber =0;
   // vector<string>lineforsave;
  //  while(!input.eof()){
  //  	getline(input,line);
   // 	linenumber++;
    	//lineforsave.push_back(line);
    //	}
    while(!input.eof()){
    	getline(input,line);
    	//char*searchstring = getline(input,line);
    	//make sure the position of "Makar Alexeevich" in a line
    	if(line.find(ALEXEEVICH)!=string::npos){
    		countnumber = linenumber;// if it finds the Name, give linenumber to countnumber
    		string flag = "Makar";
    		int position = 0;
    		while((position =line.find(flag,position))!=string::npos){
        		position++;//give the flag and when it reads the line, which it catches the flag
        		//return the position
    		cout<<countnumber<<setw(10)<<position<<"  "<<"Makar Alexeevich"<<endl;
    		}
    	}
    	//make sure the position of "Makar Alexeevich" is not in a line
    	if(line.find(ALEXEEVICH1)!=string::npos){
    		countnumber = linenumber;
    		string flag = "Makar";
    		int position = 0;
    		while((position =line.find(flag,position))!=string::npos){
        		position++;
        	if(position>=60){
    		cout<<countnumber<<setw(10)<<position<<"  "<<"Makar Alexeevich"<<endl;
        		}
    		}
    	}
    	//make sure the position of "Joseph Bazdeev" in a line
    	if(line.find(BAZDEEV)!=string::npos){
    		countnumber = linenumber;
    		string flag = "Joseph";
    		int position = 0;
    		while((position =line.find(flag,position))!=string::npos){
        		position++;
    		cout<<countnumber<<setw(10)<<position<<"  "<<"Joseph Bazdeev"<<endl;
    		}
    	}
    	//make sure the position of "Joseph Bazdeev"is not in a line
    	if(line.find(BAZDEEV1)!=string::npos){
    		countnumber = linenumber;
    		string flag = "Joseph";
    		int position = 0;
    		while((position =line.find(flag,position))!=string::npos){
        		position++;
        		if(position==60){
    		cout<<countnumber<<setw(10)<<position<<"  "<<"Joseph Bazdeev"<<endl;
        		}
    		}
    	}
    	//make sure the position of "Boris Drubetskoy" in a line
    	if(line.find(DRUBETSKOY)!=string::npos){
    		countnumber = linenumber;
    		string flag = "Boris";
    		int position = 0;
    		while((position =line.find(flag,position))!=string::npos){
        		position++;
    		cout<<countnumber<<setw(10)<<position<<"  "<<"Boris Drubetskoy"<<endl;
    		}
    	}
    	//make sure the position of "Boris Drubetskoy"is not in a line
    	if(line.find(DRUBETSKOY1)!=string::npos){
    		countnumber = linenumber;
    		string flag = "Boris";
    		int position = 0;
    		while((position =line.find(flag,position))!=string::npos){
        		position++;
        	if(position==62&&linenumber>10000){
    		cout<<countnumber<<setw(10)<<position<<"  "<<"Boris Drubetskoy"<<endl;
        		}
    		}


    	}
    	linenumber++;
    }


  //  cout<<linenumber;

    }
/***** Complete at 09/12/2020 17:20. *****/
