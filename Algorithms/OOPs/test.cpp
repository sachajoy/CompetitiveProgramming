#include<bits/stdc++.h>
using namespace std;

class Test {
    int x;
    
    public:
    Test(int x){
        this->x = x;
        cout << "Hello Test" << endl;
    }
};

int main(){
    Test t1(2);
}