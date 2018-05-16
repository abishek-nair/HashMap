#include "HashMap.h"

#include <cmath>

HashMap::HashMap() {
    
}

HashMap::~HashMap() {
    this->buckets_.clear();
}

std::shared_ptr<T> HashMap::Get(std::string& key) {

    int hash_index = this->GetHashIndex(key);

    auto bucket = this->buckets_[hash_index];

    if (bucket == nullptr) {
        return nullptr;
    }

    std::shared_ptr<T> value = nullptr;

    for (auto it = bucket.begin(); it != bucket.end(); it++) {
        if (it->first == key) {
            value = it->second;
            break;
        }
    }

    return value;
}

void HashMap::Set(std::string& key, std::shared_ptr<T> data) {

    int hash_index = this->GetHashIndex(key);

    if (this->buckets_[hash_index] == nullptr) {
        // std::list<std::pair<std::string, std::shared_ptr<T>>>
        auto bucket_list;
        this->buckets_[hash_index] = std::make_shared(bucket_list);
    }

    auto bucket_list = this->buckets_[hash_index];

    auto value_pair = std::make_pair(key, data);
    bucket_list.push_front(value_pair);
}

bool HashMap::Delete(std::string& key) {

    int hash_index = this->GetHashIndex(key);

    if (this->buckets_[hash_index] == nullptr) {
        return false;
    }

    auto bucket_list = this->buckets_[hash_index];

    std::shared_ptr<T> value = nullptr;

    bucket_list->remove_if(
        [](std::pair<std::string, std::shared_ptr<T>> value_pair) {
            return (value_pair.first == key);
        });

    return true;
}

int HashMap::GetHashIndex(std::string& key) {

    int hash_code = this->CalculateHashcode(key);
    int array_index = this->GetArrayIndex(this->array_size_, hash_code);

    return array_index;
}

int HashMap::CalculateHashcode(std::string& key) {

    if (key.size() == 0) {
        return 0;
    }

    int hash = 0;

    for (char& ch : key) {
        hash = ((31 * hash) + (int) ch);
    }

    return hash;
}

int HashMap::GetArrayIndex(int array_size, int hash_code) {

    int array_index = (std::abs(hash_code) % array_size);

    return array_index;
}