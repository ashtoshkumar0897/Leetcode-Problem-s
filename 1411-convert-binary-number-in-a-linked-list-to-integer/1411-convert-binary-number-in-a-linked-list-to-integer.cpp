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

 // Aproch 1 revesed the linklist then clculate the value 2^0  2^1  2^2
class Solution {
public:
    //Reverse linklist
    ListNode* reverseLL(ListNode* head){
        if (head == NULL || head-> next ==NULL){
            return head;
        }

        ListNode* last =reverseLL(head->next);
        head->next->next =head;
        head->next=NULL;
        return last;
    }


    int getDecimalValue(ListNode* head) {
        head = reverseLL(head);

        int result = 0;
        int power = 0;
        while(head){
            if(head->val ==1){
                result += pow(2,power);
            }
            power++;
            head = head->next;
        }

        return result;
    }
};