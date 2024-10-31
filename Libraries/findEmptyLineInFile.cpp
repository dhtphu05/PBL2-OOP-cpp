#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../Template/DoubleLinkedList.h"

using namespace std;
DoubleLinkedList<string> list;
DoubleLinkedList<string> split( const string &s, char delimiter){
    DoubleLinkedList<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}
int main(){
    ifstream inputFile("test.txt");
    string line;
    string test="Hello world";
    DoubleLinkedList<string> tokens=split(test, ' ');
    for(int i=0;i<tokens.getSize();i++){
        cout<<tokens[i]<<endl;
    }
    int count=0;
    if(inputFile.is_open()){
        
        while(getline(inputFile, line)){
            line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
            line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);

            if (line.empty()){
                cout<<"Dong trong roi ne"<<endl;
            }
            else{
                count++;
                DoubleLinkedList<string> ans=split(line, ' ');
                for(int i=0;i<ans.getSize();i++){
                    cout<<ans[i]<<endl;
                }
                
            }
        }
    } else {
        cout << "Khong the mo file" << endl;
    }
    inputFile.close();
    inputFile.open("test.txt");
    getline(inputFile, line);
    cout<<line<<endl;
    
    return 0;
}
