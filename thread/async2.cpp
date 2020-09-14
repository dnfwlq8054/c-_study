#include <future>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string s;

void readStream(){
    ifstream readFile("text.txt");

    if(readFile.is_open()){
        char c;
        c = readFile.get();
        while(readFile.good()){
            if(c == '.'){
                s += c;
                s += "\r";
            }   
            else
                s += c;
            
            c = readFile.get();
        }

    }
    readFile.close();
    
}

void writeStream(){
    ofstream writeFile("_text.txt");
    
    if(writeFile.is_open()){
        writeFile << s;
    }

    writeFile.close();
}

int main(){

    future<void> t1 = async(launch::deferred, readStream);
    future<void> t2 = async(launch::deferred, writeStream);

    t1.wait();
    t2.wait();
    return 0;
}