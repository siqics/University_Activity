#include "array_of_dll.h"





//Siqi Wen  CS202  11/05/2021
//This file contains the implementations of the member
//functions in the four classes in the hierarchy. 
//There are member functions to read in the name of the
//activity; the time needed for the activity; the priority
//of the activity. Each derived class also has it's own
//member function that's not similar to any in the other two
//classes. In addition, this file also incudes the implementations
//of the member functions in the node class and the array_of_dll
//class. These functions allow user to insert new activities,
//retrieve an activity, remove an activity, display all activities
//and remove all activities.





//This is the constructor of the activity class. It initializes
//all data members to their zero equivalent values.
activity::activity(): name(nullptr), time_needed(0)
{

}



//This is the destructor for the activity class.
activity::~activity()
{
	delete_activity();
}



//This function takes no argument and returns nothing.
//It will reset the data members to their zero equivalent
//values for activity class and will be called in the 
//destructor of the activity class.
void activity::delete_activity()
{
	if(name)
        {
                delete []name;
                name = NULL;
        }
        time_needed = 0;
}



//This function takes a char pointer. It would copy
//the data from the argument into the data member.
//0 will be returned if the argument is invalid.
//1 will be returned if it was successful.
int activity::name_of_activity(char* input)
{
	if(!input)
		return 0;

	if(name)
		delete []name;

	name = new char[strlen(input)+1];
	strcpy(name, input);

	cout << "\n\nThe activity name you entered was: "
	     << name << "\n\n\n";
	return 1;
}



//This function reads in the answer from user for
//the data member: time_needed. It returns nothing.
void activity::time_spent()
{
	cout << "\n\n\nNow, enter the required time length for"
	     << " the activity ( " << name << " ) in hrs: ";
	cin >> time_needed;
	cin.ignore(100, '\n');

	cout << "\n\nEnter the time needed for this activity is: "
	     << time_needed << "\n\n\n";
}



//This function takes a char pointer as an argument and returns an integer.
//It would compare the argument with the data member, if they match, 1 will
//be returned; if not, 0 will be returned.
int activity::compare_names(char* input)
{
	if(!input)
		return 0;
	if(!strcmp(input, name))
		return 1;
	return 0;
}



//This is the default constructor for the in_person class.
//It initialize its data memeber to nullptr.
in_person::in_person(): address(nullptr)
{
}



//This is the copy constructor of in_person class because
//it manages dynamic memory.
in_person::in_person(const in_person & source)
{
	if(source.address)
	{
		address = new char[strlen(source.address)+1];
		strcpy(address, source.address);
	}
}
		


//This is the destructor of in_person class.
in_person::~in_person()
{
	if(address)
	{
		delete []address;
		address = NULL;
	}
}

		

//This function calls the function in the base class, which
//has the same function name, same argument list and same
//return type.
int in_person::name_of_activity(char* input)
{
	return activity::name_of_activity(input);
}


		
//This function calls the function in the base class, which
//has the same function name, same argument list and same
//return type.
void in_person::time_spent()
{
	activity::time_spent();
}
		


//This function reads in an answer from user for the address.
//Nothing will be returned.
void in_person::classroom_address()
{
	char input[100];

	cout << "\nEnter the address of the classroom: ";
	cin.get(input, 100, '\n');
	cin.ignore(100, '\n');

	address = new char[strlen(input)+1];
	strcpy(address, input);

	cout << "\n\nThe address you entered was: "
	     << address << "\n\n\n";
}

		

//This function displays the values of the data members.
void in_person::display()
{
	cout << "\n\n\nHere is the info of the activity:\n"
	     << "Type: In_person class\n"
	     << "Name: " << name << "\nTime needed: "
	     << time_needed << " hrs\nAddress of the classroom is: " 
	     << address << "\n\n";
}



//This function takes a char pointer as an argument and returns
//an integer, it would call a function from the abstract base class,
//the returned value would be the returned value from the function
//that is being called.
int in_person::compare_names(char* input)
{
	return activity::compare_names(input);
}



//This is the default constructor of online_class class.
//It initializes the data member to its zero equivalent value.	
online_class::online_class(): duration(0)
{
}
		
		

//This function calls the function in the base class, which
//has the same function name, same argument list and same
//return type.
int online_class::name_of_activity(char* input)
{
	return activity::name_of_activity(input);
}


              
//This function calls the function in the base class, which
//has the same function name, same argument list and same
//return type.
void online_class::time_spent()
{
	activity::time_spent();
}



//This function reads in the answer from user for the duration
//of the class. Nothing will be returned.
void online_class::duration_of_class()
{
	cout << "\n\n\nEnter the duration of the acticity (" 
	     << name << "), enter in hours: ";
	cin >> duration;
	cin.ignore(100, '\n');
	
	cout << "\n\n\nThe duration you entered was: "
	     << duration << " hour(s)\n\n\n";
}


                
//This function displays the values of the data members. Nothing
//will be returned.
void online_class::display()
{
	cout << "\n\n\nHere is the info of the activity:\n"
	     << "Type: Online class\n"
             << "Name: " << name << "\nTime needed: "
             << time_needed << " hrs\nThe duration of the online class is: " 
             << duration << " hr(s)\n\n";
}



