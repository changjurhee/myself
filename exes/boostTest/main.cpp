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

/*
// ex25.1
#include <boost/property_tree/ptree.hpp>
#include <iostream>

using boost::property::ptree;

int main(){
    ptree pt;
    pt.put("C:.Windows.System", "20 files");
    
    ptree &c = pt.get_child("C:");
    ptree &windows = c.get_child("Windows");
    ptree &system = windows.get_child("System");
    
    std::cout << system.get_value<std::string>() << '\n';
}
*/

// ex ; json file read
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>

int main(){
    // Short alias for this namespace
    namespace pt = boost::property_tree;
    
    // Create a root
    pt::ptree root;
    
    // Load the json file in this ptree
    pt::read_json("test.json", root);

    // Read values
    int height = root.get<int>("height", 0);
    std::cout << height << '\n';
    
    // You can also go through nested nodes
    std::string msg = root.get<std::string>("some.complex.path");
    std::cout << msg << '\n';
    
    // A vector to allow storing our animals
    std::vector< std::pair<std::string, std::string> > animals;
    
    // Iterator over all animals
    for (pt::ptree::value_type &animal : root.get_child("animals"))
    {
        // Animal is a std::pair of a string and a child
        
        // Get the label of the node
        std::string name = animal.first;
        // Get the content of the node
        std::string color = animal.second.data();
        animals.push_back(std::make_pair(name, color));
        
        std::cout << name << ", " << color << '\n';
    }
    
    std::vector<std::string> fruits;
    for (pt::ptree::value_type &fruit : root.get_child("fruits"))
    {
        // fruit.first contain the string ""
        fruits.push_back(fruit.second.data());
        
        std::cout << fruit.second.data() << '\n';
    }
    
    int matrix[3][3];
    int x = 0;
    for (pt::ptree::value_type &row : root.get_child("matrix"))
    {
        int y = 0;
        for (pt::ptree::value_type &cell : row.second)
        {
            matrix[x][y] = cell.second.get_value<int>();
            std::cout << "[" << x << "," << y << "]" << cell.second.get_value<int>() << '\n';
            y++;
        }
        x++;
    }
    
    // writing JSON
    // Once our ptree was constructed, we can generate JSON on standard output
    pt::write_json(std::cout, root);
    
    // Add values
    height = 5;
    root.put("height", height);
    root.put("some.complex.path", "bonjour");
    
    // Create a node
    pt::ptree animals_node;
    // Add animals as childs
    for (auto &animal : animals)
        animals_node.put(animal.first, animal.second);
    // Add the new node to the root
    root.add_child("animals", animals_node);
    
    // Add two objects with the same name
    pt::ptree fish1;
    fish1.put_value("blue");
    pt::ptree fish2;
    fish2.put_value("yellow");
    root.push_back(std::make_pair("fish", fish1));
    root.push_back(std::make_pair("fish", fish2));
    
    // Add a list
    pt::ptree fruits_node;
    for (auto &fruit : fruits)
    {
        // Create an unnamed node containing the value
        pt::ptree fruit_node;
        fruit_node.put("", fruit);
        
        // Add this node to the list.
        fruits_node.push_back(std::make_pair("", fruit_node));
    }
    root.add_child("fruits", fruits_node);
    
    // Add a matrix
    pt::ptree matrix_node;
    for (int i = 0; i < 3; i++)
    {
        pt::ptree row;
        for (int j = 0; j < 3; j++)
        {
            // Create an unnamed value
            pt::ptree cell;
            cell.put_value(matrix[i][j]);
            // Add the value to our row
            row.push_back(std::make_pair("", cell));
        }
        // Add the row to our matrix
        matrix_node.push_back(std::make_pair("", row));
    }
    // Add the node to the root
    root.add_child("matrix", matrix_node);
    
    pt::write_json("modify.json", root);
    
}
