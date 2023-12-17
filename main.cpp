#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string adjustValue(int preVal, int actVal);

int main(){
    cout << "Type your text: \n";
    string lineRead;
    getline (cin, lineRead);

    string output = ">";
    int preVal = 0;

    for (char c : lineRead){
        output.append(adjustValue(preVal, int(c)));
        output.append(".\t" ); //Output char
        output += c; //Clarify letter being written in output file
        output += '\n';
        preVal = int(c);
    }

    ofstream outputFile("output.bf");
    outputFile << output;
    outputFile.close();

    return 0;
}

/**
 * @param preVal Value stored in the byte
 * @param actVal Value desired in the byte
 * 
 * @return String which increases or decreases the byte value to the desired.
*/
string adjustValue(int preVal, int actVal){
    string output;
    if(actVal > preVal){
        for(int i = preVal; i < actVal; i++){
            output += '+';
        }
    }else{
        for(int i = preVal; i > actVal; i--){
            output += '-';
        }
    }
    return output;
}