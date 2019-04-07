#include "functions.h"

/*
		this function parses a string and removes the '"' from it
*/
vector<string> stringParser(string sentence, string delimiter)
{
	size_t position = 0;
	string token;
	vector<string> v;

	while((position = sentence.find(delimiter)) != string::npos)
	{
		token = sentence.substr(0, position);
		v.push_back(token);

		//cout << token << std::endl;
		
		sentence.erase(0, position + delimiter.length());
	}
	v.push_back(sentence);		//	stores last word
	
	//cout << sentence << std::endl;		//	prints last word

	return v;
}

/*
	removes the first and last characters of a word (these will be parentheses)
*/
string parseParentheses(string word)
{
	string parsed;

	if(word.size() > 2)
	{
		parsed = word.substr(1, word.size()-2);
		return parsed;
	}
}

/*
	only prints strings
*/
void printVector(vector<string> v)
{
	for(int i = 0; i<v.size(); i++)
	{
		cout << v.at(i) << endl;
	}
}

/*
	sets value of keyVal to the camelot wheel's value
	NOTE: ONLY WORKS WITH MINOR KEYS (right now)
*/
int setKeyVal(string key)
{
	//	switch statements don't work with strings :(
	if(key == "G#m") {return 1;}
	else if (key == "Ebm") {return 2;}
	else if (key == "Bbm") {return 3;}
	else if (key == "Fm") {return 4;}
	else if (key == "Cm") {return 5;}
	else if (key == "Gm") {return 6;}
	else if (key == "Dm") {return 7;}
	else if (key == "Am") {return 8;}
	else if (key == "Em") {return 9;}
	else if (key == "Bm") {return 10;}
	else if (key == "F#m") {return 11;}
	else if (key == "C#m") {return 12;}
	else {return -1;}
}

/*
	this function is sensitive to spacing
	haven't found a more graceful way of doing this

	displays a container of Track type
*/
void displayTracks(vector<Track> container)
{
	cout << "ID";
	cout << "  Name";
	cout << setw(55) << "Artist";
	cout << setw(20) << "BPM";
	cout << setw(8) << "Key";
	cout << "\tValue\tStart Time\tEnd Time\tPlaytime" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------\n";

	/*
		The setw() can be experimented with, scuffed atm
	*/
	for(int i = 0; i<container.size(); i++)
	{
		cout << std::left;
		cout << setw(4) << container[i].id;
		cout << setw(53) << container[i].name;
		cout << setw(20) << container[i].artist << "\t";
		cout << container[i].bpm << "\t";
		cout << container[i].key << "\t";
		cout << container[i].keyVal << "\t";
		cout << container[i].startTime << "\t";
		cout << container[i].endTime << "\t";
		cout << container[i].playtime<< endl;
	}

	return;
}

//	for output purposes
void displayPlaylist(vector<Track> container)
{
	cout << "ID";
	cout << "  Name";
	cout << setw(30) << "\t\t\t\t\t\t Artist";
	cout << setw(8) << "BPM";
	cout << setw(8) << "Key";
	cout << "Value\tStart Time\tEnd Time\tPlaytime" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------\n";

	/*
		The setw() can be experimented with, scuffed atm
	*/
	for(int i = 0; i<container.size(); i++)
	{
		cout << std::left;
		cout << setw(4) << container[i].id;
		cout << setw(53) << container[i].name;
		cout << setw(20) << container[i].artist << "\t";
		cout << container[i].bpm << "\t";
		cout << container[i].key << "\t";
		cout << container[i].keyVal << "\t";
		cout << container[i].startTime << "\t";
		cout << container[i].endTime << "\t";
		cout << container[i].playtime<< endl;
	}

	return;
}

void printTrack(vector<Track> container, int i)
{
	cout << std::left;
	cout << setw(4) << container[i].id;
	cout << setw(53) << container[i].name;
	cout << setw(20) << container[i].artist << "\t";
	cout << container[i].bpm << "\t";
	cout << container[i].key << "\t";
	cout << container[i].keyVal << "\t";
	cout << container[i].startTime << "\t";
	cout << container[i].endTime << "\t";
	cout << container[i].playtime<< endl;
}



