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
            if (result != nullptr) {
                return result;
            }
        }

        return nullptr;
    }


    // DFS part for destructor (for the most part works the exact same as the above method)
    void destructor2ndpart(Node<T>* node, unordered_set<Node<T>*>& visited) {

        // edge case
        if (node == nullptr) {
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
            destructor2ndpart(child, visited);
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

    // a node looks like this:
    // [1] TEXT: You stand in a forest clearing. NEXT: 2, 3
    // WTF IS GOING ON HERE
    void addNode(const string &parentID, const string &childID, const T &value) {
        // find parent node
        Node<T>* parentNode = findNode(parentID);
        if (parentNode == nullptr) {
            cout << "parent " << parentID << " not found" << endl;
            return;
        }

        // look for existing child nodes
        Node<T>* childNode = findNode(childID);
        if (childNode == nullptr) {
            childNode = new Node<T>(childID, value); // value MUST be correct text
        }
        // link the parent -> child (allow multi-parents)
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
            cout << " " << node->id << ": " << node->data << endl;
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
        if (root == nullptr) {
            return;
        }
        // use a set to track every node we have already seen (to prevent deleting the same node twice)
        // if multiple parents were pointing to same child
        unordered_set<Node<T>*> visited;

        // call recursive delete method (use this to fill in visited with nodes we dont need to delete twice)
        destructor2ndpart(root, visited);

        // safely delete every node once now
        for (Node<T>* node : visited) {
            delete node;
        }
    }

    // Students, implement a method in Tree<T> called playGame()
    // This method should:
    // 1. Start at the root node.
    // 2. Display the current node's text.
    // 3. Display numbered options for each child.
    // 4. Ask the user which path to take.
    // 5. Move to the selected child and continue until a node has no children.
    // 6. Print an ending message.
    //
    // notes: remember a node looks like this:
    // [1] TEXT: You stand in a forest clearing. NEXT: 2, 3
    // [2] TEXT: You follow a narrow path. NEXT: 4
    // [3] TEXT: You enter a dark cave. NEXT: 4, 5
    // [4] TEXT: You find an abandoned hut. NEXT: 6
    // [5] TEXT: A river blocks your way. NEXT: 6
    // [6] TEXT: You reach the ancient ruins. NEXT:
    // valid paths here:
    // 1 → 2 → 4
    // 7 is not child of 3 so 3->7 not valid
    // printed output then:
    // Node 1: You stand in a forest clearing  Child -> 2  Child -> 3
    // Node 2: You follow a narrow path  Child -> 4
    // Node 3: You enter a dark cave  Child -> 4  Child -> 5
    // Node 4: You find an abandoned hut  Child -> 6
    // Node 5: A river blocks your way  Child -> 6
    // Node 6: You reach the ancient ruins Child -> (none)
    // You are building a dynamic, linked, templated tree that represents a branching adventure story.
    // It must support nodes with multiple parents and children,
    // and it must be fully implemented using pointers and dynamic allocation.

    void playGame() {
        // edge cases
        if (root == nullptr) {
            cout << "error: no game data" << endl;
            return;
        }
        // starting point
        Node<T>* start = root;
        cout << "play start" << endl;

        while (true) {
            //print the node string data
            cout<< "node id: " << start->id << ": " << start->data<<endl;

            // if no children -> just end game
            if (start->children.empty()) {
                cout<< "game end" << endl;
                return;
            }

            // choose which node to go to next
            cout << "Choose an option:" << endl;
            for (int i = 0; i < start->children.size(); i++) {
                cout << " " << (i+1) << ". " << start->children[i]->id << " - " << start->children[i]->data << endl;
            }

            // user choice
            int choice = 0;
            cout << "> " << endl;
            cin >> choice;

            // validate input
            if (choice < 1 || choice > start->children.size()) {
                cout << "invalid choice" << endl;
                continue;
            }
            // go to next node
            start = start->children[choice - 1];

        }
        cout<< "game end" << endl;
    }

};

#endif //FA25EC3_TREE_H
