#include <string>
#include <iostream>

void report() {
	std::string msg = "\nIn getNextState, at the end if the neighbors variable is exactly three and a cell is DEAD, it becomes ALIVE. \n\
This is what I believe is the 'birth' of a cell in the game. The births are within the World class so we \n\
could create a member variable within World to record how many births take place and just add 1 to the \n\
count every time the conditions for a birth are met. Just the way I understand it tho :)"; // Replace Hello World with your answer.
	std::cout << msg << std::endl;
}

#include <chrono>
#include <thread>

void delay(int ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

///////////////////////////////////////////////////////////////////////////
//  clearScreen implementation
///////////////////////////////////////////////////////////////////////////

void clearScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD upperLeft = { 0, 0 };
	DWORD dwCharsWritten;
	FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
		&dwCharsWritten);
	SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
void clearScreen()  // will just write a newline in an Xcode output window
{
	static const char* term = getenv("TERM");
	if (term == nullptr || strcmp(term, "dumb") == 0)
		cout << endl;
	else
	{
		static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
		cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
	}
}

#endif