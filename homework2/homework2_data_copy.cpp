// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"
#include "iostream"
#include "windows.h"
#include "fstream"
#include "winbase.h"
#include "string.h"

using namespace std;


void __cdecl _tmain(int argc, TCHAR *argv[])
{
	clock_t start, end;

	DWORD actualBytesRead;
	DWORD totalBytes = 0;
	long bufferSize;
	bufferSize = _tcstol(argv[1], NULL, 10); //changes string to int

	char   * readBuff = new char[bufferSize]; //creates dynamic char array 
	HANDLE readFile, writeFile; //2 files declared
	readFile = CreateFile(argv[2],//creates file
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	writeFile = CreateFile(argv[3], //creates file
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	BOOL moreToWrite = TRUE;
	start = clock();
	while (moreToWrite != FALSE)
	{
		ReadFile(readFile, readBuff, bufferSize, &actualBytesRead, NULL); //function to read file with parameters
		totalBytes += actualBytesRead; //counts total number of bytes read from each iteration
		moreToWrite = (actualBytesRead > 0); //while we are still reading bytes, the writefile function is calle for that chunk of bytes
		if (moreToWrite == TRUE) { //will only write if the file isnt at the end
			WriteFile(writeFile, readBuff, actualBytesRead, NULL, NULL); //function to write to new file
		}
	}
	end = clock();
	double totalTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	cout << "Copied " << totalBytes << " bytes in " << totalTime << " seconds " <<
		" at the rate of " << static_cast<double>(totalBytes) / totalTime << " bytes per second." << " Buffer size is: " << bufferSize << std::endl;
	
	CloseHandle(readFile); //close files
	CloseHandle(WriteFile); //close files
	delete[] readBuff; //clean up memory
}