#include <iostream>
using namespace std;

void binarySearch(int* arr, int target, int l, int h) {
    if (l > h) {
        cout << "Element not found" << endl;
        return;
    }

    int mid = (l + h) / 2;

    if (arr[mid] == target) {
        cout << "Element found at index: " << mid << endl;
    }
    else if (arr[mid] < target) {
        binarySearch(arr, target, mid + 1, h);  // Search right
    }
    else {
        binarySearch(arr, target, l, mid - 1);  // Search left
    }
}

int main() {
    int arra[7] = { 45, 45, 46, 47, 48, 49, 50 };
    binarySearch(arra, 49, 0, 6);
    return 0;
}
