/*
 211. Add and Search Word - Data structure design (M)

 Notes:
    Ref. 211
    Beware the edge case.
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

class WordDictionary {
private:
    TrieNode* head;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = head;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (!cur->children[index])
                cur->children[index] = new TrieNode();

            cur = cur->children[index];
        }
        cur->isEnd = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if (!head) return false;
        int length = word.size();
        return search(word, length, 0, head);
    }

    bool search(string& word, int length, int pos, TrieNode* cur)
    {
        if (pos == length)
            return cur->isEnd;

        if (word[pos] == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (cur->children[i])
                {
                    if (search(word, length, pos + 1, cur->children[i]))
                        return true;
                }
            }
        }
        else
        {
            int index = word[pos] - 'a';
            if (cur->children[index])
                return search(word, length, pos + 1, cur->children[index]);
        }

        return false;
    }
};