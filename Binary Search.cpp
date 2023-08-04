#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Binary Search Function
// Parameters:
// - arr: The sorted array in which we want to perform the search.
// - target: The element we are looking for in the array.
// Returns:
// - The index of the target element in the array, if found.
// - Otherwise, it returns -1 to indicate that the element is not present.
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;              // Leftmost index of the search space
    int right = arr.size() - 1;// Rightmost index of the search space

    // Continue the loop as long as there is a valid search space (left <= right)
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        // If the middle element is the target, return its index
        if (arr[mid] == target) {
            return mid;
        }
        // If the target is greater than the middle element,
        // narrow the search space to the right half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If the target is smaller than the middle element,
        // narrow the search space to the left half
        else {
            right = mid - 1;
        }
    }

    // Element not found, return -1
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int target = 11;

    // Call the binary search function and store the result
    int result = binarySearch(arr, target);

    // Check if the result is not -1 (element found)
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    // Perform upper_bound and lower_bound operations
    auto upper = upper_bound(arr.begin(), arr.end(), target);
    auto lower = lower_bound(arr.begin(), arr.end(), target);

    // Calculate the indices from the iterators
    int upper_index = upper - arr.begin();
    int lower_index = lower - arr.begin();

    // Print the results
    cout << "Upper Bound Index: " << upper_index << endl;
    cout << "Lower Bound Index: " << lower_index << endl;

    return 0;
}
