#include <iostream>
#include <memory>
#include "HashMap.h"

using namespace std;

int main() {

    cout << "Hello World" << endl;

    HashMap<int> hashMap;

    std::string key = "abi";
    auto val = std::make_shared(new int(25));

    hashMap.Set(key, val);

    std::cout << hashMap.Get(key) << std::endl;

    return 0;
}