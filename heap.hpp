#ifndef HEAP_HPP
#define HEAP_HPP

#include <stdexcept>
#include <vector>

template <typename T, typename Compare = std::less<T>>
class heap{
public:
    heap();
    heap(std::initializer_list<T> keys);
    ~heap();

    void insert(T key);
    T delete_top();
    const T& top() const;
    bool isEmpty() const;
    int size() const;

private:
    std::vector<T> _keys;
    Compare cmp;

    void build_heap();
    void move_up(int i);
    void move_down(int i);
};  

#endif