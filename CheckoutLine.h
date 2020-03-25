#ifndef CheckoutLine_H
#define CheckoutLine_H
#include <fstream>
#include <vector>
#include <string>
#include "stack.cpp"
#include "queue.cpp"

using namespace std;

// A person_node contains their name, how long they have been waiting (wait_time) as well as when they were served (time_stamp).
struct person_node{
	string name;
	int wait_stamp;
	int time_stamp;
	person_node(){
		name = "";
		wait_stamp=0;
		time_stamp=0;
	}
	person_node (string n, int w, int t){
		name = n;
		wait_stamp = w;
		time_stamp = t;
	}
};

// The checkout line system will have a container to store the different checkout lines and to store history, you have to make choice between stack or queue.
// Also argue in favour of your choice of container.
class CheckoutLine{
public:
	// Containers
	// Make three containers: two for the checkout lines and one to store serving history
	// decide between:
	// 	  -- Stack<person_node> container;
	Queue<person_node> container1;
	Queue<person_node> container2;
	//The lines at pdc ressemble qeues where people add at the last and are served at the front, and the person that add the line first, leaves first.
    Stack<person_node> Customer_record;

	int time;
	int line_size;
	// Base constructor
	CheckoutLine(int size);
	//Destructor
	~CheckoutLine();
	//Functionalities
	bool joinCheckoutLine(string name, int line_number, int type);
	void serveCheckoutLine(int type);
	vector<string> history(int n);
	//because the assignment requires that history shoud be recorded in such a way that the person that got served last comes out first in the hirstory
};

#endif
