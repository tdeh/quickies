// Class for a least recently used (LRU) cache

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <list>

// Class implementing a least recently used (LRU) cache
class LruCache {
 public:
    LruCache(int capacity) : capacity_(capacity), map_(capacity) {}

    // Lookup key in cache and get value if found
    bool Lookup(int key, int* value) {
        auto it = map_.find(key);
        if (it == map_.end()) {
            return false;
        } else {
            // Set value
            *value = it->second.data;

            // Update lru queue
            lru_.erase(it->second.it);
            lru_.push_front(key);
            it->second.it = lru_.begin();

            return true;
        }
    }

    // Insert a key value pair into the cache
    void Insert(int key, int value) {
        if (Full()) {
            // Cache is full; need to evict to make room
            auto it = lru_.rbegin();
            map_.erase(*it);
            lru_.pop_back();
        }

        lru_.push_front(key);
        InternalValue v = {value, lru_.begin()};
        map_.emplace(key, v);
    }

    // Erase key from cache
    void Erase(int key) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            // Erase from lru queue and from map
            lru_.erase(it->second.it);
            map_.erase(key);
        }
    }

    // Get capacity of cache
    size_t GetCapacity() {
        return capacity_;
    }

    // Get number of iterms in the cache
    size_t GetSize() {
        return lru_.size();
    }

    // Check if cache is full
    bool Full() {
        return lru_.size() == capacity_;
    }

    // Check if cache is empty
    bool Empty() {
        return lru_.empty();
    }

 private:
    // Struct containing the value and an iterator to the corresponding location in the LRU queue
    struct InternalValue {
        int data;
        std::list<int>::iterator it;
    };

    std::list<int> lru_;
    std::unordered_map<int, InternalValue> map_;
    size_t capacity_;
};


void TestLruCache() {
    // Test capacity functions
    std::cout << "Testing capacity functions..." << std::endl;
    LruCache single_cache(1);

    // Empty cache of capacity 1
    assert(single_cache.Empty());
    assert(!single_cache.Full());
    assert(single_cache.GetSize() == 0);
    assert(single_cache.GetCapacity() == 1);

    // Full cache of of capacity 1
    single_cache.Insert(1, 1);
    assert(!single_cache.Empty());
    assert(single_cache.Full());
    assert(single_cache.GetSize() == 1);
    assert(single_cache.GetCapacity() == 1);

    LruCache triple_cache(3);

    // Empty cache of capacity 3
    assert(triple_cache.Empty());
    assert(!triple_cache.Full());
    assert(triple_cache.GetSize() == 0);
    assert(triple_cache.GetCapacity() == 3);

    // Cache of capacity 3 with 1 item
    triple_cache.Insert(1, 1);
    assert(!triple_cache.Empty());
    assert(!triple_cache.Full());
    assert(triple_cache.GetSize() == 1);
    assert(triple_cache.GetCapacity() == 3);

    // Full cache of capacity 3
    triple_cache.Insert(2, 1);
    triple_cache.Insert(3, 1);
    assert(!triple_cache.Empty());
    assert(triple_cache.Full());
    assert(triple_cache.GetSize() == 3);
    assert(triple_cache.GetCapacity() == 3);
    std::cout << "=== Success ===" << std::endl;


    // Test modifiers
    std::cout << "Testing modifiers..." << std::endl;
    LruCache cache(5);
    assert(cache.Empty());

    // Insert a couple items
    cache.Insert(1, 1);
    cache.Insert(-190, -190);
    assert(!cache.Empty());

    // Erase the items
    cache.Erase(1);
    cache.Erase(-190);
    assert(cache.Empty());

    // Try to erase an item that does not exist
    cache.Erase(394);
    std::cout << "=== Success ===" << std::endl;


    // Test element access
    std::cout << "Testing element access..." << std::endl;
    int result;
    cache.Insert(1, 1);

    // Lookup item with small key/value
    assert(cache.Lookup(1, &result));
    assert(result = 1);

    // Lookup item with large positive key/value
    cache.Insert(190528, 6666666);
    assert(cache.Lookup(190528, &result));
    assert(result = 6666666);

    // Lookup item with large negative key/value
    cache.Insert(-190528, -6666666);
    assert(cache.Lookup(-190528, &result));
    assert(result = -6666666);

    // Try to lookup item that does not exist
    assert(!cache.Lookup(12345, &result));
    cache.Erase(1);
    cache.Erase(190528);
    cache.Erase(-190528);
    std::cout << "=== Success ===" << std::endl;


    // Test eviction
    std::cout << "Testing eviction..." << std::endl;
    // Fill cache with 0-4
    for (int i = 0; i < 5; ++i) {
        cache.Insert(i, i);
    }

    // Insert another item; the first item inserted (0) should be evicted since it's LRU
    cache.Insert(5, 5);
    assert(!cache.Lookup(0, &result));

    // Insert another 4 items so all original items are evicted
    for (int i = 6; i < 10; ++i) {
        cache.Insert(i, i);
    }

    // Confirm that original items are gone
    for (int i = 0; i < 5; ++i) {
        assert(!cache.Lookup(i, &result));
    }

    // Confirm that new items exist
    for (int i = 5; i < 10; ++i) {
        assert(cache.Lookup(i, &result));
        assert(result == i);
    }

    // Lookup a couple of items so that their position in the LRU queue is updated
    assert(cache.Lookup(7, &result));
    assert(cache.Lookup(5, &result));

    // Insert three more items
    for (int i = 10; i < 13; ++i) {
        cache.Insert(i, i);
    }

    // Confirm that the two items looked up exist and that the other three do not
    assert(cache.Lookup(7, &result));
    assert(cache.Lookup(5, &result));
    assert(!cache.Lookup(6, &result));
    assert(!cache.Lookup(8, &result));
    assert(!cache.Lookup(9, &result));
    std::cout << "=== Success ===" << std::endl;
}


int main() {
    TestLruCache();
}
