//#define EX4_1
#define EX25_1

// ex4.1
/*
#include <boost/pool/simple_segregated_storage.hpp>
#include <vector>
#include <cstdef>

int main(){
    boost::simple_segragated_storage<std::size_t> storage;
    std::vector<char> v(1024);
    storage.add_block(&v.front(), v.size(), 256);
    
    int *i = static_cast<int*>(storage_malloc());
    *i = 1;
    
    int *j = static_cast<int*>(storage.malloc_n(1, 512));
    j[10] = 2;
    
    storage.free(i);
    storage_n.free(j,1,512);
}
*/

// ex25.1
#include <boost/property_tree/ptree.hpp>
#include <iostream>

using boost::property_tree::ptree;

int main(){
    
    ptree pt;
    pt.put("C:.Windows.System", "20 files");
    
    ptree &c = pt.get_child("C:");
    ptree &windows = c.get_child("Windows");
    ptree &system = windows.get_child("System");
    
    std::cout << system.get_value<std::string>() << '\n';
}
