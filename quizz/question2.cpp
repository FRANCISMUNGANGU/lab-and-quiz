#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k is greater than the length of the array

    // Reverse the entire array
    reverse(nums, 0, n - 1);

    // Reverse the first k elements
    reverse(nums, 0, k - 1);

    // Reverse the remaining n - k elements
    reverse(nums, k, n - 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    // Print the rotated array
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
