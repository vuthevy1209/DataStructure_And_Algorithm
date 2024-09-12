#include <iostream>
using namespace std;

// Định nghĩa một nút trong danh sách liên kết đơn
struct Node {
    int data;
    Node* next;
};

using node = struct Node;

// Hàm hỗ trợ, trộn hai danh sách liên kết đã sắp xếp và trả về danh sách liên kết đã trộn
node* Merge(node* left, node* right){
    node* result = nullptr;
    if(left == nullptr){
        return right;
    }
    else if (right == nullptr){
        return left;
    }
    if(left->data <= right->data){
        result = left;
        result->next = Merge(left->next, right);
    }
    else{
        result = right;
        result->next = Merge(left, right->next);
    }
    return result;
}
void Merge_Sort(node*& head){
    if(head == nullptr || head->next == nullptr){
        return;
    }
    node* left = head;
    node* right = head->next;
    left->next = nullptr;
    Merge_Sort(left);
    Merge_Sort(right);
    head = Merge(left, right);
}

