// https://leetcode.com/problems/design-hashset/
// 172 ms
// 41.9 MB

class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<list<int>> bucket;
    
    MyHashSet() {
        bucket.assign(1000, list<int>());
    }
    
    void add(int key) {
        if (contains(key)) return;
        auto& target = bucket[key % 1000];
        target.push_back(key);
    }
    
    void remove(int key) {
        auto& target = bucket[key % 1000];
        auto iter = target.begin();
        while (iter != target.end()) {
            if (*iter == key) break;
            ++iter;
        }
        if (iter != target.end()) target.erase(iter);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto& target = bucket[key % 1000];
        for (auto elem : target) {
            if (elem == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */