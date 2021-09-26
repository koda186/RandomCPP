#include<iostream>
#include<string>
using namespace std;

class Stack{
public:
	Stack();
	~Stack();
	unsigned size() const;
	void push(double item);
	double pop();
	void show() const;
private:
	double *arrayDMA;
	unsigned elements;
	unsigned slotCapacity;
};

bool die(const string & msg);

int main()
{
	/*Stack stack1;
	stack1.show();
	cout << "STEP1: push  2.0 \nSTEP2: push  4.2 \nSTEP3: push  6.4 \n";
	stack1.push(2.0);
	stack1.push(4.2);
	stack1.push(6.4);
	cout << "Size: " << stack1.size() << endl;
	stack1.show();
	cout << "STEP4: push 8.6" << endl;
	stack1.push(8.6);
	cout << "Size: " << stack1.size() << endl;
	stack1.show();
	cout << "STEP5: pop ( " << stack1.pop() << " )" << endl;
	cout << "Size: " << stack1.size() << endl;
	stack1.show();*/

	//Polish Postfix Calculator


	Stack stack1;
	char numberOperator;
	double number;
	double leftNum;
	double rightNum;
	double answer;

	cout << "User must type '!' before each operator." <<endl;
	cout << "User must type '#' before each number." << endl;
	cout << "User must type '.' to end the expression." << endl;
	for (;;)
	{
		cin >> numberOperator;
		if (numberOperator == '#')
		{
			cin >> number;
			stack1.push(number);
		}
		else if (numberOperator == '!')
		{
			cin >> numberOperator;
			if (numberOperator == '+')
			{
				rightNum = stack1.pop();
				leftNum = stack1.pop();
				answer = leftNum + rightNum;
				stack1.push(answer);
			}
			else if (numberOperator == '-')
			{
				rightNum = stack1.pop();
				leftNum = stack1.pop();
				answer = leftNum - rightNum;
				stack1.push(answer);
			}
			else if (numberOperator == '*')
			{
				rightNum = stack1.pop();
				leftNum = stack1.pop();
				answer = leftNum * rightNum;
				stack1.push(answer);
			}
			else
				die("Invalid operator.");
		}
		else if (numberOperator == '.')
		{
			cout << "Operation Complete." << endl;
			break;
		}
		else
			die("Invalid character.");
	}
	cout << "Answer: " << stack1.pop() << endl;
}

Stack::Stack()
{
	elements = 0;
	slotCapacity = 2;
	arrayDMA = nullptr;
	try{
		arrayDMA = new double[slotCapacity];}
	catch (bad_alloc&){
		die("Allocation Failure");}
}
Stack::~Stack()
{
	delete[] arrayDMA;
}
unsigned Stack::size() const
{
	return elements;
}
void Stack::push(double item)
{
	if (elements == slotCapacity)
	{
		cout << "*********DMA EXPANSION*********" << endl;
		double *temporary = arrayDMA;
		slotCapacity += 2;
		arrayDMA = nullptr;
		try{
			arrayDMA = new double[slotCapacity];}
		catch (bad_alloc&){
		}

		for (unsigned count = 0; count < elements; count++)
			arrayDMA[count] = temporary[count];

		delete[] temporary;
	}

	arrayDMA[elements] = item;
	elements++;
}
double Stack::pop()
{
	if (elements == 0)
		die("Pop: Stack Underflow");

	return arrayDMA[--elements];
}
void Stack::show() const
{
	for (unsigned count = 0; count < elements; count++)
		cout << "\t" << arrayDMA[count];
	cout << endl;
}

//NON-MEMEBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool die(const string & msg)
{
	cout << "Error: " << msg << endl;
	exit(EXIT_FAILURE);
}