#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    std::locale::global(std::locale("EU.UTF-8"));
    wofstream writeFile(L"_text.txt");
    wifstream readFile(L"text.txt");
    
    if (writeFile.is_open() && readFile.is_open()) {
        wchar_t c = readFile.get();
        bool flag = false;
        while (readFile.good()) {
            if (c == L'“') {
                while (readFile.good()) {
                    wcout << c;
                    writeFile << c;
                    wcout << c;
                    c = readFile.get();
                    if (c == L'”') {
                        wcout << c;
                        writeFile << c;
                        break;
                    }
                }
            }
            else if (c == '.') {
                char temp = readFile.get();
                writeFile << c;
                writeFile << '\r';
                if (temp != ' ')
                    writeFile << temp;
            }
            else
                writeFile << c;

            c = readFile.get();
        }
    }
    writeFile.close();
    readFile.close();
    return 0;
}