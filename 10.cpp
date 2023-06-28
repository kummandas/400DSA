Take two pointers (basically integers) namely, slow and fast. Initially both will point to first element
Increase slow by 1 and fast by two.
Step 2 will be done as follows: slow = nums[slow]; fast = nums[nums[fast]].
There will be one time when slow and fast will meet. They will meet in a cycle.
At step 4 we have to stop.
Now move fast to initial position i.e. fast = nums[0].
Now move both slow and fast by one position till both of them meet.
Step 7 increment will be done as follows: slow = nums[slow]; fast = nums[fast].
The node at which both slow and fast will meet will be the duplicate number.
Return slow or fast :).


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};







    public static int findDuplicate_bs(int[] nums) {
        int len = nums.length;
        int low = 1;
        int high = len - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] <= mid) {
                    cnt++;
                }
            }

            if (cnt <= mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }