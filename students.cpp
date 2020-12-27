//Yunzhe Yu 015287714
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const string INPUT_FILE_NAME = "students.txt";

/*
 * Use the Typedef to simplify the pointer*/
typedef int **STUDENTSCORES;
typedef string*NAME;

/*
 * 			PRINT_NAME
 * Combine firstname and lastname into one string, and
 * save this string in a new string in order to
 * print it out
 */
string print_name(string firstname, string lastname);
/*
 * 			PRINT_TABLE
 * 	In order to print the name and check if there is no grades
 * 	after the student name, and if there are some grades, print
 * 	it out in order.
 */
void print_table(int numberofstudent,NAME name, STUDENTSCORES studentscores);


/*
 * Main Function
 * hint: because I don't know how to call the "input>>" in other
 * functions, so there is a huge Main function.
 */
int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    string coursename;
    int numberofstudent;
    input>>coursename>>numberofstudent;
    string firstname;
    string lastname;
    NAME name = new string[numberofstudent];
	STUDENTSCORES studentscores = new int*[numberofstudent];
	for(int i=0;i<numberofstudent;i++){
		input>>firstname>>lastname;
		name[i]=print_name(firstname,lastname);
		int countnumber;
		input>>countnumber;
		studentscores[i]=new int[countnumber+1];
		int t=0;
		while(t<countnumber){
			input>>studentscores[i][t];
			t++;
		}
	}
	input.close();
	cout<<"STUDENT SCORES for ";
	cout<<coursename;
	cout<<endl<<endl;
	print_table(numberofstudent,name,studentscores);
	/***** Completed at 09/20/2020 19:51. *****/
}
/*
 * Code of Print_name
 * Return a new function with each student's
 * firstname and lastname, and in main function
 * save the new string in string array.
 */
string print_name(string firstname, string lastname){
	string c;
	c = firstname +' '+ lastname;
	return c;
}
/*
 * Code of Print_table
 * Check if there is a grade after the student name
 * use the place of student score and print there is
 * none grades or grades.
 */
void print_table(int numberofstudent,NAME name, STUDENTSCORES studentscores){
	int check = 0;
	for(int i =0;i<numberofstudent;i++){
		cout<<name[i]<<endl;
    	for(int j=0;;j++){
    		if(check==0){
    		   if(studentscores[i][check]=='\0'){
    			   cout<<"   (none)";
    			   break;
    		   }else{
    		      cout<<setw(5)<<studentscores[i][check];
    		   }
    		}else if(studentscores[i][check]!='\0'){
    			cout<<setw(5)<<studentscores[i][check];
    		}else{
    			break;
    		}
    		check++;
    	}
    	cout<<endl;
    	cout<<endl;
    	check=0;
	}
}
