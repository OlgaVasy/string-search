/* P. 911 Ch.5: String Search */
// This program searches for the specified string in the file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string fileName;	
	string line;	
	string search;				
	int occurrences = 0;
	int lineNumber = 0;
						
	// Ask the user for the name of a file
	cout << "Please enter the name of a file: ";
	cin >> fileName;
	
	// Open the file
	fstream file(fileName, ios::in | ios::binary);
	if (!file)
	{
		cout << "Error in trying to open file.\n";
		return 0;
	}

	// Ask the user for a string to search for
	cout << "Please enter a string to search for in the file \"" << fileName << "\": ";	
	cin >> search;
	cout << endl;	
	
	// Search for the lines that contain the specified string	
	file.seekg(0, ios::beg);

	while (file)
	{		
		getline(file, line);
		lineNumber++;		
		
		if (line.find(search, 0) < line.length())
		{
			cout << lineNumber  << ": " << line << endl;					
		}
		
		// Count the number of occurrences
		size_t found = line.find(search,0);
		while (found != string::npos)
		{
			occurrences++;
			found = line.find(search, found + 1);
		}	
	}
	
	
	// Report the total number of occurrences in the file
	cout << "     "  << occurrences << " occurrences total" << endl;	

	file.close();

	system("PAUSE");
	return 0;
}