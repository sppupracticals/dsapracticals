//Title:  Implement a Sequential Access file to maintain the data.
//Write data to file.
//Read data from file Sequentially.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to write data to a sequential access file
void writeData(const string& filename) {
    ofstream outFile(filename, ios::out | ios::app); // Open file for writing, appending to the end
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    int numEntries;
    cout << "How many entries would you like to add? ";
    cin >> numEntries;

    string name;
    int age;

    for (int i = 0; i < numEntries; ++i) {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;

        outFile << name << " " << age << endl; // Write data to file
    }

    outFile.close(); // Close the file after writing
}

// Function to read data from a sequential access file
void readData(const string& filename) {
    ifstream inFile(filename, ios::in); // Open file for reading
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    string name;
    int age;

    cout << "\nData in the file:" << endl;
    while (inFile >> name >> age) { // Read data sequentially
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    inFile.close(); // Close the file after reading
}

int main() {
    const string filename = "home.txt";

    // Write data to the file
    writeData(filename);

    // Read data from the file
    readData(filename);

    return 0;
}