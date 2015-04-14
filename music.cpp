/*
*********************************************************
Made by Tyler McQuarrie (COMP150) HUNAR ROOP SINGH KAHLON
*********************************************************
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Prototypes
double options();
double input();
double list();
double sort();
double quit();

//structs
struct cdinfo
{
	string album[40];
	string artist[40];
	string genre[40];
	string publisher[40];
	int year[40];
}cd;


int countentries;

//main function
int main()
{
	options();
	return 0;
};


double options()
{
	//options() variables
	int optionnum;
	int optionsretry;

	//function execution
	cout << "**************************************************" << endl;
	cout << "*** " << "What would you like to do?" << "***" << endl;
	cout << "**************************************************" << endl;
	cout << "1.) " << "Display the current listing" << endl;
	cout << "2.) " << "Enter a new item to the listing" << endl;
	cout << "3.) " << "Quit Program" << endl;
	cout << "Enter the number for the option" << endl;
	cout << "**************************************************" << endl;
	cin >> optionnum;

	if (optionnum == 1)
		list();
	else if (optionnum == 2)
		input();
	else if (optionnum == 3)
		quit();
	else
	{
		cout << "**************************************************" << endl;
		cout << "Oops you entered a invalid number." << endl;
		cout << "Do you want to try again?" << endl;
		cout << "1.) " << "Yes" << endl;
		cout << "2.) " << "No" << endl;
		cout << "**************************************************" << endl;
		cin >> optionsretry;

		if (optionsretry == 1)
			options();
		else
			return 0;
	};
};
double input()
{

    cout << "How many entries are entering?" << endl;
    cin >> countentries;


    ofstream outfile;
    outfile.open("music.dat");
    cout << "**************************************************" << endl;
    cout << "*** " << "Please Enter the Following Information:" << endl;
    cout << "**************************************************" << endl;

    for(int i=0;i<countentries;i++)
    {
      // Added '[i]' on every other line (for output) - Josh
    cout << "Name of album." << endl;
    cin >> cd.album[i];
    outfile << cd.album[i] << endl;
    cout << "Name of the artist." << endl;
    cin >> cd.artist[i];
    outfile << cd.artist[i] << endl;
    cout << "Name of the genre." << endl;
    cin >> cd.genre[i];
    outfile << cd.genre[i] << endl;
    cout << "Name of the publisher." << endl;
    cin >> cd.publisher[i];
    outfile << cd.publisher[i] << endl;
    cout << "Year Publisher" << endl;
    cin >> cd.year[i];
    cin.ignore();
    outfile << cd.year[i] << endl;
    };
    outfile.close();
    options();
};

double list()
{
    string data;

    ifstream infile;
    infile.open("music.dat");
    //j's were i's - Josh
    for(int j=0;j<countentries;j++)
    {
    infile >> data;
    cout << data << endl;
    infile >> data;
    cout << data << endl;
    infile >> data;
    cout << data << endl;
    infile >> data;
    cout << data << endl;
    infile >> data;
    cout << data << endl;
    }
    infile.close();
    options();
};

double sort()
{
	return 0;
};
double quit()
{
	return 0;
};
