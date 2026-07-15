class TrieNode {
    public:
    char data;
    TrieNode *children[26];
    bool isLast;

    TrieNode(char ch) {
        data=ch;
        for(int i=0; i<26; i++) {
            children[i]=NULL;
        }
        isLast=false;
    }
};

class Trie {
public:
TrieNode *root;
    Trie() {
        root=new TrieNode('\0');
    }
    
    void insert(string word) {
        TrieNode *curr=root;
        for(char ch:word) {
            int index=ch-'a';
            if(curr->children[index]==NULL) {
                curr->children[index]=new TrieNode(ch);
            }
            curr=curr->children[index];
        }
        curr->isLast=true;
    }
    
    bool search(string word) {
        TrieNode *curr=root;
        for(char ch:word) {
            int index=ch-'a';
            if(curr->children[index]==NULL) {
                return false;
            }
            curr=curr->children[index];
        }
        return curr->isLast;
    }
    
    bool startsWith(string prefix) {
         TrieNode *curr=root;
        for(char ch:prefix) {
            int index=ch-'a';
            if(curr->children[index]==NULL) {
                return false;
            }
            curr=curr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */