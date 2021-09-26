/*
file i/o chapter 3
string streams;
getline(cin, str); //copy chars from input buffer to str until \n is encountered; \n is not put in str, but is discarded from buffer
*/

#include <iostream>
#include <fstream> // ifstream ofstream
#include <sstream> //stream stream
#include <string>
#include <cstdlib>

using namespace std;
const string DEF_IN_NAME = "input.txt";
const string DEF_OUT_NAME = "output.txt";

string reverse(const string & s);

bool die(const string & msg);


int main() {
	string inName, outName;

	cout << "name of input file ( " << DEF_IN_NAME << " ): ";

	getline(cin, inName) || die("input failure");
	//if (!cin) die
	//allows user to enter more than one word, getline reads everything up to but ni up to the \n.
	//it throws away the \n character and doesnt stay in buffer.

	if (inName.empty()) //returns a bool, is string empty?
		inName = DEF_IN_NAME; //now i have input file if user didnt enter..

	//Now open the file ifstream fin(inName);
	//fin works like cin, knows how to work like cin however it works with files
	ifstream fin; //this declares variable fin and tries to open it //older C++: ifstream fin(inName.c_str());
	fin.open(inName); //this is called a constructor (inName)
	//Now try to open it
	if (!fin) die("Cant open input  file " + inName);


	//OUTPUT file
	cout << "name of output file ( " << DEF_OUT_NAME << " ): ";

	getline(cin, outName) || die(" I couldnt read the name of the output file input failure");

	if (outName.empty())
		outName = DEF_OUT_NAME;
	ifstream tin(outName);		//take the file that user opened for input and use it for output. if it succeeds, badnews .
	if (tin) die("input failure, it already exist " + outName); //should fail ,if file already exist die, it will proceed to next line to open outName.
	ofstream fout(outName);
	if (!fout) die("cant open" + outName + " for output");

	//LOOP to reverse string
	for (string line; getline(fin, line); ) {
		fout << reverse(line) << endl; //reverse ("blah") is "halb"
	}

	//INPUT file CONT'
	//string line; //read in a line from the name of the file.
	//getline(fin, line) || die("cant read input file " + inName);//gets a line from input file
	//cout << "First line: " << line << endl;

	//output to file!
	//fout << line << endl; //this will output our input from input file to output file.

	//Now done with the file, close it!
	//c++ string concatentation it knows how to deal with + to concatenate with other string to make it longer
	fout.close();
	if (!fout) die("problem writing to " + outName + " for output");
	fin.close();
	cout << "bye" << endl;

}

bool die(const string & msg) {
	cout << "Fatal Error" << msg << endl;
	exit(EXIT_FAILURE);
}

string reverse(const string & s) {
	string ret;
	for (unsigned i = s.size(); i--;) //
		ret += s[i];
	return ret;
}
//string ret; sets a string to have 0 characters ?
