#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int index = 0; // Index to track the position of the next unique element

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[index]) {
            // If the current element is different from the previous unique element,
            // move it to the next position in the array
            nums[++index] = nums[i];
        }
    }

    // The length of the array with unique elements is index + 1
    return index + 1;
}

int main() {
    // Test the function
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 6, 6};
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int newLength = removeDuplicates(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "New length: " << newLength << endl;

    return 0;
}
