#include<iostream>
#include<unordered_map>
using namespace std;
#define hashmap unordered_map<char,node*>
class node
{
    public:
    char data;
    hashmap h;
    bool isterminal;
    node(char d)
    {
        data=d;
        isterminal=false;
    }
};

class trie
{
    node *root;
    public:
    trie()
    {
        root = new node('\0');
    }
    void add_word(char *word)
    {
        node *temp=root;
        int i=0;
        while(word[i]!='\0')
        {
            if(temp->h.count(word[i]==1))
            {
                temp=temp->h[word[i]];
                i++;
            }
            else
            {
                node *temp2=new node(word[i]);
                temp->h[word[i]]=temp2;
                temp=temp2;//remember to update temp
                i++;
            }
        }
        temp->isterminal=true;
    }

    bool search(char *word)
    {
        node *temp = root;
        int i=0;
        while(word[i]!='\0')
        {
            if(temp->h.count(word[i])==0)
            return false;
            else
            {
                temp=temp->h[word[i]];
                i++;
            }
        }
        if(temp->isterminal==true)
        return true;
        else
        return false;
    }

};
int main()
{
  trie t;
  t.add_word("mango");
  t.add_word("apple");
  t.add_word("ape");
  if(t.search("ape"))
    cout<<"found";
    else
    cout<<"not found";
    return 0;
}
