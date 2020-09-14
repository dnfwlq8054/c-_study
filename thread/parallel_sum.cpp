#include <future>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
int parallel_sum(T start, T end, int n){
    int len = end - start;
    int sum = 0;
    if(len < 1) return 0;

    T newstart = start + n;
    cout << start << " " << newstart << " " << end;
    auto handle = async(parallel_sum<T>, newstart, end, n);
    for_each(start, newstart, [&](int n){
        sum += n;
    });  

    return sum + handle.get();
}

int main(){
    vector<int> v(1001, 1);

    
    int sum = parallel_sum(v.begin(), v.end(), v.size() / 5);

    cout << parallel_sum(v.begin(), v.end(), v.size() / 5) << endl;

    return 0;
}