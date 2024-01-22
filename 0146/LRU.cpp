#include <list>
#include <unordered_map>
#include <utility>

using std::list;
using std::unordered_map;
using std::pair;

class LRUCache {
public:
    LRUCache(int capacity): m_capacity(capacity) {
    }
    
    int get(int key) {
        auto keyIter = m_keyMap.find(key);
        if (keyIter != m_keyMap.end()) {
            int result = keyIter->second->second;
            m_dataList.erase(keyIter->second);
            m_dataList.emplace_front(key, result);
            m_keyMap[key] = m_dataList.begin();
            return result;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto keyIter = m_keyMap.find(key);
        if (keyIter != m_keyMap.end()) {
            m_dataList.erase(keyIter->second);
            m_dataList.emplace_front(key, value);
            m_keyMap[key] = m_dataList.begin();
        } else {
            m_dataList.emplace_front(key, value);
            if (m_dataList.size() > m_capacity) {
                m_keyMap.erase(m_dataList.back().first);
                m_dataList.pop_back();
            }
            m_keyMap[key] = m_dataList.begin();
        }
    }
private:
    list<pair<int, int>> m_dataList;
    unordered_map<int, list<pair<int, int>>::iterator> m_keyMap;
    int m_capacity{0};
};