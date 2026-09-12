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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> mp;
        vector<int> unique;
        ListNode *temp=head;
        while(temp != NULL) {
            mp[temp->val]++;
            temp=temp->next;
        }
        for(auto it:mp) {
            if(it.second==1) {
                unique.push_back(it.first);
            }
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *newhead=dummy;
        for(int i=0; i<unique.size(); i++) {
            ListNode *curr=new ListNode(unique[i]);
            dummy->next=curr;
            dummy=dummy->next;
        }
        return newhead->next;
    }
};