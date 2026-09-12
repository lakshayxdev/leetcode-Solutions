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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp=head;
        ListNode *curr=new ListNode(-1);
        ListNode *mainhead=curr;
        while(temp != NULL) {
            if(temp->val < x) {
                curr->next=new ListNode(temp->val);
                curr=curr->next;
            }
            temp=temp->next;
        }
        ListNode *temp2=head;
        while(temp2 != NULL) {
            if(temp2->val >= x) {
                curr->next=new ListNode(temp2->val);
                curr=curr->next;
            }
            temp2=temp2->next;
        }
        return mainhead->next;
    }
};