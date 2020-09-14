#include <iostream>
#include <future>

using namespace std;

int fnc(int n1, int n2){
    int sum = 0;
    for(int i = n1; i < n2; i++){
        printf("%d\n", i);
        sum += 1;
    }

    return sum;
}

int main(){

    future<int> t1 = async(launch::async, fnc, 0, 10);
    future<int> t2 = async(launch::async, fnc, 100, 200);

    int sum = t1.get() + t2.get();
    cout << sum << endl;
    return 0;
}