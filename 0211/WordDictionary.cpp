#include<string>
#include<array>
#include<memory>
using namespace std;
struct TrieNode {
    TrieNode(char currChar): m_currChar(currChar) {
        for (auto &elem : m_nextTrieNode) {
            elem = nullptr;
        }
    }
    char m_currChar{' '};
    int m_count{0};
    array<shared_ptr<TrieNode>, 26> m_nextTrieNode;
};

class WordDictionary {
public:
    WordDictionary() {
        m_rootNode = make_shared<TrieNode>(' ');
    }
    
    void addWord(string word) {
        int wordSize = word.size();
        shared_ptr<TrieNode> currNode = m_rootNode;
        for (int i = 0; i < wordSize; ++i) {
            if (currNode->m_nextTrieNode[word[i] - 'a'] == nullptr) {
                currNode->m_nextTrieNode[word[i] - 'a'] = make_shared<TrieNode>(word[i]);
            }
            currNode = currNode->m_nextTrieNode[word[i] - 'a'];
        }
        currNode->m_count = currNode->m_count + 1;
    }
    
    bool search(string word) {
        int wordSize = word.size();
        bool hasFound{true};
        shared_ptr<TrieNode> currNode = m_rootNode;
        for (int i = 0; i < wordSize; ++i) {
            if (currNode->m_nextTrieNode[word[i] - 'a'] == nullptr) {
                hasFound = false;
                break;
            }
            currNode = currNode->m_nextTrieNode[word[i] - 'a'];
        }
        return hasFound && currNode->m_count > 0;
    }
private:
    shared_ptr<TrieNode> m_rootNode{nullptr};
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */