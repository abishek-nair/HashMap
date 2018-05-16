#ifndef HASH_MAP_H

#define HASH_MAP_H

#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <list>

template <class T>
class HashMap {

    public:
    HashMap();
    ~HashMap();
    /*
        Gets the value present at the key
        Returns nullptr if the key doesn't exist
    */
    std::shared_ptr<T> Get(std::string& key);

    /*
        Add's the data at the given key. 
        Overwrites the data if the key already exists
    */
    void Set(std::string& key, std::shared_ptr<T> data);

    /*
        Deletes the value at the given key if it exists and 
        returns True.
        Returns False if the key doesn't exist.
    */
    bool Delete(const std::string& key);

    private:
    int GetHashIndex(std::string& key);
    int CalculateHashcode(std::string& key);
    int GetArrayIndex(int array_size, int hash_code);

    const size_t array_size_ = 2543;
    std::vector<std::unique_ptr<std::list<std::pair<std::string, std::shared_ptr<T>>>>> buckets_;
};

#endif