#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class AllOne {
	struct LinkNode {
		LinkNode* prev = nullptr;
		LinkNode* next = nullptr;
		string key = "";
		int value = 0;
	};
	vector<LinkNode*> storage_;
	map<string, LinkNode*> loc_;
public:
    /** Initialize your data structure here. */
    AllOne() {
		storage_.push_back(new LinkNode);
    }

	~AllOne() {
		for (auto p : storage_) {
			while (p) {
				auto next = p->next;
				delete p;
				p = next;
			}
		}
	}
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
		auto it = loc_.find(key);
		if (it == loc_.end() || it->second == nullptr) {
			// Create a new node.
			auto node = new LinkNode;
			node->key = key;
			loc_[key] = node;
			// Add to the new queue.
			if (storage_[0]->next)
				storage_[0]->next->prev = node;
			node->next = storage_[0]->next;
			node->prev = storage_[0];
			storage_[0]->next = node;
		}
		else {
			auto node = it->second;
			// Delete from the original queue.
			node->prev->next = node->next;
			if (node->next)
				node->next->prev = node->prev;
			// Check existence of the new queue.
			if (++node->value >= storage_.size())
				storage_.push_back(new LinkNode);
			// Add to the new queue.
			if (storage_[node->value]->next)
				storage_[node->value]->next->prev = node;
			node->next = storage_[node->value]->next;
			node->prev = storage_[node->value];
			storage_[node->value]->next = node;
		}
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
		auto it = loc_.find(key);
		if (it != loc_.end() && it->second != nullptr) {
			auto& node = it->second;
			// Delete from the original queue.
			node->prev->next = node->next;
			if (node->next)
				node->next->prev = node->prev;
			if (node->value) {
				// Add to the new queue.
				if (storage_[--node->value]->next)
					storage_[node->value]->next->prev = node;
				node->next = storage_[node->value]->next;
				node->prev = storage_[node->value];
				storage_[node->value]->next = node;
			}
			else {
				delete node;
				node = nullptr;
			}
		}
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
		for (int i = storage_.size() - 1; i >= 0; --i)
			if (storage_[i]->next)
				return storage_[i]->next->key;
		return "";
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
		for (int i = 0; i < storage_.size(); ++i)
			if (storage_[i]->next)
				return storage_[i]->next->key;
		return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */