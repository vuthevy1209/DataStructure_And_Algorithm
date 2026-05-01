#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T, class P>
class PriorityQueue{
private:
    struct Item{
        T value;
        P priority;
        int id;
    };

    vector<Item> data;
    vector<int> pos;
    int next_id;
    bool (*cmp)(P, P);

    void swap_items(int i, int j){
        Item temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        pos[data[i].id] = i;
        pos[data[j].id] = j;
    }

    void heapify_up(int idx){
        while(idx > 0){
            int parent = (idx - 1) / 2;
            if(cmp(data[idx].priority, data[parent].priority)){
                swap_items(idx, parent);
                idx = parent;
            }else break;
        }
    }

    void heapify_down(int idx){
        int n = size();
        while(true){
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int best = idx;

            if(left < n && cmp(data[left].priority, data[best].priority)) best = left;
            if(right < n && cmp(data[right].priority, data[best].priority)) best = right;

            if(best != idx){
                swap_items(idx, best);
                idx = best;
            }else break;
        }
    }

public:
    PriorityQueue(bool (*cmp_func)(P, P)) : next_id(0), cmp(cmp_func) {}

    bool empty(){
        return data.empty();
    }
    int size(){
        return static_cast<int>(data.size());
    }

    int push(T value, P priority){
        Item it; it.value = value; it.priority = priority; it.id = next_id;
        if(next_id >= static_cast<int>(pos.size())) pos.push_back(-1);
        data.push_back(it);
        pos[it.id] = size() - 1;
        heapify_up(size() - 1);
        return next_id++;
    }

    void pop(){
        if(empty()) return;
        int removed_id = data[0].id;
        data[0] = data.back();
        data.pop_back();
        if(!empty()){
            pos[data[0].id] = 0;
            heapify_down(0);
        }
        pos[removed_id] = -1;
    }

    T top(){
        if(empty()) return T();
        return data[0].value;
    }

    P top_priority(){
        if(empty()) return P();
        return data[0].priority;
    }

    bool update_key(int id, P new_priority){
        if(id < 0 || id >= static_cast<int>(pos.size())) return false;
        int idx = pos[id];
        if(idx < 0 || idx >= size()) return false;
        P old_priority = data[idx].priority;
        data[idx].priority = new_priority;
        if(cmp(new_priority, old_priority)) heapify_up(idx);
        else heapify_down(idx);
        return true;
    }
};
