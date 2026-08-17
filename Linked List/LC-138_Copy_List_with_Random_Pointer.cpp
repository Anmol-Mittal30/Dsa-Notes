/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
   // TC -> O(n), SC -> O(n)
   // Approach 1: HashMap
    //  Node* copyRandomList(Node* head) {
    //     if(head == NULL) return NULL;
    //     unordered_map<Node* , Node* > mp;
    //     Node* curr = head;
    //     // create copy and map with original
    //     while(curr != NULL){
    //         mp[curr] = new Node(curr->val);
    //         curr = curr->next;
    //     }


    //     curr = head;

    //     while(curr != NULL){
    //         mp[curr]->next = mp[curr->next];
    //         mp[curr]->random = mp[curr->random];
    //         curr = curr->next;
    //     }
    //     return mp[head];
    // }



// TC -> O(n), SC -> O(1)
// Approach 2: Interweaving / In-place
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node* curr = head;

        // Step 1: Create copy and place it after original
        // 1 -> 1' -> 2 -> 2' -> 3 -> 3'  store in this form
        while(curr != NULL){
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Connect random pointers
        curr = head;
        while(curr != NULL){
            if(curr->random !=NULL){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate original and copied list
        curr = head;
        Node* copyhead = curr->next; 

        while(curr != NULL){
            Node* copy = curr->next;
            curr->next = copy->next;
            if(copy->next != NULL) copy->next = copy->next->next;
            curr = curr->next;
        }

        return copyhead;

    }
};