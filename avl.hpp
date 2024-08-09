#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>

template <typename T, typename Compare = std::less<T>>
class avl_tree{
public:
    avl_tree();
    avl_tree(std::initializer_list<T> keys);
    ~avl_tree();

    void insert(T key);
    void remove(T key);
    T find(T value) const;
private:
    struct avl_node{
        avl_node *up;
        avl_node *left;
        avl_node *right;
        T val;
        int h;

        avl_node(avl_node *up, T val);
        avl_node* upper();
        avl_node* lower();
    };
    avl_node* root;
    Compare cmp;

    void left(avl_node *node);
    void right(avl_node *node);
    void clear(avl_node *node);
};

#endif