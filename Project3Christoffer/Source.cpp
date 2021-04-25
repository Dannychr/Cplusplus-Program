#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


int main() {
	while (true) {
		// Declaring variables
		int userNum;
		string item;
		// User input menu
		cout << "1: Display all purchases for today" << endl;
		cout << "2: Displaying individual item frequency" << endl;
		cout << "3: Display a histogram of purchases" << endl;
		cout << "4: Exit" << endl;
		cout << "Enter your selection as a number 1, 2, 3 or 4." << endl;
		cin >> userNum;

		// Calls a python function to display purchases in a list
		if (userNum == 1) {
			CallProcedure("allpurchases");
		}

		// Gets a user string input, then calls a python function to display purchases for one item
		else if (userNum == 2) {
			cout << "Enter name of item: ";
			cin >> item;
			cout << callIntFunc("ItemFreq", item);
		}

		// Calls a python function to write the items and frequencies to a new file in a list
		else if (userNum == 3) {
			CallProcedure("Histogram");

			// Opens the new file
			std::ifstream file("frequency.dat");
			int freq;
			string ast{};
			string food;
			if (file.is_open()) {
				// Histogram labels
				cout << endl << "Product" << "\t\t" << "Purchases" << endl;
				cout << "--------------------------" << endl;
				// Assigns the strings and integers in the file to variables
				while (file >> food >> freq) {
					// Converts the numbers to asterisks
					for (int i = 0; i < freq; ++i) {
						ast += '*';
					}
					// If/else just for cleaner formatting
					if (food.length() > 7) {
						cout << food << "\t" << ast << endl;
					}
					else {
						cout << food << "\t\t" << ast << endl;
					}
					// Initializes the variable after every loop
					ast = {};
				}
			}

		}
		// Option for user to exit
		else if (userNum == 4) {
			break;
		}

		// Error message for all invalid numbers
		else {
			cout << "--------------------------" << endl;
			cout << "Invalid number. Try again." << endl;
			cout << "--------------------------" << endl;
		}

		// I accidentally hit a letter key in the first menu and it caused the program to loop endlessly
		// so I found this solution on Stack Overflow to prevent that
		if (cin.fail()) {
			cout << "------------------------------" << endl;
			cout << "ERROR - Please enter a number." << endl;
			cout << "------------------------------" << endl;
			cin.clear();
			#undef max
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

}