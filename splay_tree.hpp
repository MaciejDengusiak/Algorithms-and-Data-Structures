#ifndef SPLAY_TREE_HPP
#define SPLAY_TREE_HPP

#include <iostream>

template<typename T, typename Compare = std::less<T>> 
class splay_tree{
public:
    splay_tree();
    splay_tree(std::initializer_list<T> keys);
    ~splay_tree();

    void insert(T key);
    void remove(T key);
    T find(T value) const;
    friend splay_tree& join()
private:

};

#endif