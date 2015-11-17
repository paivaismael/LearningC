// iostream: contains basic io streaming operations (cin, cout, etc.)
#include <iostream>
// true string type
#include <string>
// convert strings to streams with stringstream
#include <sstream>
// write files easily as streams
#include <fstream>

int main()
{
    using namespace std;

    string firstname_string;
    string lastname_string;
    string input;
    int age_int;

    cout << "Enter with the following information:" << endl;
    cout << "First name: ";
    getline(cin,firstname_string);
    cout << "Last name: ";
    getline(cin,lastname_string);
    cout << "Age: ";
    getline(cin,input);
    stringstream(input) >> age_int;
    cout << "The information is saved." << endl;

    // file handle
    ofstream output;
    // open a file
    output.open("output_file.txt");
    output << "First name: " << firstname_string << '\t';
    output << "Last name: " << lastname_string << '\t';
    output << "Age: " << age_int << endl;
    output.close();

    return 0;
}
