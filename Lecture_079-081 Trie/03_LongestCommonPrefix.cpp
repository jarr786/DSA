// Input: {“apple”, “ape”, “april”}
// Output: “ap”
class Trienode{
    public:
    char data;
    Trienode*children[26];
    int childcount;
    bool isTerminal;
    Trienode(char x){
        data=x;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
        childcount=0;
    }
};

class Trie{
    public:
    Trienode*root;
    Trie(char x){
        root=new Trienode(x);
    }
    

    void insert(string word){
        insertUtil(root,word);
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
        // absent
        else {
          child = new Trienode(word[0]);
          root->children[index] = child;
          root->childcount++;
        }
        // recursive call
        insertUtil(child, word.substr(1));
    }

    // traversing and checking
    void getanswer(string word,string &ans){
        for(int i=0;i<word.size();i++){
            if(root->childcount!=1) break;
            else if(root->childcount==1){
                int index=word[i]-'a';
                ans+=word[i];
                root=root->children[index];
            }
            else if(root->isTerminal==true) break;
        }
    }
};


string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie*t=new Trie('\0');
    for(int i=0;i<arr.size();i++){
        t->insert(arr[i]);
    }
    string ans="";

    t->getanswer(arr[0],ans);

    return ans;
}


