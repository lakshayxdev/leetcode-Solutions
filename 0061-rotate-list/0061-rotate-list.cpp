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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) {
            return head;
        }
        ListNode *curr=head;
        int length=0;
        while(curr!=NULL) {
            length++;
            curr=curr->next;
        }
        int K=k%length;
        while(K>0) {
            ListNode *prev=NULL;
            ListNode *temp=head;
            while(temp->next != NULL) {
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            temp->next=head;
            head=temp;
            K--;
        }
        return head;
    }
};