#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct Convict
{ //defining a structure type
	string name;
	unsigned id;
	bool deathRow;
};

//We shall pass structs to functions by reference
//void display(Convict prisoner);			//<----- Passing the struct by variable
void display(const Convict & prisoner);		//<--- Passing the struct by reference

void display(Convict prisoner[], unsigned els);

unsigned pardon(Convict prisoner[], unsigned els);


void input(Convict & prisoner);


bool die(const string & msg);
int main()
{
	Convict x; //defining a struct variable
	//x.name is ""
	// id is random garbage
	//deathRow is random garbage

	Convict y = {"Richard Kimble", 1234, true};
	//int a[] = { 1, 2, 3, 4, 5 };	<--- this is how we would use an array

	// int a[5], b[5]; a = b    <-- is bogus

	x = y;		//x.name = y.name; x.id = y.id; x.deathRow = y.deathRow

	//one array element immediately follows the previous element in memory? yes, thats a c++ rule
	//one struct field immediately follows the previous struct field? no, that's not a c++ rule
	//If our implementation has sizeof(string) == 24, sizeof(unsigned) == 4, sizeof (bool) == 1
	//sizeof (string[5]) == 120? yes, c++ guarantees it
	//sizeof (Convict) == 29? no, c++might add padding

	//a[5] = 12, cout << a[5];
	x.deathRow =! y.deathRow;

	//unary postfix has higher precedence than unary prefix;
	//unary prefix has higher precedence than non-unary operators;
	display(x);
	cout << "name # death: ";
	input(y);			//for input the last value to type is either 1 or 0
	display(y);

	Convict block[3] = { {"Sam", 1, true}, {"Nancy", 2, false}, {"Fred", 3, true}};
	display(block, 3);
	cout << "Commuting " << pardon(block, 3) << "death sentences " << display(block, 3);  ////??????
}

bool die(const string & msg)
{
	cout << "Fatal Error " << msg << endl;
	exit(EXIT_FAILURE);
}

void display(const Convict & prisoner)
{
	cout << prisoner.name << "#" << prisoner.id << ": " << (prisoner.deathRow ? "prepare last meal" : " underachiever") << endl;
}

void display(Convict prisoner[], unsigned els)
{
	for (unsigned i = 0; i < els; i++)
	{
		display(prisoner[i]);
	}
}

unsigned pardon(Convict prisoner[], unsigned els)	//to call if death penalty is abolished
{
	unsigned changes = 0;
	for (unsigned i = 0; i < els; i++)
	{
		if (prisoner[i].deathRow == true)
		{
			prisoner[i].deathRow = false;
			changes++;
		}
	}
	return changes;
}



void input(Convict & prisoner)
{
	cin >> prisoner.name >> prisoner.id >> prisoner.deathRow;
}


/*
array and struct are AGGREGATE TYPES

array : Is a set of the same types
struct: Is a set of diferent types

**STRUCTS*
When we work with structs we need to define two things (the type of the struct and the variable of the structure type)
*/
