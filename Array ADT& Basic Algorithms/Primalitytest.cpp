#include <iostream>
using namespace std;
#include <string>
bool isPrime(int d) {
    if (d < 2) return false;
    else {
        for (int i = 2;i*i < d;i++) {
            if (d % i == 0) return false;
        }
    }
    return true;
}


int main() {
  
    
    cout << isPrime(37);
    return 0;
}
