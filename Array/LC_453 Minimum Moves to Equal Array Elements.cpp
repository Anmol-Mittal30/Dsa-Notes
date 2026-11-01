class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int mini = *min_element(begin(nums), end(nums));
        int moves = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            moves += (nums[i] - mini);
        }
        return moves;
    }
};