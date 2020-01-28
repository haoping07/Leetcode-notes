/*
 208. Implement Trie (Prefix Tree) (M)

 Notes:
    Ref. 211
*/

class TrieNode
{
public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode() : isEnd(false)
    {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* ptr = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';

            if (!ptr->children[index])
                ptr->children[index] = new TrieNode();

            ptr = ptr->children[index];
        }

        ptr->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* ptr = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';

            if (!ptr->children[index])
                return false;

            ptr = ptr->children[index];
        }

        return ptr->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int index = prefix[i] - 'a';

            if (!ptr->children[index])
                return false;

            ptr = ptr->children[index];
        }

        return true;
    }
};