#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//removes a string from the line
void rem(string &initialString, string whatToRemove) {
	size_t pos = initialString.find(whatToRemove);
	if (pos != string::npos)
		initialString.erase(initialString.begin() + pos, initialString.begin() + pos + whatToRemove.length());
}

//removes 10 characters in a certain position from the line
void remc(string &initialString, string whatToRemove) {
	size_t pos = initialString.find(whatToRemove);
	if (pos != string::npos)
		initialString.erase(initialString.begin() + pos, initialString.begin() + pos + 10);
}

int main()
{
	string line; //creates a string called "line"
	ifstream readfile("original.log"); //opens the log file if it is called "original.log"
	if (readfile.is_open())
	{
		ofstream writefile("conversation.txt"); //creates a .txt file, if the log file successfully opened, into which the new text will be added
		if (writefile.is_open())
		{
			while (getline(readfile, line)) //places the next line from the log file into the "line" string
			{
				if ((line.find("says") != string::npos) || (line.find(" ~s~") != string::npos) || (line.find("~SMS") != string::npos)
					|| (line.find("cellphone") != string::npos) || (line.find("Whisper") != string::npos) || (line.find("shouts") != string::npos)) //if any of these are found it starts working on that line, if not found it skips the line
				{
					//checks if there is a timestamp and removes the appropriate number of characters from the beginning of the line
					if (line.at(1) == '0' && line.at(38) == '#' || line.at(1) == '1' && line.at(38) == '#' || line.at(1) == '2' && line.at(38) == '#') { line.replace(0, 48, ""); }
					else if (line.at(1) == ' ') { line.replace(0, 32, ""); }
					else { line.replace(0, 40, ""); }

					//ugly way of removing unwanted stuff from the line, will call either "rem" or "remc" depending on what needs to be removed
					if (line.find("~s~") != string::npos) { string removeThis = "~s~"; rem(line, removeThis); }
					if (line.find("~g~") != string::npos) { string removeThis = "~g~"; rem(line, removeThis); }
					if (line.find("~r~") != string::npos) { string removeThis = "~r~"; rem(line, removeThis); }
					if (line.find("~w~") != string::npos) { string removeThis = "~w~"; rem(line, removeThis); }
					if (line.find("~y~") != string::npos) { string removeThis = "~y~"; rem(line, removeThis); }
					if (line.find("~h~") != string::npos) { string removeThis = "~h~"; rem(line, removeThis); }
					if (line.find("~h~") != string::npos) { string removeThis = "~h~"; rem(line, removeThis); } //~h~ is done twice since it can appear two times in the same line
					if (line.find("~#") != string::npos) { string removeThis = "~#"; remc(line, removeThis); }

					writefile << line << "\n"; //writes the "clean" line to the new .txt file and then starts from the beginning of the while loop again as long as there are still lines left to read
				}
			}
		}

		//when there are no more lines to read from the log file both files are closed and a message is displayed
		readfile.close();
		writefile.close();

		cout << "Operation completed succesfully, conversation saved to \"conversation.txt\"." << endl << "Made by: GamingNinjaSheep." << endl << "Press Enter to close window...";
	}
	//if log file could not be opened it will give this error message
	else cout << "Unable to open file, make sure filename is \"original.log\" and placed in the same folder as this program." << endl << "Press Enter to close window...";

	cin.get();
	return 0;
}
