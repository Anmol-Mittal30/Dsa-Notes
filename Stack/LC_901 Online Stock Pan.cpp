class StockSpanner
{
public:
    // TC -> O(n) , SC-> o(n)
    typedef pair<int, int> P; // {val , span};
    stack<P> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1; // curr day counted
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */