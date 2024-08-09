#include "avl.hpp"

template <typename T, typename Compare>
avl_tree<T, Compare>::avl_node::avl_node(avl_node *up, T val) : up(up), left(nullptr), right(nullptr)
                                                                val(val), h(0) {};
                                                                
template <typename T, typename Compare>
avl_tree<T, Compare>::avl_tree() : root(nullptr){}

template <typename T, typename Compare>
avl_tree<T, Compare>::avl_tree(std::initializer_list<T> keys) : root(nullptr){
    for(auto key : keys){
        insert(key);
    }
}
                                                          