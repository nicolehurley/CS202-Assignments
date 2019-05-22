//Nicki Hurley
//July 21, 2018
//Program 2 CS202
//
//
//This is the main/test file for a program that allows one to log 
//guest activities.

#include "program2.h"


int main()
{
	int choice;
//	activity  * input;
	CLL a_CLL;

	cout << "Welcome." << endl;
	do 
	{
		cout << "Would you like to:" << endl
		<< "(1) Add Data" << endl
		<< "(2) Remove Data" << endl
		<< "(3) Display Data" << endl
		<< "(4) Quit" << endl;

		//cin.get(choice, 100, '\n');
		cin >> choice;
		cin.ignore(100, '\n');
	
		if(choice == 1)
		{
			if(a_CLL.add())
				cout << "Success!" << endl;
		}
		else if(choice == 2)
		{
			if(a_CLL.remove())
				cout << "Success!" << endl;
			else
				cout << "Activity not found." << endl;		
		}
		else if(choice == 3)
		{
			a_CLL.display();	 
		}
		
	} while(choice != 4);




	return 0;
}
