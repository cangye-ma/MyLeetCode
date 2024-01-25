#include <string>
#include <array>
#include <memory>

using namespace std;

namespace {
    constexpr int charNum = 26;
    struct TrieNode
    {
        char m_currChar{' '};
        int m_count{0};
        array<shared_ptr<TrieNode>, charNum> m_nextNode;
        TrieNode(char currChar) : m_currChar(currChar) {
            for (auto &elem : m_nextNode) {
                elem = nullptr;
            }
        }
    };
}


class Trie {
public:
    Trie() {
        rootNode = make_shared<TrieNode>(' ');
    }
    
    void insert(string word) {
        size_t wordSize = word.size();
        if (wordSize == 0) {
            return;
        }
        shared_ptr<TrieNode> currNode = rootNode;
        for (int i = 0; i < wordSize; ++i) {
            if (currNode->m_nextNode[word[i] - 'a'] == nullptr) {
                currNode->m_nextNode[word[i] - 'a'] = make_shared<TrieNode>(word[i]); 
            }
            currNode = currNode->m_nextNode[word[i] - 'a'];
        }
        currNode->m_count = 1;
    }
    
    bool search(string word) {
        size_t wordSize = word.size();
        shared_ptr<TrieNode> currNode = rootNode;
        bool hasFound{true};
        for (int i = 0; i < wordSize; ++i) {
            if (currNode->m_nextNode[word[i] - 'a'] == nullptr) {
                hasFound = false;
                break; 
            }
            currNode = currNode->m_nextNode[word[i] - 'a'];
        }
        return hasFound && currNode->m_count == 1;
    }
    
    bool startsWith(string prefix) {
        size_t wordSize = prefix.size();
        if (wordSize == 0) {
            return true;
        }
        shared_ptr<TrieNode> currNode = rootNode;
        bool hasFound{true};
        for (int i = 0; i < wordSize; ++i) {
            if (currNode->m_nextNode[prefix[i] - 'a'] == nullptr) {
                hasFound = false;
                break; 
            }
            currNode = currNode->m_nextNode[prefix[i] - 'a'];
        }
        return hasFound;
    }

private:
    shared_ptr<TrieNode> rootNode{nullptr};
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */