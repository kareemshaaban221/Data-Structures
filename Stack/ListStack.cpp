#include <iostream>
#include </home/kareem/Desktop/DataStructures/LinkedList/LinkedList.cpp>

using namespace std;

template <typename T>
class Stack{
    private:
        List<T>* l;
    public:
        Stack(){
            l = new List<T>();
        }

        bool isEmpty(){
            return l->isEmpty();
        }
        bool isFull(){
            return 0;
        }
        int size(){
            return l->size();
        }

        bool push(T data){
            return l->push_front(data);
        }
        bool pop(){
            return l->pop_front();
        }

        T peek(){
            return l->peek_front();
        }

        bool find(T data){
            if(l->indexOf(data) == -1){
                return 0;
            }
            return 1;
        }

        bool clear(){
            return l->clear();
        }
};

int main(){
    Stack<string> s;

    s.push("Kemo");
    s.push("Ali");
    s.push("Mohamed");
    s.push("Ahmed");
    s.push("Shady");
    s.push("Fady");

    if(s.find("Kemo")){
        cout << "Founded" << endl;
    }
    else{
        cout << "isn't here!" << endl;
    }

    s.clear();
    if(s.isEmpty()){
        cout << "Empty" << endl;
    }

    int n = s.size();
    while(n--){
        cout << s.peek() << " ";
        s.pop();
    }

    cout << endl;

    if(s.isEmpty()){
        cout << "Empty" << endl;
    }

    cout << s.size() << endl;

    return 0;
}