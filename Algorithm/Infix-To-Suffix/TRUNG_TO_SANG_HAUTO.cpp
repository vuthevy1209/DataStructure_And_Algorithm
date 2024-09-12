

#include <iostream>
#include <string>
using namespace std;

struct node{
    char data;
    struct node* next;
};

typedef struct node node;

node* makeNode(char x){
    node* newnode = new node;
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void push_stack(node* &stack, char x){
    node* newnode = makeNode(x);
    if(stack == NULL){
        stack = newnode;
        return;
    }
    newnode->next = stack;
    stack = newnode;
}

 void pop_stack(node* &stack){
     node* temp = stack;
     stack = stack->next;
     delete temp;
 }

char Top(node* stack){
    return stack->data;
}

void remove_all_stack(node** stack){
    node* temp = NULL;
    while(*stack != NULL){
        temp = *stack;
        *stack =(*stack)->next;
        delete  temp;
    }
    *stack = NULL;
}

void in(node* head){
    while(head != nullptr){
        cout << Top(head) << " ";
        head = head->next;
    }
}
int douutienthuattoan(char x)
{
    if (x == '(' || x == ')') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/' || x == '%') return 2;
    if (x == '^') return 3;
    if (x == '$') return 4;
    if (x == ' ') return 5;
    return 6;
}



int main(){
    node* stack = NULL;
    string s;
    getline(cin, s);
    s = s + "$";
    for(int i = 0; i< s.length(); i++){
        int check = douutienthuattoan(s[i]);
        if(check == 0){
            if(s[i] == '(') // Nếu gặp dấu "MỞ NGOẶC" thì push vào stack.
                push_stack(stack, s[i]);
            else{ // nếu gặp dấu "ĐÓNG NGOẶC" thì lấy trong stack ra đến khi gặp dấu mở tương ứng thì dừng.
                while(Top(stack) != '('){
                    cout << Top(stack) << " ";
                    pop_stack(stack);
                }
                pop_stack(stack);
            }
        }
        else if (check == 1 || check == 2 || check == 3){ // Nếu gặp "TOÁN TỬ" ?
            if(stack == NULL) //Nếu gặp "TOÁN TỬ" mà stack trống thì push vào stack
                push_stack(stack, s[i]);
            else{ //Ngược lại điều trên?
                //Nếu độ ưu tiên <= Top thì lấy top ra và push "TOÁN TỬ" vào stack
                //Nếu độ ưu tiên > Top thì ta push và stack
                while(stack != NULL && check <= douutienthuattoan(Top(stack))){
                    cout << Top(stack) << " ";
                    pop_stack(stack);
                }
                push_stack(stack, s[i]);
            }

        }
        else if(check == 4){
            while (stack != NULL){
                cout << Top(stack) << " ";
                pop_stack(stack);
            }
        }
        else if(check == 5)
            continue;
        else
            cout << s[i] << " "; // Nếu gặp toán hạng thì in ra.
    }
    remove_all_stack(&stack);
    return 0;
}

//----------------------- PHIÊN BẢN HOÀN THIỆN HƠN-------------------------------//

//int priority(char x){
//    if(x == '{' || x == '[' || x == '(' || x == '}' || x == ']' || x == ')') return 1;
//    if(x == '+' || x == '-') return 2;
//    if(x == '*' || x == '/' || x == '%') return 3;
//    if(x == '^') return 4;
//    if(x == ' ') return 5;
//    return 6;
//}

//void trung_to_sang_hau_to(node* &head, string s){
//    s = "(" + s + ")";
//    int length = static_cast<int>(s.size());
//    for(int i = 0; i<length; i++){
//        int check = priority(s[i]);
//        if(check == 1){
//            if(s[i] == '{' || s[i] == '[' || s[i] == '(') push(head, s[i]);
//            else{
//                char temp = ' ';
//                if(s[i] == '}') temp = '{';
//                else if(s[i] == ']') temp = '[';
//                else temp = '(';
//                while(top(head) != temp){
//                    cout << top(head) << " ";
//                    pop(head);
//                }
//                pop(head);
//            }
//        }
//        else if(check == 2 || check == 3 || check == 4){
//            if(Empty(head)) push(head, s[i]);
//            else{
//                int priority_top = priority(top(head));
//                while(!Empty(head) && check <= priority_top){
//                    cout << top(head) << " ";
//                    pop(head);
//                }
//                push(head, s[i]);
//            }
//        }
//        else if(check == 5) continue;
//        else{
//            cout << s[i] << " ";
//        }
//    }
//}
//
//
