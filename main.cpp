//Nicki Hurley
//July 21, 2018
//Program 2 CS202
//
//
//This is the implementation file, despite the name of the file.
//This program allows one to add various guest activities to a running
//list that contains pertinent details in deciding which activity 
//to choose.

#include "program2.h"

//default construtor for derived class
active::active(): fitness(0), min_age(0), equipment(0){}


//copy constructor for derived class
active::active(const active & to_copy): activity(to_copy){}


//destructor for derived class
active::~active()
{
	//deallocate space
	delete equipment;
	equipment = NULL;
}


//creates a new active object(virtual base)
int active::add() 
{
	int MAX = 100;
	char temp[MAX];	
	cout << "What is the name of the physically active activity you'd like to add?" << endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	name = new char[strlen(temp + 1)];
	strcpy(name, temp);
	cout << "One a scale of 1-10, what level of fitness is required for this activity?" << endl;
	cin >> fitness;
	cin.ignore(100, '\n');
	cout << "What is the minimum age someone should be to participate in this sport?" << endl;
	cin >> min_age;
	cin.ignore(100, '\n');	 
	cout << "What kind of equipment is required?" << endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	equipment = new char[strlen(temp + 1)];
	strcpy(equipment, temp);
	return 1;

}


//displays active data (virtual base)
void active::display()
{
	cout << "Activity: " << name << endl;
	cout << "Completed?: ";
	if(!completed)
		cout << "No" << endl;
	else	
		cout << "Yes" << endl;
	cout << "Rating: " << rating << endl;
	cout << "Required fitness level: " << fitness << endl;
	cout << "Minimum age: " << min_age << endl;
	cout << "Required equipment: " << equipment << endl;

}


//constructor for derived class
cultural::cultural(): hours(0), transport(0), description(0){}


//copy constructor for derived class
cultural::cultural(const cultural & to_copy): activity(to_copy){}


//destructor for dervied class
cultural::~cultural()
{
	//deallocates memory
	delete hours;
	hours = NULL;
	delete transport;
	transport = NULL;
	delete description;
	description = NULL;
}


//creates a new cultural object (virtual base)
int cultural::add()
{
	int MAX = 100;
	char temp[MAX];	
	cout << "What is the name of the cultural activity you'd like to add?" << endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	name = new char[strlen(temp + 1)];
	strcpy(name, temp);

	cout << "What hours is the location open?" << endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	hours = new char[strlen(temp + 1)];
	strcpy(hours, temp);

	cout << "What kind of transportion to the location is recommended?" << endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	transport = new char[strlen(temp + 1)];
	strcpy(transport, temp);

	cout << "Please provide a description of the activity:" << endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	description = new char[strlen(temp + 1)];
	strcpy(description, temp);

	return 1;
}


//displays data (virtual base)
void cultural::display()
{
	cout << "Activity: " << name << endl;
	cout << "Completed?: ";
	if(!completed)
		cout << "No" << endl;
	else	
		cout << "Yes" << endl;
	cout << "Rating: " << rating << endl;
	cout << "Hours open: " << hours << endl;
	cout << "Recommended transport: " << transport << endl;
	cout << "Description: " << description << endl;	

}


//default constructor for derived class
over_21::over_21(): type(0), food(0), transport(0){}


//copy constructor for derived class
over_21::over_21(const over_21 & to_copy): activity(to_copy){}


//destructor for derived class
over_21::~over_21()
{
	//deallocate memory
	delete type;
	type = NULL;
	delete transport;
	transport = NULL;
}


//creates a new over 21 object (virtual base)
int over_21::add()
{
	int MAX = 100;
	char temp[MAX];	
	cout << "What is the name of the over 21 activity you'd like to add?" << endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	name = new char[strlen(temp + 1)];
	strcpy(name, temp);
	
	cout << "Will this activity involve beer, wine or a full bar?" << endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	type = new char[strlen(temp + 1)];
	strcpy(type, temp);

	cout << "Will there be food available? (1) yes (0) no" << endl;
	cin >> food;
	cin.ignore(100, '\n');

	cout << "What's the recommended mode of transportation?" << endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	transport = new char[strlen(temp + 1)];
	strcpy(transport, temp);

	return 1;
}


//displays data (virtual base)
void over_21::display()
{
	cout << "Activity: " << name << endl;
	cout << "Completed?: ";
	if(!completed)
		cout << "No" << endl;
	else	
		cout << "Yes" << endl;
	cout << "Rating: " << rating << endl;
	cout << "Type: " << type << endl;
	cout << "Food available?";
	if(!food)
		cout << "No" << endl;
	else	
		cout << "Yes" << endl;
	cout << "Recommended transport: " << transport << endl;

}


