#pragma once
#include<iostream>
#include<fstream>

void FileHandlingEntryPoint();

void ReadFile();
void ReadPayroll();

void WriteToAFile();
long GetSizeOfFile(std::ifstream&);

void ReadFileInReverse();

void WriteBinary();
