// C++ Program to illustrate how to find the frequency of
// elements in an array
#include <iostream>
#include <unordered_map>
using namespace std;

// Driver Code
int main()
{
    // Declaring an array of integers
    int arr[] = { 10, 20, 20, 10, 30, 40, 10, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Declaring an unordered_map to store the frequency of
    // elements
    unordered_map<int, int> frequencyMap;

    // Counting the frequency of elements
    for (int i = 0; i < n; i++) {
        frequencyMap[arr[i]]++;
    }

    // Printing the frequency of elements
    cout << "Frequency of elements in the array is: "
         << endl;
    for (auto& i : frequencyMap) {
        cout << i.first << " -> " << i.second << endl;
    }
    int p=0;
    int d=0;
    for (auto& i : frequencyMap) {
        if(i.second>p){p=i.second; 
        d=i.first;
        }
    }
    cout<<p<<endl;
    cout<<d;
    

    return 0;
