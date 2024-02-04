#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            // If the number is already present in the set, return true
            return true;
        } else {
            // Otherwise, add the number to the set
            seen.insert(num);
        }
    }

    // If no duplicates found, return false
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Array contains duplicates: " << boolalpha << containsDuplicate(nums) << endl;

    nums = {1, 2, 3, 4, 1};
    cout << "Array contains duplicates: " << boolalpha << containsDuplicate(nums) << endl;

    return 0;
}
