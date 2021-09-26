#include<iostream>
#include<string>
using namespace std;

struct ABC{
	string name;
	unsigned number;
};

struct Queue{
	ABC* data;	//Pointer to dynamically allocated array of ABC's.
	//Other field variables as needed you decide which ones.
	unsigned frontNum;
	unsigned elements;
	unsigned slotCapacity;
};

void initialize(Queue & q);					//X	//Set the data members of q so that q represents a queue with 0 items.
void finalize(Queue & q);					//X	//Deallocate the dynamically allocated array.
unsigned size(const Queue & q);				//X	//Return the # of elements in the (abstract) queue represented by q.
void add(Queue & q, const string & item);	//X?	
string remove(Queue & q);					//X				
void show(const Queue & q);					//X	//Output the elements in the queue, starting at the front of the queue.
bool die(const string & msg);				//X

int main()
{
	Queue queue1;
	initialize(queue1);

	cout << "STEP1: add \"Rod\"" << endl;
	add(queue1, "Rod");
	cout << "STEP2: add \"Bob\"" << endl;
	add(queue1, "Bob");
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << size(queue1) << endl;
	show(queue1);
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP3: add \"David\"" << endl;
	add(queue1, "David");
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << size(queue1) << endl;
	show(queue1);
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP4: add \"Sam\"" << endl;
	add(queue1, "Sam");
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << size(queue1) << endl;
	show(queue1);
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP5: add \"Jeff\"" << endl;
	add(queue1, "Jeff");
	cout << "STEP6: add \"Christian\"" << endl;
	add(queue1, "Christian");
	cout << "STEP7: add \"Ramiro\"" << endl;
	add(queue1, "Ramiro");
	cout << "STEP8: add \"Ben\"" << endl;
	add(queue1, "Ben");
	cout << "STEP9: add \"Max\"" << endl;
	add(queue1, "Max");
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << size(queue1) << endl;
	show(queue1);
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP10: remove " << endl;
	remove(queue1);
	cout << "STEP11: remove " << endl;
	remove(queue1);
	cout << "STEP12: remove " << endl;
	remove(queue1);
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << size(queue1) << endl;
	show(queue1);
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP13: add \"Frank\"" << endl;
	add(queue1, "Frank");
	cout << "STEP14: add \"Roger\"" << endl;
	add(queue1, "Roger");
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << size(queue1) << endl;
	show(queue1);
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP15: add \"Gabriel\"" << endl;
	add(queue1, "Gabriel");
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << size(queue1) << endl;
	show(queue1);
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP16: remove " << endl;
	remove(queue1);
	cout << "STEP17: remove " << endl;
	remove(queue1);
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << size(queue1) << endl;
	show(queue1);
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	finalize(queue1);
	return 0;
}

void initialize(Queue & q)
{
	//When initializing there are 0 elements, but 2 slots available.
	q.frontNum = 0;
	q.elements = 0;
	q.slotCapacity = 2;
	q.data = nullptr;
	try{
		q.data = new ABC[q.slotCapacity];}	//This means creating 2 structs of ABC. |struct1|struct2|.....
	catch (const bad_alloc&){
		die("Allocation Failure");}
}
void finalize(Queue & q)
{
	delete[] q.data;
}
unsigned size(const Queue & q)
{
	return q.elements;
}
void add(Queue & q, const string & item)
{
	unsigned nameNumber = 0;
	if (q.elements == q.slotCapacity)									//If q is full.
	{
		cout << "***DMA EXPANSION***" << endl;
		//q.data --->{{Rod, 1}, {Bob, 2}}
		ABC * temporary = q.data;
		//temporary ---> {{Rod, 1}, {Bob, 2}}

		q.slotCapacity += 2;											//Increment slotCapacity by 2.
		q.data = nullptr;		
		try{
			q.data = new ABC[q.slotCapacity];}							//Allocate a bigger array (2 elements bigger).
		catch (bad_alloc&){
			die("Allocation Failure");}
		//q.data ---> {{0, 0}, {0, 0}, {0, 0}, {0, 0}}

		for (unsigned count = 0; count < q.elements; count++/*, q.data++*/)
		{
			//If you use (count < q.slotCapacity) the array temporary will go out of bounce.
			//Therefore you must use the (q < q.elements).
			q.data[count].name = temporary[count].name;
			q.data[count].number = temporary[count].number;	//IGNORE, NOT NEEDED.
			//q.data[count].number = nameNumber++;			//IGNORE, NOT NEEDED.
		}
		//q.data ---> {{Rod, 1}, {Bob, 2}, {0, 0}, {0, 0}}
		delete [] temporary;												//Deallocate the smaller array.
	}
	
	q.data[(q.elements + q.frontNum) % q.slotCapacity].name = item;		//Add the element to the queue, using wrap-around trick.
	q.elements++;
}
string remove(Queue & q)
{
	if (q.elements == 0)
		die("Stack Underflow.");

	string ret = q.data[q.frontNum].name;

	q.frontNum = (q.frontNum + 1) % q.slotCapacity;
	q.elements--;
	return ret;
}
void show(const Queue & q)
{
	for (unsigned count = 0; count < q.elements; count++)
	{
		cout << "  " << q.data[(q.frontNum + count) % q.slotCapacity].name << endl;
		cout << "Number #" << endl;
		//cout << "  " << q.data[(q.frontNum + count) % q.slotCapacity].number << endl;//IGNORE, NOT NEEDED.
	}
}
bool die(const string & msg)
{
	cout << "Error: " << msg << endl;
	exit(EXIT_FAILURE);
}