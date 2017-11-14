#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string line;
	ifstream readfile("original.log");
	if (readfile.is_open())
	{
		ofstream writefile("conversation.txt");
		if (writefile.is_open())
		{
			while (getline(readfile, line))
			{
				if ((line.find("says") != string::npos) || (line.find("~s~") != string::npos))
				{
					writefile << line << "\n";
				}
			}
		}
		
		readfile.close();
		writefile.close();

		cout << "Operation completed succesfully, conversation saved to \"conversation.txt\"." << endl << "Made by: GamingNinjaSheep." << endl << "Press Enter to close window...";
	}
	else cout << "Unable to open file, make sure filename is \"original.log\" and placed in the same folder as this program." << endl << "Press Enter to close window...";

	cin.get();
	return 0;
}
