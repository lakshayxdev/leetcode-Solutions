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
ListNode *Reverse(ListNode *head) {
    ListNode *temp=head;
    ListNode *prev=NULL;
    while(temp != NULL) {
        ListNode *NEXT=temp->next;
        temp->next=prev;
        prev=temp;
        temp=NEXT;
    }
    return prev;
}
    void reorderList(ListNode* head) {
        ListNode *temp=head;
        ListNode *slow=temp;
        ListNode *fast=temp;
        while(fast != NULL && fast->next != NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *curr=slow->next;
        slow->next=NULL;
        curr=Reverse(curr);
        ListNode *temp2=head;
        while(temp2 != NULL && curr != NULL) {
            ListNode *next1=temp2->next;
            ListNode *next2=curr->next;
            temp2->next=curr;
            curr->next=next1;

            temp2=next1;
            curr=next2;
        }
    }
};