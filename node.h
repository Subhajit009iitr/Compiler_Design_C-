#ifndef NODE_H_
#define NODE_H_

#include <string>  // Include for std::string
#include <vector>  // Include for std::vector

struct Node {
    std::string label;  // String part
    std::vector<Node*> children;  // Vector part for storing child nodes
};

#endif
