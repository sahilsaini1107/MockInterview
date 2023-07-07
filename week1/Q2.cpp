https://leetcode.com/problems/find-the-duplicate-number/ 
// Brute Force (2 Loops)
// Since solve the problem without modifying the array nums and uses only constant extra space, we can use Brute Force to solve it.

// It's easy to use 2 loops to do it, but the time complexity is O(n2)O(n^2)O(n 
// 2
//  ), so it wouldn't accepted as timeout.

    // 2 Loops
    public static int findDuplicate_2loops(int[] nums) {
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }

        return len;
    }
// Analysis
// Time Complexity: O(n2)O(n^2)O(n 
// 2
//  )
// Space Complexity: O(1)O(1)O(1)
// Count
// Count the frequency of the num in the array.

// With extra O(n)O(n)O(n) space, without modifying the input.

    public static int findDuplicate(int[] nums) {
        int len = nums.length;
        int[] cnt = new int[len + 1];
        for (int i = 0; i < len; i++) {
            cnt[nums[i]]++;
            if (cnt[nums[i]] > 1) {
                return nums[i];
            }
        }

        return len;
    }
// Analysis
// Time Complexity: O(n)O(n)O(n)
// Space Complexity: O(n)O(n)O(n)
// Hash
// Using a HashSet\texttt{HashSet}HashSet to record the occurrence of each number.

// With extra O(n)O(n)O(n) space, without modifying the input.

    public static int findDuplicate_set(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            if (!set.add(nums[i])) {
                return nums[i];
            }
        }

        return len;
    }
// Analysis
// Time Complexity: O(n)O(n)O(n)
// Space Complexity: O(n)O(n)O(n)
// Marking visited value within the array
// Since all values of the array are between [1…n][1 \dots n][1…n] and the array size is n+1n+1n+1, while scanning the array from left to right, we set the nums[n]\textit{nums}[n]nums[n] to its negative value.

// With extra O(1)O(1)O(1) space, with modifying the input.

    // Visited
    public static int findDuplicate_mark(int[] nums) {
        int len = nums.length;
        for (int num : nums) {
            int idx = Math.abs(num);
            if (nums[idx] < 0) {
                return idx;
            }
            nums[idx] = -nums[idx];
        }

        return len;
    }
// Analysis
// Time Complexity: O(n)O(n)O(n)
// Space Complexity: O(1)O(1)O(1)
// Sort
// Sorting the array first, then use a loop from 111 to nnn.

// With extra O(nlogn)O(nlogn)O(nlogn) space, modifying the input.

    public static int findDuplicate_sort(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }

        return len;
    }
// Analysis
// Time Complexity: O(nlogn)O(nlogn)O(nlogn)
// Space Complexity: O(logn)O(logn)O(logn)
// Index Sort
// If the array is sorted, the value of each array element is its index value index+1index + 1index+1, then we can do this:

// If nums[i]==i+1\textit{nums}[i] == i + 1nums[i]==i+1, it means that the order has been sorted, then skip, i++i++i++;
// If nums[i]==nums[nums[i]−1]\textit{nums}[i] == \textit{nums}[\textit{nums}[i] - 1]nums[i]==nums[nums[i]−1], it means that there is already a value at the correct index, then this value is a duplicated element;
// If none of the above is satisfied, exchange the values of nums[i]\textit{nums}[i]nums[i] and nums[nums[i]−1]\textit{nums}[\textit{nums}[i] - 1]nums[nums[i]−1].
// With extra O(logn)O(logn)O(logn) space, with modifying the input.

    // Index Sort
    // n + 1 numbers in n.
    public static int findDuplicate_index_sort(int[] nums) {
        int len = nums.length;
        for (int i = 0; i < len; ) {
            int n = nums[i];
            if (n == i + 1) {
                i++;
            } else if (n == nums[n - 1]) {
                return n;
            } else {
                nums[i] = nums[n - 1];
                nums[n - 1] = n;
            }
        }

        return 0;
    }
// Analysis
// Time Complexity: O(n)O(n)O(n)
// Space Complexity: O(1)O(1)O(1)
// Binary Search
// Note that the key is to find an integer in the array [1,2,…,n][1, 2, \dots, n][1,2,…,n] instead of finding an integer in the input array.

// We can use the binary search algorithm, each round we guess one number, then scan the input array, narrow the search range, and finally get the answer.

// According to the Pigeonhole Principle, n+1n + 1n+1 integers, placed in an array of length nnn, at least 111 integer will be repeated.

// So guess a number first(the number midmidmid in the valid range [left,right][left, right][left,right]), count the elements of the array which is less than or equal to midmidmid in the array.

// If cntcntcnt is strictly greater than midmidmid. According to the Pigeonhole Principle, repeated elements are in the interval [left,mid][left, mid][left,mid];
// Otherwise, the repeated element is in the interval [mid+1,right][mid + 1, right][mid+1,right].
// With extra O(1)O(1)O(1) space, without modifying the input.

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
// Analysis
// Time Complexity: O(nlogn)O(nlogn)O(nlogn)
// Space Complexity: O(1)O(1)O(1)
// Bit
// This method is convert all the numbers to binary numbers. If we can get each digit of the repeated number in binary, we can rebuild the repeated number.

