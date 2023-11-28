#include "activities.h"





//Siqi Wen  CS202  11/05/2021
//This file contains the class interface for the array of dll.
//This class has a private data member which is a pointer to
//an activity object, and this pointer can also point to the
//derived class object by using RTTI. There are member functions
//that support insert, removal, display, retrieval, and remove-all.
//In the private section, there are also recursive member functions 
//that uses recursion to complete those missions.




class node
{
	public:
		node();
		~node();
		void move_a_node();

		activity *& get_event_ptr();
		node *& go_prev();
		node *& go_next();
	private:
		activity * event_ptr;
		node * prev;
		node * next;
};




class arr_of_dll
{
	public:
		arr_of_dll(int size = 5);
		~arr_of_dll();

		int converting_index(int num_priority);
		void insert_an_activity(int num_priority, activity * main_ptr, char* input);
		int remove_an_activity(int num_priority, char * the_name);
		int find_an_activity(int num_priority, char * the_name, node *& found);
		int remove_all();
		void display_all();
	private:
		node ** table_ptr;
		int ht_size;
		int priority;

		int find_an_activity_recursion(node* , char* , node*& , int& );
		void remove_an_activity(node *&, node *&, node *&);
		void remove_all_recursion(node *& current);
		int display_all_recursion(node * current, int num);

};