//This function takes a char pointer as an argument and returns
//an integer, it would call a function from the abstract base class,
//the returned value would be the returned value from the function
//that is being called.
int online_class::compare_names(char* input)
{
        return activity::compare_names(input);
}



//This is the default constructor.
assignment::assignment(): tasks(0)
{
}



//This function calls the function in the base class, which
//has the same function name, same argument list and same
//return type.
int assignment::name_of_activity(char* input)
{
	return activity::name_of_activity(input);
}



//This function calls the function in the base class, which
//has the same function name, same argument list and same
//return type.
void assignment::time_spent()
{
	activity::time_spent();
}
                


//This function reads in the answer from user for the amount
//of tasks for the assignment. Nothing will be returned.
void assignment::amount_of_tasks()
{
	cout << "\n\n\nEnter the number of tasks you need"
	     << " to complete for the activity( " << name
	     << " ): ";
	cin >> tasks;
	cin.ignore(100, '\n');

	cout << "\n\nThe number of tasks you entered was: "
	     << tasks << "\n\n\n";
}



//This function displays the values of the data members. Nothing
//will be returned.
void assignment::display()
{
	cout << "\n\n\nHere is the info of the activity:\n"
	     << "Type: Assignment\n"
             << "Name: " << name << "\nTime needed: "
             << time_needed << " hrs\nThe number of tasks is: " << tasks << "\n\n";
}



//This function takes a char pointer as an argument and returns
//an integer, it would call a function from the abstract base class,
//the returned value would be the returned value from the function
//that is being called.
int assignment::compare_names(char* input)
{
        return activity::compare_names(input);
}




//This is the default constructor for the node class.
//It initializes the data members.
node::node(): event_ptr(nullptr), prev(nullptr), next(nullptr)
{
}



//This is the desturctor for the node class, it will
//call another function to reset the data members.
node::~node()
{
	move_a_node();
}



//This function takes no argument and returns nothing. It
//resets the data members in the node class to their zero
//equivalent values. This will be called in the destructor.
void node::move_a_node()
{
	if(event_ptr)
        {
                event_ptr->delete_activity();
                event_ptr = NULL;
        }
        prev = NULL;
        next = NULL;
}



//This function takes no argument and returns an activity pointer
//by reference.
activity *& node::get_event_ptr()
{
	return event_ptr;
}

		

//This function takes no argument and returns a node pointer
//by reference.
node *& node::go_prev()
{
	return prev;
}



//This function takes no argument and returns a node pointer
//by reference.
node *& node::go_next()
{
	return next;
}



//Constructor - initialize the data members.
arr_of_dll::arr_of_dll(int size)
{
	//Allocate the hash table and initialize each
	//element and data member.
	table_ptr = new node* [size];
	for(int i = 0; i < size; ++i)
		table_ptr[i] = NULL;
	ht_size = size;
	priority = 0;
}



//This is the destructor of the array_of_dll class.
//It would call another function to remove all nodes
//in the DLL and it would reset the data members to
//their zero equivalent values.
arr_of_dll::~arr_of_dll()
{
	remove_all();
	ht_size = 0;
	priority = 0;
}



//This function takes an integer as an argument and returns
//an integer as the index of the array of DLL.
int arr_of_dll::converting_index(int num_priority)
{
	if(num_priority == 5)
		return 0;
	else if(num_priority == 4)
		return 1;
	else if(num_priority == 3)
		return 2;
	else if(num_priority == 2)
		return 3;
	else
		return 4;
}



//This function takes an integer, an activity pointer and a char pointer
//as arguments, it returns nothing. This function would insert the node
//that contains the right object information into the array of DLL.
void arr_of_dll::insert_an_activity(int num_priority, activity * main_ptr, char* input)
{
	int index = converting_index(num_priority);
	
	node * hold = table_ptr[index];

	table_ptr[index] = new node;
	table_ptr[index]->get_event_ptr() = main_ptr;
	table_ptr[index]->go_prev() = NULL;
	table_ptr[index]->go_next() = hold;

	if(hold)
		hold->go_prev() = table_ptr[index];
	
	//Using RTTI to determine which function to call.
	in_person * ptr_inperson = dynamic_cast <in_person*> (main_ptr);
	if(ptr_inperson)
	{
		ptr_inperson->name_of_activity(input);
		ptr_inperson->time_spent();
		ptr_inperson->classroom_address();
		ptr_inperson->display();
	}
	
	online_class * ptr_online = dynamic_cast <online_class*> (main_ptr);
	if(ptr_online)
	{
		ptr_online->name_of_activity(input);
                ptr_online->time_spent();
		ptr_online->duration_of_class();
                ptr_online->display();
	}

	assignment * ptr_homework = dynamic_cast <assignment*> (main_ptr);
	if(ptr_homework)
	{
		ptr_homework->name_of_activity(input);
                ptr_homework->time_spent();
		ptr_homework->amount_of_tasks();
                ptr_homework->display();
	}
	cout << "The priority for this activity is: " << num_priority << "\n\n";
}



//This function takes an integer and a char pointer as an argument, it would
//call a recursive function and return 0 if nothing was moved, return 1 otherwise.
int arr_of_dll::remove_an_activity(int num_priority, char * the_name)
{
	node * found = NULL;
	int match = find_an_activity(num_priority, the_name, found);
	
	if(!match)
		return 0;

	int index = converting_index(num_priority);

	node * front = NULL;

	remove_an_activity(front, found, table_ptr[index]);

	return 1;

}



//This function takes three node pointers and they are passed by reference.
//It would remove the matching node. Nothing will be returned.
void arr_of_dll::remove_an_activity(node *& front, node *& found, node *& current)
{
	if(found == current)
	{
		node * hold = found->go_next();
		if(front)
		{
			front->go_next() = hold;
		}
		else
		{
			current = hold;
		}

		if(hold)
			hold->go_prev() = front;

		found->get_event_ptr()->delete_activity();
                delete found;
		found = NULL;

		return;
	}

	front = current;
	return remove_an_activity(front, found, current->go_next());
}



//This function takes an integer, a char pointer and a node pointer (pass by reference),
//1 will be returned if a matching node was found, otherwise, 0 will be returned.
int arr_of_dll::find_an_activity(int num_priority, char * the_name, node *& found)
{
	int index = converting_index(num_priority);
	int match = 0;

	return find_an_activity_recursion(table_ptr[index], the_name, found, match);
}



//This function takes a node pointer(passed by value), a char pointer, a node pointer
//(passed by reference) and an integer(passed by reference) as arguments, it would check
//if there's a matching node, 1 will be returned if there is. Otherwise, 0 will be returned.
int arr_of_dll::find_an_activity_recursion(node* current, char* the_name, node*& found, int& match)
{
	if(match || !current)
		return match;

	if(current->get_event_ptr()->compare_names(the_name))
	{
                        match = 1;
                        found = current;
                        cout << "\n\n\nWe found a match!\n\n";
                        current->get_event_ptr()->display();
        }


	return find_an_activity_recursion(current->go_next(), the_name, found, match);
}



//This function takes no argument and returns an integer.
//If the array of DLL is empty, which means there's nothing
//to remove, then 0 will be returned. If everything was removed
//successfully, 1 will be returned. A recursive function will be
//called in this function.
int arr_of_dll::remove_all()
{
	int empty = 0;

	for(int i = 0; i < ht_size; ++i)
	{
		if(table_ptr[i])
		{
			remove_all_recursion(table_ptr[i]);
			table_ptr[i] = NULL;

			empty = 1;
		}
	}
	return empty;
}



//This function takes a node pointer as an argument, it
//is passed by reference, nothing will be returned. This
//recursive function will be invoked in another function.
void arr_of_dll::remove_all_recursion(node *& current)
{
	if(!current)
		return;

	node * hold = current->go_next();

	current->get_event_ptr()->delete_activity();
	delete current;
	current = hold;

	remove_all_recursion(current);
}



//This function calls a recursive function to display all info
//in the array of DLL. Nothing will be returned.
void arr_of_dll::display_all()
{
	int i = 0;
	while(i < ht_size)
	{
		if(!display_all_recursion(table_ptr[i], i))
			++ i;
	}
}



//This function takes a node pointer and an integer as arguments, 0 will be
//returned if the node pointer is NULL. It is a recursive function.
int arr_of_dll::display_all_recursion(node * current, int num)
{
	if(!current)
		return 0;

	int priority_num = 0;
	if(num == 0)
		priority_num = 5;
	else if(num == 1)
		priority_num = 4;
	else if(num == 2)
		priority_num = 3;
	else if(num == 3)
		priority_num = 2;
	else if(num == 4)
		priority_num = 1;

	//Using RTTI to determine which function to call.
	in_person * ptr_inperson = dynamic_cast <in_person*> (current->get_event_ptr());
        if(ptr_inperson)
        {
		ptr_inperson->display();
		cout << "The priority is: " << priority_num << "\n\n";
	}

	online_class * ptr_online = dynamic_cast <online_class*> (current->get_event_ptr());
        if(ptr_online)
        {
		ptr_online->display();
		cout << "The priority is: " << priority_num << "\n\n";
	}

	assignment * ptr_homework = dynamic_cast <assignment*> (current->get_event_ptr());
        if(ptr_homework)
        {
		ptr_homework->display();
		cout << "The priority is: " << priority_num << "\n\n";
	}

	return display_all_recursion(current->go_next(), num);
}


