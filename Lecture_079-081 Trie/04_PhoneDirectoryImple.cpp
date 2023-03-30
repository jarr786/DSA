// Qsn-cdnjs Implement a phone directory

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

class Trie{
    public:
    Trienode*root;
    Trie(){
        root=new Trienode('\0');
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
        //absent
        else {
            child=new Trienode(word[0]);
            root->children[index]=child;
        }
        //recursive call 
        insertUtil(child,word.substr(1));
    }

    vector<vector<string>> getSuggetions(string s){
        Trienode*prev=root;
        vector<vector<string>>output;
        string prefix="";
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            prefix.push_back(ch);

            // check for character
            Trienode*curr=prev->children[ch-'a'];
            if(curr==NULL){
                break;
            }
            // if found
            vector<string>temp;

            printSuggestions(curr,temp,prefix);
            output.push_back(temp);

            temp.clear();
            prev=curr;
        }
        return output;
    }

    void printSuggestions(Trienode*curr,vector<string>&temp,string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char ch='a';ch<='z';ch++){
            Trienode*next=curr->children[ch-'a'];

            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestions(next, temp,prefix);

                prefix.pop_back();
            }
        }
    }
};




vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie*t=new Trie();

    // inserting all words to the trie
    for(int i=0;i<contactList.size();i++){
        t->insert(contactList[i]);
    }

    // retuen ans
    return t->getSuggetions(queryStr);

}