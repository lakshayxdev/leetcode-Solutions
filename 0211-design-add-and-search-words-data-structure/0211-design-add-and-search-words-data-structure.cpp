class WordDictionary {
public:
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
 TrieNode *root;
    WordDictionary() {
     root=new TrieNode('\0');
        
    }
    
    void addWord(string word) {
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

    bool helper(TrieNode *root, string word, int index) {
        if(index==word.length()) {
            return root->isLast;
        }
        char ch=word[index];
        if(ch!='.') {
            int idx=ch-'a';
            if(root->children[idx]==NULL) {
                return false;
            }
            else {
                return helper(root->children[idx],word,index+1);
            }
        }

        if(ch=='.') {
            for(int i=0; i<26; i++) {
                if(root->children[i]!=NULL) {
                    if(helper(root->children[i],word,index+1)) {
                        return true;
                    }
                }
            }
        }
         return false;
    }


    bool search(string word) {
        return helper(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */