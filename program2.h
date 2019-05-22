//Nicki Hurley
//July 21, 2018
//Program 2 CS202
//
//
//This is the header file.
//This program allows one to add various guest activities to a running
//list that contains pertinent details in deciding which activity
//to choose.

#include <iostream>
#include <cstring>
using namespace std;


//base class
class activity
{
	public:
		//constructor
		activity();
		//copy constructor
		activity(const activity & to_copy);
		//virtual destructor
		virtual ~activity();
		//pure virtual add function
		virtual int add() = 0;
		//pure virtual display
		virtual void display() = 0;
		//complete an activty
		int complete();
		//rate an activity
		int rate();
		//return name of activity
		char* get_name();
	protected:
		//activity name
		char * name;
		//completed or not
		bool completed;
		//1-10 rating
		int rating;
		
};

//derived class
class active: public activity
{
	public:
		//constructor
		active();
		//copy constructor
		active(const active & to_copy);
		//destructor
		~active();
		//dynamic add
		int add();
		//dynamic display
		void display();
	private:
		//required fitness level for activity
		int fitness;
		//minimum age for activity
		int min_age;
		//equipment needed for activity
		char * equipment;
};

//derived class, cultural activity
class cultural: public activity
{
	public:
		//constructor
		cultural();
		//copy constructor
		cultural(const cultural & to_copy);
		//destructor
		~cultural();
		//dynamic add
		int add();
		//dynamic display
		void display();
	private:
		//hours the location is open
		char * hours;
		//recommended transportion
		char * transport;
		//description of the activity
		char * description;
};

//derived class, over 21 activity
class over_21: public activity
{
	public:
		//constructor
		over_21();
		//copy constructor
		over_21(const over_21 & to_copy);
		//destructor
		~over_21();
		//dynamic add
		int add();
		//dynamic display
		void display();
	private:
		//type of over 21 activity
		char * type;
		//is food available or not
		bool food;
		//reccommended transportion
		char * transport;
};

//represents a node in the CLL
class node
{
	public:		
		//constructor
		node();
		//displays node data
		void display();
		//sets next
		void set_next(node *& next);
		//goes to next node
		node *& go_next();
		//cout data		
		char * see_data();
		//add new data
		void set_data(activity * new_data);

	protected:
		//pointer to activity
		activity * data;
		//pointer to next node
		node * next;
};


//Circular linked list class
class CLL
{
	public:
		//constructor
		CLL();
		//copy constructor
		CLL(const CLL & to_copy);
		//destructor
		~CLL();
		//add a new node
		int add();
		//remove a node
		int remove();
		//display a node
		void display();
		
	
	private:
		//pointer to rear
		node * rear;
		//copy structure
		int copy_data(CLL *& to, CLL * from);
		//deletes all nodes
		int delete_all(node *& rear);
		//recursive add
		int add(node *& rear, activity * to_add);
		//recursive remove
		int remove(node *& rear, char * to_remove);
		//recursive display
		void display(node * rear);
};

