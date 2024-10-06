class Solution {
public:
    void fix_down(vector<int> &nums, int i, int last)
    {
        int largest = i, leftChild = 2*i + 1, rightChild = 2*i + 2;

        if(leftChild <= last && nums[i] < nums[leftChild]) 
        largest = leftChild;

        if(rightChild <= last && nums[largest] < nums[rightChild])
        largest = rightChild;

        if(largest != i)
        {
            swap(nums[i], nums[largest]);
            fix_down(nums, largest, last);
        }
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        int n = nums.size();

        // Step 1 - Max-Heapify the array
        for(int i = n/2 - 1; i >= 0; i--)
        {
            fix_down(nums, i, n - 1);
        }

        // Step 2 - Apply heapSort by exchanging first and last elements of the heap and fixing the heap. 
        //The last element would be the largest after each iteration and doesn't need to be taken into the next iteration.
        for(int r = n - 1; r > 0; r--)
        {
            swap(nums[0], nums[r]);
            fix_down(nums, 0, r - 1);
        }

        return nums;
    }
};