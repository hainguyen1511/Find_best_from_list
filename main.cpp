#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//function prototypes
bool openFile(ifstream& inFile, string fileName);
void feedBack(ifstream& inFile);
void totalpoints(ifstream& inFile);

//main function
// this include the seperation line between function feedback and totalpoints
int main()
{
	ifstream inFile;
	string fileName;
	cout << "Welcome to my Oreo Survey!!!" << endl;
	cout << "\n";
	cout << "This is the summary of Oreo Flavors Taste-Survey\n"; 
	cout << "\n";
	cout << "Each Oreo flavor will be rated on the scale of 0 to 5\n";
	cout << "Total score is 0 min to 25 max\n";
	cout << "\n";
	fileName = "oreo.txt";
	if (!openFile(inFile, fileName))
	{
		cout << "file did not open. Program terminating!!!";
		return 0;
	}
	cout << "*********************************************************" << endl;
	feedBack(inFile);
	cout << "*********************************************************" << endl;
	totalpoints(inFile);
	cout << "*********************************************************" << endl;

}

//function to open file
//returns true if file opens
//returns false if file does not open for any reason
bool openFile(ifstream& inFile, string fileName)
{
	inFile.open(fileName);
	if (!inFile)
	{
		return false;
	}
	return true;
}

//function to calculate and read file
//returns the most and the least result
void feedBack(ifstream& inFile)
{
	string cookCat;
	int ratern, raterc, raterr, raterk, ratera;
	int sum = 0, avg = 0;
	inFile.ignore(52);
	while (!inFile.eof())
	{
		inFile >> cookCat >> ratern >> raterc >> raterr >> raterk >> ratera;
		sum = ratern + raterc;
		sum = sum + raterr + raterk + ratera;
		avg = sum / 5;
		if (avg > 3) {
			cout << "The most tasty flavors are:\n";
			cout << cookCat << "\n";
			cout << endl;
		}
		if (avg < 2) {
			cout << "The least tasty flavors are:\n";
			cout << cookCat << "\n";
			cout << endl;
		}
	}
	inFile.clear();
	inFile.seekg(0);
}

//function list out the total score of each Oreo flavor.
void totalpoints(ifstream& inFile)
{
	string cookCat;
	int ratern, raterc, raterr, raterk, ratera;
	int sum = 0, avg = 0;
	inFile.ignore(52);
	while (!inFile.eof())
	{
		inFile >> cookCat >> ratern >> raterc >> raterr >> raterk >> ratera;
		sum = ratern + raterc;
		sum = sum + raterr + raterk + ratera;
		avg = sum / 5;
		cout << "Total points of the " << cookCat << " flavor is " << sum
			<< " out of 25 with the average score of " << avg << " out of 5"
			<< endl;
		cout << "\n";
	}
	inFile.clear();
	inFile.seekg(0);
}
