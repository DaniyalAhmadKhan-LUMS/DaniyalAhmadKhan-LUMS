#ifndef CheckoutLine_CPP
#define CheckoutLine_CPP
#include "CheckoutLine.h"

//base constructor, init
int wait_stamp=0;
int time_stamp=0;
CheckoutLine::CheckoutLine(int size)
{
	line_size=size;

}

//destructor
CheckoutLine::~CheckoutLine()
{
    line_size=0;

}
void compare_wait()
{
    CheckoutLine TestContainer1(10);
    CheckoutLine TestContainer2(10);
    string Testname1 = "tsetasd";
    string testname2 = "ugjkbkj";
    for(int i=0; i<10; i++)
    {
        string s1 = string(1,Testname1[i]);
        string s2 = string(1,testname2[i]);

        TestContainer1.joinCheckoutLine(s1,1,1);
        TestContainer2.joinCheckoutLine(s2,2,1);

    }
    for(int i=0; i<10; i++)
    {
         string s1 = string(1,Testname1[i]);
        string s2 = string(1,testname2[i]);

        TestContainer2.joinCheckoutLine(s1,1,1);
        TestContainer2.joinCheckoutLine(s2,2,1);

    }
    TestContainer1.serveCheckoutLine(1);
    TestContainer2.serveCheckoutLine(2);
    vector<string> record1 = TestContainer1.history(20);
    vector<string> record2 = TestContainer2.history(20);
    int difference;
    int sum = 0;


    for (int i = 0; i < 20; i++)
    {
      string name = record1[i];
      for (int j = 0; j < 20; j++)
      {
        if(name==record2[j])
        {
          difference = j-i;
          sum = sum + difference;
        }

      }

    }


}
// the function above returns the 0 which means that there is no difference in the waits of the two systems which means both systems serve the customers at the same time

// join the checkout line
// impliment for both waiting systems
bool CheckoutLine::joinCheckoutLine(string name, int line_number, int type)
    {
        if(type==1)
            {
                if(line_number==1)
                    {
                        if(container1.length()<line_size)
                            {
                                person_node P(name,wait_stamp,0);
                                wait_stamp++;
                                container1.enqueue(P);
                                return 1;
                            }
                        else
                            {
                                return 0;
                            }
                    }

                else if(line_number==2)
                    {
                        if(container2.length()<line_size)
                            {
                                person_node P(name,wait_stamp,0);
                                wait_stamp++;
                                container2.enqueue(P);
                                return 1;

                            }
                        else
                        {
                            return 0;
                        }
                    }
            }
        else if(type=2)
            {
                if(line_number==1)
                    {
                        if(container1.length()<line_size)
                            {
                                person_node P(name,wait_stamp,0);
                                wait_stamp++;
                                container1.enqueue(P);
                                return 1;
                            }
                        else
                            {
                                return 0;
                            }
                    }

                else if(line_number==2)
                    {
                        if(container2.length()<line_size)
                            {
                                person_node P(name,wait_stamp,0);
                                wait_stamp++;
                                container2.enqueue(P);
                                return 1;

                            }
                        else
                            {
                                return 0;
                            }
                    }
            }


    }

// impliment serving strategy for both waiting systems
void CheckoutLine::serveCheckoutLine(int type)
    {
       if(type==1)
        {
            while( true )
                {
                    if(!container1.isEmpty() && !container2.isEmpty())
                        {

                            if( container1.front().wait_stamp > container2.front().wait_stamp)
                                {
                                    person_node person = container2.dequeue();
                                    person.time_stamp = time_stamp;
                                    time_stamp++;
                                    Customer_record.push(person);
                                }
                            else if(container1.front().wait_stamp < container2.front().wait_stamp)
                                {
                                    person_node person = container1.dequeue();
                                    person.time_stamp = time_stamp;
                                    time_stamp++;
                                    Customer_record.push(person);
                                }

                            }
                    else if(!container1.isEmpty() && container2.isEmpty())
                        {
                            person_node person = container1.dequeue();
                            person.time_stamp = time_stamp;
                            time_stamp++;
                            Customer_record.push(person);
                        }
                    else if(container1.isEmpty() && !container2.isEmpty())
                        {
                            person_node person = container2.dequeue();
                            person.time_stamp = time_stamp;
                            time_stamp++;
                            Customer_record.push(person);
                        }
                    else
                        break;
            }

	}
	else if(type==2)
	{
		bool switch_line = true;
		while(true)
		{
			if(!container1.isEmpty() && !container2.isEmpty())
			{
				if(switch_line==true)
				{
					person_node person = container1.dequeue();
					person.time_stamp = time_stamp;
					time_stamp++;
					Customer_record.push(person);
					switch_line = !switch_line;
				}
				else if(switch_line==false)
				{
					person_node person = container2.dequeue();
					person.time_stamp = time_stamp;
					time_stamp++;
					Customer_record.push(person);
					switch_line = !switch_line;
				}
			}
			else if(!container1.isEmpty() && container2.isEmpty())
                {
                    person_node person = container1.dequeue();
                    person.time_stamp = time_stamp;
                    time_stamp++;
                    Customer_record.push(person);
                }
			else if(container1.isEmpty() && !container2.isEmpty())
                {
                    person_node person = container2.dequeue();
                    person.time_stamp = time_stamp;
                    time_stamp++;
                    Customer_record.push(person);
                }
			else
				break;
		}
	}
    }

// return a vector of strings with the names of last n people served
vector<string> CheckoutLine::history(int n)
{
	Stack<person_node> temp(Customer_record);
	vector<string> cus_record;
	for(int i=0; i<n; i++)
        {
                person_node customer = temp.pop();
                cus_record.push_back(customer.name);
        }
        return cus_record;
}

#endif
