/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// This a 2 pass approach by counting the nodes in 1st pass. 
// Performed Deleting in 2nd pass at count-n position. 

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         int count = 0; 
//         ListNode* temp = head;

//         while(temp != NULL){
//             count++;
//             temp = temp->next;
//         }

//         if(count == n){
//             temp = head;
//             head = head->next;
//             delete temp;
//             return head;
//         }

//         temp = head;

//         for(int i=1; i<count-n; i++){
//             temp = temp->next;
//         }

//         ListNode* toDel = temp->next;
//         temp->next = toDel->next;
//         delete toDel;

//         return head;
//     }
// };




//  Optimal Solution
// Maintain a gap of n positions between fast and slow pointers from the starting. 


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        // Important Edge Case - if only head is present.
        if(fast == NULL){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }        

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;

        return head;
    }
};