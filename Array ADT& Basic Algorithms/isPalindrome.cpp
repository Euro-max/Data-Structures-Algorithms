#include <iostream>
using namespace std;
#include <string>
bool isPalindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}


int main() {
  
    string b = "ABA";
    cout << isPalindrome(b);
}
