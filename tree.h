//
// Created by Manju Muralidharan on 11/22/25.
//

#ifndef FA25EC3_TREE_H
#define FA25EC3_TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/*
   TEMPLATE TREE CLASS
   Multiple parents may point to the same child.
   Students must manage storage, pointers, and dynamic allocation.

   Requirements:
   1. Templated Tree class.
   2. Nodes stored dynamically.
   3. Each node has:
      - id
      - data
      - vector of children pointers
   4. Students must prevent memory leaks.
   5. Students must create createRoot, addNode, findNode, print functions, etc.

   DO NOT IMPLEMENT ANYTHING HERE.
   Only placeholders and TODO comments.
*/


template <typename U>
class Node {
public:
    string id;
    U data;
    vector<Node<U>*> children;

    // TODO: Write constructor

// note this will set children to empty
Node(const string &nodeID, const U &value) :
    id(nodeID), data(value), children() {
}

};



       // TODO: Initialize root pointer to nullptr
// we will do this in the tree constructor
template <typename T>
class Tree {
private:
    Node<T>* root;
    Node<T>* findNode2ndpart(Node<T>* currNode, const string &id) {
        // 1st case for just null ptr
        if (currNode == nullptr)
            return nullptr;
        // our base case
        if (currNode->id == id)
            return currNode;

        // use this method upon each child (hence the recursion)
        // so we just check each child with a recursion of findNode
        for (Node<T>* child : currNode->children) {
            // actual recursive call here. remember it calls upon children of node and those children...
            Node<T>* result = findNode2ndpart(child, id);
            if (result != nullptr)
                return result;
        }

        return nullptr;
    }


    // DFS part for destructor (for the most part works the exact same as the above method)
    void destructor2ndpart(Node<T>* node, unordered_set<Node<T>*>& visited) {

        // edge case
        if (!node) {
            return;
        }

        // if we already visited this node we can stop so we dont log same children twice
        if (visited.count(node)) {
            return;
        }

        // now actually mark node as visited
        visited.insert(node);

        // now visit all children recursively
        for (Node<T>* child : node->children) {
            deleteDFS(child, visited);
        }
    }

public:
    // now we actually set the root ptr to null
    Tree() : root(nullptr) {}
    // TODO: Allocate memory, assign id, assign data, set as root
    void createRoot(const string &id, const T &value){
if(root != nullptr) {
    cout << "root exists" << endl;
    return;
}
root = new Node<T>(id, value);
// new root
}


    // TODO: Find parent, create child, link parent to child
    // TODO: Support repeated children under multiple parents

void addNode(const string &parentID, const string &childID, const T &value){
// 1. find parent node
Node<T>* parentNode = findNode(parentID);
if(parentNode == nullptr){
cout <<"error:null parent" << endl;
return;
}
// create new child node using id and value
Node<T>* childNode = new Node<T>(childID, value);
// connect child to parent
parentNode->children.push_back(childNode);
}


Node<T>* findNode(const string &id) {
        // TODO: Use DFS or BFS to search tree
        // we will use DFS recursive search, which we will use a different method for
        // this is so we can change the method headers
        return findNode2ndpart(root, id);
    }

    void printAll(Node<T>* node, int depth) {
        // TODO: Print entire structure in readable form
        // 1st easy case
        if(node == nullptr) {
            return ;
        }
        // 1st for loop: will allow us to go through depth
        for ( int i = 0; i < depth; i++) {
            // first print the id of our node
            cout << " " << node->id << ": " << endl;
            // then call this to then print all of the children
            // note that each child will print itself then go for children in depth
            for (Node<T>* child : node->children) {
                printAll(child, depth + 1);
            }
        }
    }

    ~Tree() {
        // TODO: Free all allocated memory
        // empty tree edge case
        if (!root) {
            return;
        }
        // use a set to track every node we have already seen (to prevent deleting the same node twice)
        // if multiple parents were pointing to same child
        unordered_set<Node<T>*> visited;

        // call recursive delete method (use this to fill in visited with nodes we dont need to delete twice)
        destructor2ndpart(root, visited);

        // safely delete every node once now
        for (Node<T>* node : visited) {
            delete root;
        }
    }

};

#endif //FA25EC3_TREE_H
