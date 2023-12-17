#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    cout << "Type your text: \n";
    string lineRead;
    getline (cin, lineRead);

    string output = ">";
    for (char c : lineRead){
        output += '>';
        for(int i = 0; i < int(c); i++){    //Increment byte up to ASCII corresponding value
            output.append("+");
        }
        output.append(".\t" ); //Output char
        output += c; //Clarify letter being written in output file
        output += '\n';
    }

    ofstream outputFile("output.bf");
    outputFile << output;
    outputFile.close();

}