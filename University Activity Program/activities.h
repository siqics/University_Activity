#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;





//Siqi Wen   CS202  11/05/2021
//This file is a .h file that contains the interfaces of
//a base class (that is an abstract base class) and three
//derived classes. The abstract base class is: activity,
//it have member functions that are actually virtual functions,
//because we will need to do dynamic binding in this program.
//The activity class has two data members: a char pointer
//pointing to the information of the activity's name; an integer
//representing the time we need to spend for this activity. The
//three derived classes are: in_person; online_class and assignment.
//They all have their own special data members. They have some
//self-similar functions, and each of them has one special member
//function that we need to use RTTI to call.





class activity
{
	public:
		activity();
		virtual ~activity();
		void delete_activity();

		virtual int name_of_activity(char* input);
		virtual void time_spent();
		virtual void display() = 0;
		virtual int compare_names(char* input);
	protected:
		char * name;
		int time_needed;
};



class in_person: public activity
{
	public:
		in_person();
		in_person(const in_person & source);
		~in_person();
		void delete_inperson();

		int name_of_activity(char* input);
		void time_spent();
		void display();
		void classroom_address();
		int compare_names(char* input);
	protected:
		char * address;
};



class online_class: public activity
{
	public:
		online_class();
		
		int name_of_activity(char* input);
                void time_spent();
                void display();
		void duration_of_class();
		int compare_names(char* input);
	protected:
		int duration;
};



class assignment: public activity
{
	public:
		assignment();

		int name_of_activity(char* input);
                void time_spent();
                void display();
		void amount_of_tasks();
		int compare_names(char* input);
	protected:
		int tasks;
};





//Prototypes
void welcome();            //Output the welcome message.
bool again();              //Ask if the user wants to do again.
void menu(int & task);     //Show the user the menu.


