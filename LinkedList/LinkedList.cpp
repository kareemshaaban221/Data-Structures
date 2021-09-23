#include <iostream>

using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node* next;
        Node(T data){
            this->data = data;
            next = NULL;
        }
};

template <typename T>
class List{
    private:
        Node<T>* Head;
        Node<T>* Tail;
        int len;

    public:
        List(){
            Head = Tail = NULL;
            len = 0;
        }

        int size(){
            return this->len;
        }

        bool isEmpty(){
            return !this->len;
        }

        bool isFull(){
            return 0;
        }

        T peek_back(){
            return this->Tail->data;
        }

        T peek_front(){
            return this->Head->data;
        }

        bool push_front(T data){
            Node<T>* d = new Node<T>(data);
            if(!Head){
                this->Head = d;
                this->Tail = d;
            }
            else{
                d->next = this->Head;
                this->Head = d;
            }
            this->len++;
            return 1;
        }

        bool pop_front(){
            if(!this->len){
                return 0;
            }
            Node<T>* d = this->Head;
            this->Head = this->Head->next;
            if(this->len == 1){
                this->Tail = NULL;
            }
            free(d);
            this->len--;
            return 1;
        }

        bool push_back(T data){
            Node<T>* d = new Node<T>(data);
            if(!this->len){
                this->Tail = this->Head = d;
            }
            else{
                this->Tail->next = d;
                this->Tail = d;
            }
            this->len++;
            return 1;
        }

        int indexOf(T data){
            Node<T>* pn = this->Head;
            int cnt = 0;
            while(pn){
                if(pn->data == data) return cnt;
                cnt++;
                pn = pn->next;
            }
            return -1;
        }

        T operator[](int index){
            if(index < 0){
                cout << "Out Of Range" << endl;
                throw "error";
            }
            Node<T>* pn = this->Head;
            int cnt = 0;
            while(pn){
                if(cnt == index) return pn->data;
                cnt++;
                pn = pn->next;
            }
            cout << "Out Of Range" << endl;
            throw "error";
        }

        bool traverseWithFunction(void (*fun)(T)){
            Node<T>* pn = this->Head;
            while(pn){
                fun(pn->data);
                pn = pn->next;
            }
            return 1;
        }

        bool clear(){
            while(this->Head){
                this->Tail = this->Head;
                this->Head = this->Head->next;
                free(this->Tail);
            }
            this->Tail = this->Head = NULL;
            this->len = 0;
            return 1;
        }

        bool destroy(){
            this->clear();
            free(this);
            return 1;
        }
};

// template<typename T>
// void count(T){
//     static int cnt = 1;
//     cout << cnt++ << endl;
// }

// int main(){
//     List<int> l;
//     l.push_back(1);
//     l.push_back(4);
//     l.push_back(2);
//     l.push_back(3);
//     // l.pop_front();
//     // l.pop_front();
//     // for(int i = 0; i < l.size(); i++){
//     //     cout << l[i] << ' ';
//     // }
//     // cout << l.size() << endl;
//     // l.traverseWithFunction(&count);

//     // cout << l[l.indexOf(3)] << endl;

//     l.clear();
//     cout << l.size() << endl;
//     if(&l){
//         cout << "yea" << endl;
//     }
//     else{
//         cout << "nup" << endl;
//     }

//     return 0;
// }