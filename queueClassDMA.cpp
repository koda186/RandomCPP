//(Queue class, with DMA)
#include<iostream>
#include<string>
using namespace std;

struct ABC{
	string name;
	unsigned number;
};

class Queue{
public:
	Queue();								//Constructor initialized class object to represent empty queue.
	~Queue();								//Destructor deallocates memory.
	unsigned size() const;					//Return # items in queue being represented.
	void add(const ABC & abc);				//Add copy of ABC object to queue.
	ABC remove();							//Remove ABC object from queue.
	void show() const;						//Output the elements in the queue, starting at the front of the queue.
private:
	//For your dynamic memory allocation, you will have a data member that is a pointer to an ABC.
	//This data member will point to your DA array.
	ABC *data;
	unsigned frontNumber;
	unsigned elements;
	unsigned slotCapacity;
};

bool die(const string & msg);

int main()
{
	ABC arrayStruct[20] = { { "Ash", 111 }, { "Bob", 222 }, { "David", 333 }, { "Sam", 444 }, { "Jeff", 555 }, { "Christian", 666},
	{ "Ramiro", 777 }, { "Benjamin", 888 }, { "Max", 999 }, { "Frank", 1000 }, { "Roger", 1100 }, {"Gabriel", 1200} };

	Queue queue1;
	cout << "STEP1: add \"Ash\"" << endl;
	queue1.add(arrayStruct[0]);
	cout << "STEP2: add \"Bob\"" << endl;
	queue1.add(arrayStruct[1]);
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << queue1.size() << endl;
	queue1.show();
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP3: add \"David\"" << endl;
	queue1.add(arrayStruct[2]);
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << queue1.size() << endl;
	queue1.show();
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP4: add \"Sam\"" << endl;
	queue1.add(arrayStruct[3]);
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << queue1.size() << endl;
	queue1.show();
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP5: add \"Jeff\"" << endl;
	queue1.add(arrayStruct[4]);
	cout << "STEP6: add \"Christian\"" << endl;
	queue1.add(arrayStruct[5]);
	cout << "STEP7: add \"Ramiro\"" << endl;
	queue1.add(arrayStruct[6]);
	cout << "STEP8: add \"Benjamin\"" << endl;
	queue1.add(arrayStruct[7]);
	cout << "STEP9: add \"Max\"" << endl;
	queue1.add(arrayStruct[8]);
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << queue1.size() << endl;
	queue1.show();
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP10: remove " << endl;
	queue1.remove();
	cout << "STEP11: remove " << endl;
	queue1.remove();
	cout << "STEP12: remove " << endl;
	queue1.remove();
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << queue1.size() << endl;
	queue1.show();
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP13: add \"Frank\"" << endl;
	queue1.add(arrayStruct[9]);
	cout << "STEP14: add \"Roger\"" << endl;
	queue1.add(arrayStruct[10]);
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << queue1.size() << endl;
	queue1.show();
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP15: add \"Gabriel\"" << endl;
	queue1.add(arrayStruct[11]);
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << queue1.size() << endl;
	queue1.show();
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

	cout << "STEP16: remove " << endl;
	queue1.remove();
	cout << "STEP17: remove " << endl;
	queue1.remove();
	cout << "~~~~~~~~~SHOW~~~~~~~~~" << endl;
	cout << "Elements: " << queue1.size() << endl;
	queue1.show();
	cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
}

Queue::Queue()
{
	frontNumber = 0;
	elements = 0;
	slotCapacity = 2;
	data = nullptr;
	try{
		data = new ABC[slotCapacity];}
	catch (bad_alloc&){
		die("Allocation Failure");}
}
Queue::~Queue()
{
	delete[] data;
}
unsigned Queue::size() const
{
	return elements;
}
void Queue::add(const ABC & abc)
{
	if (elements == slotCapacity)
	{
		cout << "***DMA EXPANSION***" << endl;
		//Data ---> {{Ash, 1}, {Bob, 2}}
		ABC *temporary = data;
		//temporary ---> {{Ash, 1}, {Bob, 2}}

		slotCapacity += 2;
		data = nullptr;
		try{
			data = new ABC[slotCapacity];}
		catch (bad_alloc&){
			die("Allocation Failure");}
		//Data ---> {{0, 0}, {0, 0}, {0, 0}, {0, 0}}

		for (unsigned count = 0; count < elements; count++)
		{
			//DO THESE NEED CHANGING??
			//data[(count + frontNumber) % slotCapacity].name = abc.name;??????
			data[count].name = temporary[count].name;
			data[count].number = temporary[count].number;
		}
		//Data ---> {{Ash, 1}, {Bob, 2}, {0, 0}, {0, 0}}
		delete[] temporary;
	}

	data[(elements + frontNumber) % slotCapacity].name = abc.name;
	data[(elements + frontNumber) % slotCapacity].number = abc.number;
	elements++;
}
ABC Queue::remove()
{
	if (elements == 0)
		die("Queue Underflow.");

	ABC ret = data[frontNumber];

	frontNumber = (frontNumber + 1) % slotCapacity;
	elements--;
	return ret;
}
void Queue::show() const
{
	for (unsigned count = 0; count < elements; count++)
	{
		cout << " " << data[(frontNumber + count) % slotCapacity].name << endl;
		cout << " " << data[(frontNumber + count) % slotCapacity].number << endl;
	}
}

//NON-MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool die(const string & msg)
{
	cout << "Error: " << msg << endl;
	exit(EXIT_FAILURE);
}
