#include<iostream>
using namespace std;
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
    
    bool search(string word){
        return searchUtil(root,word);
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

    void deleteword(string word ){
        deleteUtill(root,word);
    }
    void deleteUtill(Trienode*root,string word){
         //base case
        if(word.length()==0){
            // impo
            root->isTerminal=false;
            return;
        }
        int index=word[0]-'a';

        //present
        Trienode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        // absent 
        else return;
        //reccursive call
        deleteUtill(child,word.substr(1));
    }
};
int main(){
    Trie *t=new Trie();
    t->insert("apple");
    t->insert("ale");
    t->insert("app");
    cout<<t->search("apple")<<endl;
    cout<<t->search("appleee")<<endl;
    cout<<t->search("app")<<endl;
    t->deleteword("app");
    cout<<t->search("app")<<endl;
return 0;
}