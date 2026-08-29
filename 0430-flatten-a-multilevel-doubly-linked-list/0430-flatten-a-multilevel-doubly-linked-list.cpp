/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) {
            return NULL;
        }
        Node *temp=head;
        while(temp!=NULL) {
            if(temp->child!=NULL) {
                Node *stored=temp->next;
                temp->next=temp->child;
                temp->child->prev=temp;
                Node *curr=temp->next;
                while(curr->next!=NULL) {
                    curr=curr->next;
                }
                curr->next=stored;
                if(stored) {
                    stored->prev=curr;
                }
            }
            temp=temp->next;
        }

        Node *temp2=head;
        while(temp2!=NULL) {
            temp2->child=NULL;
            temp2=temp2->next;
        }
        return head;
    }
};