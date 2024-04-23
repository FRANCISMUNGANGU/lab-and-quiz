#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

int main() {
    // Example usage:
    vector<int> nums = {4, 1, 2, 1, 2};
    int single = singleNumber(nums);
    cout << "The single element is: " << single << endl;
    return 0;
}
