/*
Implement the RandomizedSet class:

    RandomizedSet() Initializes the RandomizedSet object.
    
    bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present,
    false otherwise.
    
    bool remove(int val) Removes an item val from the set if present. Returns true if the item was present,
    false otherwise.
    
    int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one
    element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.
*/


class RandomizedSet {
public:

    unordered_map<int, int> hash;
    vector<int> vec;


    RandomizedSet() {

    }
    
    bool insert(int val) {
        bool valPresent = (hash.find(val) != hash.end());

        if (!valPresent)
        {
            vec.push_back(val);
            hash[val] = vec.size()-1;
        }

        return !valPresent;
    }
    
    bool remove(int val) {
        bool valPresent = (hash.find(val) != hash.end());

        if (valPresent)
        {
            vec[hash[val]] = vec.back();
            hash[vec.back()] = hash[val];

            vec.pop_back();
            hash.erase(val);
        }

        return valPresent;
    }
    
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */