#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h> 

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::ifstream;
using std::endl;
using std::istringstream;
using std::sort;
using std::setw;

class Track {

	public:

		int id;
		string name;
		string artist;
		int bpm;
		string key;
		int keyVal;
		string startTime;
		string endTime;
		string playtime;

};

vector<string> stringParser(string sentence, string delimiter);

string parseParentheses(string word);

int setKeyVal(string key);

void printVector(vector<string> v);

void displayTracks(vector<Track> container);

void printTrack(vector<Track> container, int i);

void displayPlaylist(vector<Track> container);

#endif

