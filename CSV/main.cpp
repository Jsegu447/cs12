#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int sumNums = 0;
    int numAvg = 0;
   string inputFile;
   string outputFile;
   int numFromFiles;
   vector <int> fileNums;
   
   // Assign to inputFile value of 2nd command line argument
    inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
    outputFile = argv[2];
   // Create input stream and open input csv file.
    ifstream inFS;
    inFS.open(inputFile);
   // Verify file opened correctly.
    if (!inFS.is_open()){
   // Output error message and return 1 if file stream did not open correctly.
        cout << "Error opening " << inputFile << endl;
        return 1;
    }
   // Read in integers from input file to vector.
    while (inFS >> numFromFiles){
        inFS.ignore();
        fileNums.push_back(numFromFiles);
        
    }
   // Close input stream.
    inFS.close();
    
   // Get integer average of all values read in.
    for ( unsigned int i = 0; i < fileNums.size(); i++){
        sumNums += fileNums.at(i);
        numAvg = sumNums/fileNums.size();
       
    }
   // Convert each value within vector to be the difference between the original value and the average.
    for ( unsigned int i = 0; i < fileNums.size(); i++){
        fileNums.at(i) -= numAvg;
    }
   // Create output stream and open/create output csv file.
   ofstream outFS;
    outFS.open(outputFile);
   // Verify file opened or was created correctly.
    if(!outFS.is_open()){
           cout << "Error opening " << outputFile << endl;
        return 1;
       }
   // Output error message and return 1 if file stream did not open correctly.
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for ( unsigned int i = 0; i < fileNums.size() - 1; i++){
       outFS << fileNums.at(i) << ",";
    }
    outFS << fileNums.at(fileNums.size()-1);
    // Close output stream.
    outFS.close();
    
   return 0;
}