//default constructor for base class
activity::activity(): completed(0), rating(0) {}


//copy constructor for base class
activity::activity(const activity & to_copy) {}


//destructor for base class
activity::~activity()
{
	delete name;
	name = NULL;
}


//sets an activity completed
int activity::complete() 
{
	completed = 1;
	return completed;
}


//set a rating for an activity
int activity::rate() 
{
	cout << "What would you like to rate from 1-10 this activity?" << endl;
	cin >> rating;
	return rating;
}


//getter for the name
char* activity::get_name()
{
	return name;
}


//constructor for node class
node::node(): next(NULL){}


//displays the object data in the node
void node::display()
{
	cout << endl;
	//dynamically calls the appropriate display object function(active, cultural, over 21)
	return data->display();
}


//sets next
void node::set_next(node *& connect) 
{
	next = connect;
}


//moves to the next node
node *& node::go_next()
{
	return next;
}


//returns the name of the activity, for comparisions
char* node::see_data()
{
	return data->get_name();
}


//sets the new data at a node
void node::set_data(activity * new_data)
{
	data = new_data;
}



//constructor for CLL
CLL::CLL(): rear(NULL) {}


//copy constructor for CLL
CLL::CLL(const CLL & to_copy) {}


//copies the CLL into a new CLL
int CLL::copy_data(CLL *& to, CLL * from) 
{
	return 1;
}


//destructor for the CLL
CLL::~CLL() 
{
	if(rear)
	{
		delete rear;
		rear = NULL;
	}	
}


//deletes all the nodes in the CLL
int CLL::delete_all(node *& rear) 
{
	return 1;
}


//adds a new node to the CLL
int CLL::add() 
{
	int choice;
	cout << "What activity would you like to add:" << endl
	<< "(1) Active" << endl
	<< "(2) Cultural" << endl
	<< "(3) Over 21" << endl;
	
	cin >> choice;
	cin.ignore(100,'\n');
	//based on which option the client chooses, the appropriate add function will be dynamically invoked
	if(choice == 1)
	{
		//upcasting
		activity * to_add = new active;
		to_add->add();
		return add(rear, to_add);	

	}
	else if(choice == 2)
	{
		//upcasting
		activity * to_add = new cultural;
		to_add->add();
		return add(rear, to_add);	
	}
	else if(choice == 3)
	{
		//upcasting
		activity * to_add = new over_21;
		to_add->add();
		return add(rear, to_add);	
	}
	return 1;
}


//adds a new node
int CLL::add(node *& rear, activity * to_add)
{
	if(!rear)
	{
		rear = new node;
		rear->set_data(to_add);
		rear->go_next() = rear;
	}
	else
	{
		node * temp = new node;
		temp->set_data(to_add);
		temp->go_next() = rear->go_next();
		rear->go_next() = temp;
		return 1;
	}
	return 1;
}


//removes a node if input matches the activity name
int CLL::remove()
{
	int MAX = 100;
	char temp[MAX];
	char * to_remove;

	if(!rear)
		return 0;
	cout << "What is the name of the activity you'd like to remove?" << endl;
	cin.get(temp, 100, '\n');
	to_remove = new char[strlen(temp +1)];
	strcpy(to_remove, temp);
	

	//checks if data to remove is at only node
	if(rear == rear->go_next())
	{
		if(strcmp(to_remove, rear->see_data()))
		{
			delete rear;
			rear = NULL;
			return 1;
		}
	}
	//calls recursive function
	return remove(rear->go_next(), to_remove);
}


//recursive remove
int CLL::remove(node *& head, char * to_remove)
{
	//if at last node
	if(head == rear)
	{
		//checks if input matches data
		if(strcmp(to_remove, head->go_next()->see_data()))
		{
			//remove
			node * temp = head->go_next()->go_next();
			delete head->go_next();
			head->go_next() = temp;
			return 1;
	
		}
		return 0;
	}
	//checks if input matches data
	if(strcmp(head->go_next()->see_data(), to_remove))
	{
		//remove
		node * temp = head->go_next()->go_next();
		//if we're at rear, reset it
		if(head->go_next() == rear)
		{
			rear = temp;
		}
		delete head->go_next();
		head->go_next() = temp;
		return 1;
	}
	return remove(head->go_next(), to_remove);
	
}


//cycles through CLL for display
void CLL::display() 
{
	if(!rear)
		return;
	display(rear->go_next());
}


//recursive display function
void CLL::display(node * head) 
{
	if(head == this->rear)
	{
		head->display();
		return;
	}
	head->display();
	display(head->go_next());
}


