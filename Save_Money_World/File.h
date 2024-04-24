#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace std;

class File {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;

	int x, y, time;

public:
	File() {
		readData();
	}
	~File() {}

	void readData() {
		fileRead.open("prueba.txt", ios::in);


		getline(fileRead, text);
		time = stoi(text);


		fileRead.close();
	}

	int getTime() { return time; }



};


