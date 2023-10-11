#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to count the number of set bits in a number.
int countSetBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

void findIndexRanges(const vector<int>& arr, int X) {
    unordered_map<int, vector<int>> indexMap; // Map to store indices for each set bit sum.

    for (int i = 0; i < arr.size(); ++i) {
        int bitCount = countSetBits(arr[i]);
        indexMap[bitCount].push_back(i + 1); // Adding 1 to convert from 0-based indexing to 1-based indexing.
    }

    for (const auto& entry : indexMap) {
        int bitCount = entry.first;
        if (indexMap.find(X - bitCount) != indexMap.end()) {
            for (int index1 : entry.second) {
                for (int index2 : indexMap[X - bitCount]) {
                    cout << "Range with set bit sum " << X << ": (" << index1 << ", " << index2 << ")\n";
                }
            }
        }
    }
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10};
    int X = 2;
    findIndexRanges(arr, X);
    return 0;
}
