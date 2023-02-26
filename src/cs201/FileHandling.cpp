#include "FileHandling.h"


// Note: Executable path is where the program code is and not the out put directory

using namespace std;

void FileHandlingEntryPoint() {
	//WriteBinary();
	//ReadFileInReverse();
	//ReadFile();
	//ReadPayroll();
	//WriteToAFile();
}

long GetSizeOfFile(ifstream& f) {
	long current = f.tellg();
	f.seekg(0L, ios::end);
	long endPosition = f.tellg();
	f.seekg(current, ios::beg);
	return endPosition;
}

void ReadFile() {
	ifstream myFile;
	myFile.open("Payroll.txt");
	if (myFile) {

		char name[20];
		int salary;

		myFile >> name >> salary;
		cout << name << '\t' << salary;

		long fileSize = GetSizeOfFile(myFile);
		long currentPosition = myFile.tellg();

		int bytesToRead = fileSize - currentPosition;
		char all[1000];

		myFile.read(all, bytesToRead);
		all[bytesToRead] = '\0';

		cout << all;

		myFile.close();
	}
	else {
		cout << "couldn't open the file";
	}
}

void ReadPayroll() {
	fstream myFile;
	myFile.open("Payroll.txt", ios::out | ios::in);
	if (!myFile) {
		cout << "couldn't open the file";
		return;
	}

	long currentPosition = myFile.tellg();
	cout << currentPosition << endl;

	myFile.seekg(10L, ios::beg); // if you put it -10L it will never get to zero in the following code
	currentPosition = myFile.tellg();
	cout << currentPosition << endl;

	myFile.seekg(0L, ios::beg);
	currentPosition = myFile.tellg();
	cout << currentPosition << endl;


	while (!myFile.eof()) {

		char line[30];
		char* name;
		float salary = 0.0;

		char* next_token1 = NULL; //strtok_s need a context char**

		myFile.getline(line, 30);
		name = strtok_s(line, " ", &next_token1);
		salary = atof(strtok_s(NULL, " ", &next_token1));
		cout << name << "\t" << salary << endl;
	}
	myFile.clear();

	long writePosition = myFile.tellp();
	cout << writePosition << endl;

	myFile.write("\nHussain 265", 12);

	myFile.close();
}

void WriteToAFile() {
	fstream myFile;
	myFile.open("Payroll2.txt", ios::out | ios::in);
	if (!myFile) {
		cout << "couldn't open the file";
		return;
	}

	long writePosition = myFile.tellp();
	cout << writePosition << endl;


	myFile.write("Hussain 265", 11);


	myFile.close();
}

void ReadFileInReverse() {
	ifstream myFile;
	myFile.open("Payroll.txt");
	if (!myFile) {
		cout << "cannot open the file";
	}

	myFile.seekg(-1L, ios::end);

	int currentPosition = myFile.tellg();

	while (currentPosition != 0) {
		char ch = myFile.get();
		cout << ch;

		if (ch == '\n')
			myFile.seekg(-1L, ios::cur);

		myFile.seekg(-2L, ios::cur);
		currentPosition = myFile.tellg();
	}
	cout << (char)myFile.get();

	myFile.close();
}

void WriteBinary() {
	ofstream file;
	file.open("test.txt");
	if (file) {
		for (int i = 0; i < 2; i++) {
			file.write((char*)&i, sizeof(i));
		}
		file.close();
	}

	ifstream file2;
	file2.open("test.txt");
	if (file2) {
		char four[4];
		file2.read(four, sizeof(int));
		file2.read(four, sizeof(int));
		file2.close();
	}
}