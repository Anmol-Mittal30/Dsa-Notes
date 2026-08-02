/*
Problem: 23. Merge k Sorted Lists
Topic: Linked List, Divide and Conquer
Difficulty: Hard

Approach:
- Recursively divide the k sorted linked lists into two halves.
- Merge the left and right halves using the standard Merge Two Sorted Lists algorithm.
- This balanced merging strategy follows the Merge Sort paradigm.

Let:
- k = Number of linked lists
- N = Total number of nodes across all linked lists

Time Complexity: O(N log k)
Space Complexity: O(N)  // Due to recursive merge function
                  // O(log k) if mergeTwoSortedLists() is implemented iteratively
*/


class Solution {
public:
    // Tc -> O(N log K) ,k = number of ll , N = total number of nodes across all ll
    ListNode* mergeTwoSortedLists(ListNode* l1 , ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val <= l2->val) {
          l1->next =   mergeTwoSortedLists(l1->next , l2);
            return l1 ;
        } else {
          l2->next =  mergeTwoSortedLists(l1 , l2->next);
            return l2 ;
        }
        return NULL ;
    }

    ListNode* partionAndMerge(int start , int end , vector<ListNode*>& lists){
        if(start > end) return NULL ;
        if(start == end) return lists[start];
        int mid = start + (end - start)/2;
        ListNode* l1 = partionAndMerge(start , mid , lists);
        ListNode* l2 = partionAndMerge(mid+1 , end , lists);
        return mergeTwoSortedLists(l1 , l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        return partionAndMerge(0 , n-1 , lists);
    }
};

