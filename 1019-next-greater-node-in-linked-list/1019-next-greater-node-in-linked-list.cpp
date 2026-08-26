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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> list;
        ListNode *temp=head;
        while(temp != NULL) {
            list.push_back(temp->val);
            temp=temp->next;
        }
        int n=list.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && list[i] > list[st.top()]) {
                ans[st.top()]=list[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};