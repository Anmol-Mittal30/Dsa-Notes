// ### Approach: Merge Sort (Decreasing Order)

// - Store each element as `{value, original_index}` to preserve its original position.
// - Apply merge sort to count smaller elements while merging the two halves.
// - Sort both halves in **decreasing order**.
// - If `arr[i].first <= arr[j].first`, take the right element.
// - Otherwise, `arr[i].first > arr[j].first`, so all elements from `j` to `r` are smaller than the current left element.
// - Update the answer using `ans[arr[i].second] += r - j + 1`.
// - Merge the elements into a temporary array and copy them back.

// **Complexity**
// - Time: `O(n log n)`
// - Auxiliary Space: `O(n)`


// TC -> O(n log n) , SC -> O(n) , n = size of nums

class Solution
{
public:
    vector<int> ans;
    int n;
    void mergeCount(int l, int mid, int r, vector<pair<int, int>> &arr)
    {
        vector<pair<int, int>> temp(r - l + 1);
        int i = l;
        int j = mid + 1; // {i , i+1 , i+2 , ...mid} {mid+1 , j+1 , j+2 , ... r};
        int k = 0;
        while (i <= mid && j <= r)
        {
            if (arr[i].first <= arr[j].first)
            { // {5 , 2} , {6 , 1} -> 5 <= 6
                temp[k++] = arr[j++];
            }
            else
            {
                ans[arr[i].second] += r - j + 1;
                temp[k++] = arr[i++];
            }
        }
        while (i <= mid)
            temp[k++] = arr[i++];
        while (j <= r)
            temp[k++] = arr[j++];

        for (int k = 0; k < temp.size(); k++)
        {
            arr[l + k] = temp[k];
        }
    }
    void merge(int l, int r, vector<pair<int, int>> &arr)
    {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        merge(l, mid, arr);
        merge(mid + 1, r, arr);
        mergeCount(l, mid, r, arr);
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        n = nums.size();
        ans.assign(n, 0);
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i}); // {val , idx}
        merge(0, n - 1, arr);
        return ans;
    }
};