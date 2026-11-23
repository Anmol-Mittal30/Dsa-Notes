class ProductOfNumbers
{
public:
    //  TC -> O(1) , SC-> O(1)
    vector<int> nums; // cum product
    int n;            // cnt the element present in product array
    ProductOfNumbers()
    {
        nums.clear();
        n = 0;
    }

    void add(int num)
    {
        if (num == 0)
        {
            nums = {};
            n = 0;
        }
        else
        {
            if (nums.empty())
                nums.push_back(num);
            else
                nums.push_back(nums[n - 1] * num);
            n++; // incr the array size by 1
        }
    }

    int getProduct(int k)
    {
        if (k > n)
            return 0; // due to 0 , so size of array is less than
        if (k == n)
            return nums[n - 1]; // last element
        return nums[n - 1] / nums[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */