/*Add the reverseStack operation to the class. This operation copies the elements of a stack in reverse order onto another stack.*/
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class Stack{
public:
	static const unsigned MAX_STACK_NUM = 5;
	Stack();
	void push(double x);
	double pop();
	double top() const;
	void show() const;
	unsigned els() const;
	unsigned available() const;
	bool same(Stack otherStack);			//Returns true if two stacks of the same type are the same, otherwise returns false.
	void reverseStack(Stack &otherStack);	//Copies the elements of a stack in reverse order onto another stack.
private:
	double list[MAX_STACK_NUM];
	unsigned elements;
};

bool die(const string & msg);
void msgSame(bool result);

int main()
{
	Stack s1;
	s1.push(1.1);
	s1.push(2.2);
	s1.push(3.3);
	s1.push(4.4);
	s1.push(5.5);
	cout << "Top: " << s1.top() << endl;
	cout << "Elements: " << s1.els() << endl;
	cout << "Available Space: " << s1.available() << endl;
	s1.show();


	Stack s2;
	s2.push(1.1);
	s2.push(2.1);
	s2.push(3.1);
	s2.push(4.1);
	s2.push(5.1);
	cout << "Top: " << s2.top() << endl;
	cout << "Elements: " << s2.els() << endl;
	cout << "Available Space: " << s2.available() << endl;
	s2.show();

	Stack s3;
	s3.push(1.1);
	s3.push(2.2);
	s3.push(3.3);
	s3.push(4.4);
	s3.push(5.5);
	cout << "Top: " << s3.top() << endl;
	cout << "Elements: " << s3.els() << endl;
	cout << "Available Space: " << s3.available() << endl;
	s3.show();

	Stack s4;
	s4.push(87.35);
	cout << "Top: " << s4.top() << endl;
	cout << "Elements: " << s4.els() << endl;
	cout << "Available Space: " << s4.available() << endl;
	s4.show();

	cout << "s1 and s2: ";
	msgSame(s1.same(s2));
	cout << "s1 and s3: ";
	msgSame(s1.same(s3));
	cout << "s1 and s4: ";
	msgSame(s1.same(s4));
	cout << endl << endl;

	s1.reverseStack(s4);
	cout << "Top: " << s4.top() << endl;
	cout << "Elements: " << s4.els() << endl;
	cout << "Available Space: " << s4.available() << endl;
	s4.show();//This now becomes the reversal of s1.


}
Stack::Stack(){ elements = 0; }
void Stack::push(double x)
{
	if (elements == MAX_STACK_NUM)
		die("Push: Stack Overflow.");

	list[elements++] = x;
}
double Stack::pop()
{
	if (elements == 0)
		die("Pop: Stack Underflow.");

	return list[--elements];
}
double Stack::top() const
{
	if (elements == 0)
		die("Top: Stack is empty.");

	return list[elements - 1];
}
void Stack::show() const
{
	for (unsigned count = 0; count < elements; count++)
		cout << "  " << list[count];
	cout << endl << endl;
}
unsigned Stack::els() const{ return elements; }
unsigned Stack::available() const{ return MAX_STACK_NUM - elements; }
bool Stack::same(Stack otherStack)
{
	//If number of elements in one stack is not equal to number of elements in the other stack then they are not equal.
	if (elements != otherStack.elements)
		return false;

	for (unsigned count = 0; count < elements; count++)
	{
		if (list[count] != otherStack.list[count])
			return false;
	}
	return true;
}
void Stack::reverseStack(Stack &otherStack)
{
	otherStack.elements = 0;
	
	for (unsigned count = 1; count <= elements; count++)
	{
		otherStack.list[otherStack.elements++] = list[elements - count];
	}
}

//Helper Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool die(const string & msg)
{
	cout << "Error: " << msg << endl;
	exit(EXIT_FAILURE);
}

void msgSame(bool result)
{
	if (result)
		cout << "The stacks are EQUAL to each other." << endl;
	else
		cout << "The stacks are NOT equal to each other." << endl;
}