// Count all the bits of [1,n][1, n][1,n] and array numbers as 111 respectively, and then restore them bit by bit to get this repeated number.

// For example, the iiith digit, note that in the nums\textit{nums}nums array, the sum of all the elements whose ith digit is 111 is xxx as convert the number to binary.

// As the range [1,n][1, n][1,n], we can also count the sum of the number whose iiith digit is 111, we denoted it yyy.

// We can easily get that x>yx > yx>y.

// The following table lists whether each bit in the binary of each number is 111 or 000 and what the xxx and yyy of the corresponding bit are:

// 1	3	4	2	2	x	y
// Bit 0	1	1	0	0	0	2	2
// Bit 1	1	0	1	1	1	3	2
// Bit 2	0	0	1	0	0	1	1
// From the table, we found that only the 111th bit x>yx > yx>y, so after bitwise restoration target=(010)2=(2)10\textit{target}=(010)_2=(2)_{10}target=(010) 
// 2
// ​
//  =(2) 
// 10
// ​
//  , which is the answer.

// The proof of correctness is actually similar to method 111. We can consider the change of the number xxx of the iii-th in different example arrays.

// If target\textit{target}target appears twice in the test case array, the rest of the numbers appear once, and the iiith bit of target\textit{target}target is 111, then the nums\textit{nums}nums array x, is exactly one greater than y. If bit iii of \textit{target} is 000, then both are equal.

// If target\textit{target}target appears three or more times in the array of test cases, then there must be some numbers that are not in the nums\textit{nums}nums array. At this time, it is equivalent to replacing these with target\textit{target}target, we consider the impact on xxx when replacing:

// If the iii-th bit of the number to be replaced is 111, and the iii-th bit of target\textit{target}target is 111: xxx remains unchanged, x>yx > yx>y.

// If the iii-th bit of the number being replaced is 000, and the iii-th bit of target\textit{target}target is 111: x plus one, x>yx > yx>y.

// If the i-th bit of the number to be replaced is 111, and the iii-th bit of target\textit{target}target is 000: xxx minus one, x≤yx \le yx≤y.

// If the iii-th bit of the number to be replaced is 000, and the iii-th bit of target\textit{target}target is 000: x remains unchanged, satisfying x≤yx \le yx≤y.

// Therefore, if the ith bit of target\textit{target}target is 111, then after each replacement, only xxx will be unchanged or increased. If it is 000, only xxx will be unchanged or decreased.

// When x>yx > yx>y, the ith bit of target\textit{target}target is 111, otherwise it is 000. We only need to restore this repeated number bitwise.

// With extra O(nlogn)O(nlogn)O(nlogn) space, without modifying the input.

    public static int findDuplicate_bit(int[] nums) {
        int n = nums.length;
        int ans = 0;
        int bit_max = 31;
        while (((n - 1) >> bit_max) == 0) {
            bit_max -= 1;
        }

        for (int bit = 0; bit <= bit_max; ++bit) {
            int x = 0, y = 0;
            for (int i = 0; i < n; ++i) {
                if ((nums[i] & (1 << bit)) != 0) {
                    x += 1;
                }
                if (i >= 1 && ((i & (1 << bit)) != 0)) {
                    y += 1;
                }
            }
            if (x > y) {
                ans |= 1 << bit;
            }
        }

        return ans;
    }
// Analysis
// Time Complexity: O(nlogn)O(nlogn)O(nlogn)
// Space Complexity: O(1)O(1)O(1)
// Fast Slow Pointers
// This problem is as same as 142. Linked List Cycle II, you can refer to this solution for the explanation of the slow fast pointer approach to solve this problem.

// The key is to understand how to treat the input array as a linked list.

// Take the array [1,3,4,2][1,3,4,2][1,3,4,2] as an example, the index of this array is [0,1,2,3][0, 1, 2, 3][0,1,2,3], we can map the index to the nums[n]nums[n]nums[n].

// 0→1→3→2→4→3→20 \to 1 \to 3 \to 2 \to 4 \to 3 \to 20→1→3→2→4→3→2

// Start from nums[n]\textit{nums}[n]nums[n] as a new index, and so on, until the index exceeds the bounds. This produces a sequence similar to a linked list.

// 0→1→3→2→4→null0 \to 1 \to 3 \to 2 \to 4 \to null0→1→3→2→4→null

// If there are a repeated numbers in the array, take the array [1,3,4,2,2][1,3,4,2,2][1,3,4,2,2] as an example,

// 0→1→3→2→4→3→2→4→20 \to 1 \to 3 \to 2 \to 4 \to 3 \to 2 \to 4 \to 20→1→3→2→4→3→2→4→2

// Similarly, a linked list is like that:

// 0→1→3→2→4→2→4→2→…0 \to 1 \to 3 \to 2 \to 4 \to 2 \to 4 \to 2 \to \dots0→1→3→2→4→2→4→2→…

// Here 2→42 \to 42→4 is a cycle, then this linked list can be abstracted as the following figure:

// Link List

// With extra O(n)O(n)O(n) space, without modifying the input.

    public int findDuplicate_fastSlow(int[] nums) {
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
// Analysis
// Time Complexity: O(n)O(n)O(n)
// Space Complexity: O(1)O(1)O(1)