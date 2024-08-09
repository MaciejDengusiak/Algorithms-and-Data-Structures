#include "heap.hpp"

template <typename T, typename Compare>
heap<T, Compare>::heap() : _keys(), cmp(Compare()) {}

template <typename T, typename Compare>
heap<T, Compare>::heap(std::initializer_list<T> keys) : _keys(), cmp(Compare()) {
    for(auto key : keys){
        _keys.push_back(key);
    }
    build_heap();
}  

template <typename T, typename Compare>
void heap<T, Compare>::insert(T key){
    _keys.push_back(key);
    move_up(_keys.size() - 1);
}
template <typename T, typename Compare>
const T& heap<T, Compare>::top() const{
    if(_keys.size() == 0){
        throw std::out_of_range("Heap is empty");
    }
    return _keys[0];
}
template <typename T, typename Compare>
T heap<T, Compare>::delete_top(){
    if(_keys.size() == 0){
        throw std::out_of_range("Heap is empty");
    } 
    T result = _keys[0];
    
    std::swap(_keys[0], _keys[_keys.size() - 1]);
    _keys.pop_back();
    move_down(0);

    return result;
}


template <typename T, typename Compare>
bool heap<T, Compare>::isEmpty() const{
    return _keys.size() == 0;
}
template <typename T, typename Compare>
int heap<T, Compare>::size() const{
    return _keys.size();
}

template <typename T, typename Compare>
void heap<T, Compare>::build_heap(){
    for(int i=_keys.size() - 1; i>0; i--){
        move_up(i);
    }
}
template <typename T, typename Compare>
void heap<T, Compare>::move_up(int i){
    if(i >= _keys.size()){
        return;
    }
    while(i > 0){
        int parent = (i - 1) / 2;
        if(cmp(_keys[i], _keys[parent])){
            std::swap(_keys[i], _keys[parent]);
        }
        else{
            break;
        }
        i = parent;
    }
}
template <typename T, typename Compare>
void heap<T, Compare>::move_down(int i){ // to implement
    if(i >= _keys.size()){
        return;
    }
    while(i < _keys.size()) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(right < _keys.size()){
            int t = cmp(_keys[left], _keys[right]) ? left : right;
            if(cmp(_keys[i], _keys[t])){
                return;
            }
            std::swap(_keys[i], _keys[t]);
            i = t;
        }
        else if(left < _keys.size()){
            if(cmp(_keys[i], _keys[left])){
                return;
            }
            std::swap(_keys[i], _keys[left]);
            i = left;            
        }
        else{
            return;
        }
    }
}

template <typename T, typename Compare>
heap<T, Compare>::~heap(){}



