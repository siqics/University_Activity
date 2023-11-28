#include "array_of_dll.h"





//Siqi Wen  CS202  11/05/2021
//This file contains a test program for the University Activity Program.
//This test program will call the functions in the functions.cpp file
//to complete different missions, including adding an activity of some
//type; retrieving some activity by entering some specific information;
//removing one activity based on some specific information; removing all
//activities; displaying all activities and so on.





int main()
{
	welcome();

	int a_task = 0;         //Create an int variable for user's choice from menu.
	int num_of_priority = 0;

	char input[100];

	arr_of_dll table_object;
	activity * main_ptr = NULL;

	do
	{
		menu(a_task);   //Call menu function.

		if(a_task == 1)
		{
			do
			{
				cout << "\n\n\nEnter the name of the activity: ";
				cin.get(input, 100, '\n');
				cin.ignore(100, '\n');

				main_ptr = new in_person;

				cout << "\n\n\nEnter the priority number for this activity\n"
				     << "(5 is the highest, 1 is the lowest): ";
				do
				{
					cin >> num_of_priority;
					cin.ignore(100, '\n');

					if(num_of_priority < 1 || num_of_priority > 5)
						cout << "\n\nIt has to be between 1-5.\n"
						     << "Enter again: ";

				}while(num_of_priority < 1 || num_of_priority > 5);

				table_object.insert_an_activity(num_of_priority, main_ptr, input);

				cout << "\n\n\nAdd another in_person session?\n\n\n";

			}while(again());
		}

		else if(a_task == 2)
		{
                        do
                        {
				cout << "\n\n\nEnter the name of the activity: ";
				cin.get(input, 100, '\n');
                                cin.ignore(100, '\n');

                                main_ptr = new online_class;

				cout << "\n\n\nEnter the priority number for this activity\n"
                                     << "(5 is the highest, 1 is the lowest): ";

				do
				{
                                	cin >> num_of_priority;
                                	cin.ignore(100, '\n');

					if(num_of_priority < 1 || num_of_priority > 5)
                                                cout << "\n\nIt has to be between 1-5.\n"
                                                     << "Enter again: ";

                                }while(num_of_priority < 1 || num_of_priority > 5);

                                table_object.insert_an_activity(num_of_priority, main_ptr, input);

				cout << "\n\n\nAdd another online class?\n\n\n";

                        }while(again());
                }

		else if(a_task == 3)
                {
                        do
                        {
				cout << "\n\n\nEnter the name of the activity: ";
				cin.get(input, 100, '\n');
                                cin.ignore(100, '\n');

                                main_ptr = new assignment;

				cout << "\n\n\nEnter the priority number for this activity\n"
                                     << "(5 is the highest, 1 is the lowest): ";

				do
				{
                                	cin >> num_of_priority;
                                	cin.ignore(100, '\n');

					if(num_of_priority < 1 || num_of_priority > 5)
                                                cout << "\n\nIt has to be between 1-5.\n"
                                                     << "Enter again: ";

                                }while(num_of_priority < 1 || num_of_priority > 5);

                                table_object.insert_an_activity(num_of_priority, main_ptr, input);

				cout << "\n\n\nAdd another assignment?\n\n\n";

                        }while(again());
                }

		else if(a_task == 4)
		{
			cout << "\n\n\nEnter the name of the activity: ";
                        cin.get(input, 100, '\n');
                        cin.ignore(100, '\n');

			cout << "\n\n\nEnter the priority number for this activity\n"
                                     << "(5 is the highest, 1 is the lowest): ";

			do
                        {
                        	cin >> num_of_priority;
                                cin.ignore(100, '\n');

                                if(num_of_priority < 1 || num_of_priority > 5)
                                        cout << "\n\nIt has to be between 1-5.\n"
                                             << "Enter again: ";

                        }while(num_of_priority < 1 || num_of_priority > 5);

			if(!table_object.remove_an_activity(num_of_priority, input))
				cout << "\n\n\nSorry, there is no matching activity name...\n\n\n";
			else
				cout << "\n\n\nCongrats! We deleted activity: "
				     << input << " successfully!\n\n\n";
		}

		else if(a_task == 5)
		{
			table_object.display_all();
		}

		else if(a_task == 6)
                {
			if(!table_object.remove_all())
				cout << "\n\n\nThere is nothing to remove!\n\n\n";
			else
				cout << "\n\n\nEverything was removed!\n\n\n";
                }

		if(a_task != 7)
			cout << "\n\n\nWanna check the menu again?\n\n";

	}while(a_task != 7 && again());  //Call again function. Continue until user wants to stop.

	cout << "\n\n\n\n\nThank you for using our program!\nHave a great day!\n\n\n\n\n";

	return 0;
}





//Output the welcome message and explain what the program can do.
void welcome()
{
	cout << "\n\n\n\nWelcome to our University Activity program!\n\n\n"
	     << "There are three types of activities included in this program"
	     << ":\n1. In-person sessions;\n2. Online classes;\n3. Assignments."
	     << "\nIn this program, you'll be able to add new activities by"
	     << " entering some information.\nYou can also look for a specifc"
	     << " activity based on the name and the number of priority.\nIn "
	     << "addition, you can delete one or all activities.\n\n\n\n";
}



//This function asks the user if they want to do it again by
//prompting the user for an input, true or false will be returned.
bool again()
{
	char answer;                              //Create a character variable
	do
	{
		cout << "\n\n\n\nPlease enter Y/y or N/n: ";
        	cin >> answer;                       //Read in the user's answer.
        	cin.ignore(100, '\n');
        	answer = toupper(answer);            //Convert the character to an uppercase letter
        	if (answer != 'Y' && answer != 'N')
        		cout << "\n\nYou entered a wrong letter. Please enter Y/y or N/n.";
	}while(answer != 'Y' && answer != 'N'); //continue until the uppercase letter is Y or N
	if (answer == 'Y')                      //This function will return true if answer is Y
        	return true;
	return false;                           //Return false if answer is N
}



//This function takes an integer as an argument and it will show the user the menu, and
//prompts the user to enter a choice in terms of which task the user wants to do.
void menu(int & task)
{
	cout << "\n\n\n\nHere is the menu:\n\n"
	     << "Enter 1 - Add an activity - Add an in_person session.\n\n"
	     << "Enter 2 - Add an activity - Add an online class.\n\n"
	     << "Enter 3 - Add an activity - Add an assignment.\n\n"
	     << "Enter 4 - Remove an activity.\n\n"
	     << "Enter 5 - Display all activities.\n\n"
	     << "Enter 6 - Remove all activities.\n\n"
	     << "Enter 7 - Exit.\n\n\n\n\n"
	     << "Now, please enter a number (1-7): ";
        do
        {
        	cin >> task;               //Read in the user's answer.
		cin.ignore(100, '\n');
		if(task < 1 || task > 7)
	        	cout << "\n\nYou entered a wrong number!\n\nPlease enter "
			     << "a number between 1 and 7(inclusive): ";
        }while(task < 1 || task > 7);  //Repeat until user enters a proper number.
}

