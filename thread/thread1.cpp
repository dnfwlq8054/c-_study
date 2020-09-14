#include <iostream>
#include <thread>
#include <functional>

using namespace std;

void fnc(int n1, int n2){
    for(int i = n1; i <= n2; i++){
        printf("%d\n", i);
    }
}

int main(){

    thread t1(fnc, 0, 1000);
    thread t2(fnc, 200, 3000);
    thread t3(fnc, 50, 1200);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}