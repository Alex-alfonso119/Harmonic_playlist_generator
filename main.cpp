#include "functions.h"

int main(int argc, char* argv[])
{
	cout << "Hello Hackathon!\n";

	ifstream inputfile;
	vector<string> input_container, parse_container;
	vector<Track> track_container;

	//	the first two fields are overhead information, not track information
	//	counts the total number of tracks read in
	int count = -2;

	inputfile.open("test2.csv");

	if(!inputfile.is_open())
	{
		cout << "Error: Failed to open file\n";
		exit(EXIT_FAILURE);	
	}

	//	process file, string parse
	string line;
	string word;

	while(getline(inputfile, line))
	{
		Track newtrack;

		++count;
		//cout << count << endl;
		input_container = stringParser(line, ",");

		for(int i = 0; i<input_container.size(); i++)
		{
			word = parseParentheses(input_container[i]);
			//cout << "i: " << i << "\t" << word << endl;

			if(count >= 1)
			{
				switch(i)
				{
					case 0:
						newtrack.name = word;
						break;

					case 1:
						newtrack.artist = word;
						break;

					case 2:
						newtrack.bpm = atoi(word.c_str());
						break;

					case 3:
						newtrack.key = word;
						break;

					case 4:
						newtrack.startTime = word;
						break;

					case 5:
						newtrack.endTime = word;
						break;

					case 6:
						newtrack.id = count;
						newtrack.playtime = word;
						track_container.push_back(newtrack);
						break;
				}
			}
		}

		//cout << endl;
	}

	for(int i = 0; i<track_container.size(); i++)
	{
		track_container[i].keyVal = setKeyVal(track_container[i].key);
		//cout << track_container[i].id << ": " << track_container[i].key << "\t" << track_container[i].keyVal << endl;
	}

	//cout << "SIZE: " << track_container.size() << endl;

	cout << "---- Tracks read in from input ---- " << endl;
	displayTracks(track_container);

	/*
		as of now, all tracks have been read in from the file and are stored in a vector container
		step 2: select song
	*/
	vector<Track> mix_container;
	vector<Track> playlist_container;

	int startIndex = -1;
	//int currentIndex = -1;

	cout << "\nSelect starting song (by track ID #): ";
	cin >> startIndex;
	startIndex -= 1;

	do
	{
		system("clear");
		mix_container.clear();

		cout << "Current Playlist: \n";
		playlist_container.push_back(track_container[startIndex]);
		//track_container.erase(track_container.begin() + startIndex);
		displayPlaylist(playlist_container);

		cout << "\nHarmonically Mixable Tracks: \n";
		for(int i = 0; i<track_container.size(); i++)
		{
			if(track_container[startIndex].id != track_container[i].id)
			{
				if(track_container[startIndex].keyVal == track_container[i].keyVal)
				{
					printTrack(track_container, i);
					mix_container.push_back(track_container[i]);
				}
				else if (track_container[startIndex].keyVal == track_container[i].keyVal-1)
				{
					printTrack(track_container, i);
					mix_container.push_back(track_container[i]);
				}
				else if (track_container[startIndex].keyVal == track_container[i].keyVal+1)
				{
					printTrack(track_container, i);
					mix_container.push_back(track_container[i]);
				}
			}
		}

		/*
			this does not validate input, so user input must be accurate
		*/
		cout << "\nChoose next song (by track ID #), or submit 0 to exit: ";
		cin >> startIndex;
		startIndex -= 1;

	} while (startIndex > -1);

	/*
		ISSUES:
			- I'd like an export option, such that it exports the current playlist as a 
			.csv file as the input is

			- I'm not sure whether to erase the songs added to the playlist from the
			original track container, or whether i should search whether duplicates
			exist inside the playlist_container vs track_container, but that seems like 
			it would become a longer search the bigger the playlist is..

			- Perhaps sorting the mix_container by lower harmonic -> higher harmonic keyVal

			- More Rules!!! BPM difference % would be cool
	*/

	//sort(mix_container.begin(), mix_container.end());
	//displayTracks(mix_container);

	//cout << "SIZE: " << playlist_container.size() << endl;



	inputfile.close();

	return 0;
}

