#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int>& numbers) {
    int xorAll = 0, xorArray = 0;
    int size = numbers.size();

    for (int i = 0; i < size; i++) {
        xorAll ^= (i + 1);
        xorArray ^= numbers[i];
    }
    xorAll ^= (size + 1);

    return xorAll ^ xorArray;
}

int main() {
    vector<int> numbers = {1, 2, 4, 5};

    cout << "Missing number: " << findMissingNumber(numbers) << endl;

    return 0;
}
