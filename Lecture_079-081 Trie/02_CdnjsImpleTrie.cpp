/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class Trienode{
    public:
    char data;
    Trienode*children[26];
    bool isTerminal;
    Trienode(char x){
        data=x;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};


class Trie {
 public:
    Trienode*root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root=new Trienode('\0');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
         insertUtil(root,word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
         return searchUtil(root,word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return starts(root,prefix);
    }

    bool starts(Trienode*root,string word){
        if(word.length()==0){
            return true;
        }
        int index=word[0]-'a';

        //present
        Trienode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        // absent 
        else return false;

        //reccursive call
        return starts(child,word.substr(1));
    }


    void insertUtil(Trienode*root,string word){
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        Trienode*child;
        int index=word[0]-'a';
        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        //absent
        else {
            child=new Trienode(word[0]);
            root->children[index]=child;
        }
        //recursive call 
        insertUtil(child,word.substr(1));
    }

    bool searchUtil(Trienode*root,string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'a';

        //present
        Trienode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        // absent 
        else return false;

        //reccursive call
        return searchUtil(child,word.substr(1));
    }
};