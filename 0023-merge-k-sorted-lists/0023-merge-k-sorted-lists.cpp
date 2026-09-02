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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) {
            return NULL;
        }
        priority_queue<int, vector<int>, greater<int>> minheap;

for(int i = 0; i < lists.size(); i++) {

    ListNode* curr = lists[i];

    while(curr != nullptr) {
        minheap.push(curr->val);
        curr = curr->next;
    }
}
        ListNode *dummy=new ListNode(-1);
        ListNode *tail=dummy;
        while(!minheap.empty()) {
            int value=minheap.top();
            minheap.pop();
            ListNode *node=new ListNode(value);
            tail->next=node;
            tail=tail->next;
        }
        return dummy->next;
    }
};