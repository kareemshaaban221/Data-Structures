#include <iostream>
#include </home/kareem/Desktop/DataStructures/LinkedList/LinkedList.cpp>

using namespace std;

template <class T>
class Queue{
    private:
        List<T>* ls;
    public:
        Queue(){
            ls = new List<T>();
        }

        bool isEmpty(){
            return ls->isEmpty();
        }
        int size(){
            return ls->size();
        }
        bool isFull(){
            return 0;
        }

        bool push(T data){
            return ls->push_back(data);
        }

        bool pop(){
            return ls->pop_front();
        }

        T peek_front(){
            return ls->peek_front();
        }
        T peek_rear(){
            return ls->peek_back();
        }

        bool find(T data){
            if(ls->indexOf(data) == -1){
                return 0;
            }
            return 1;
        }
        
        bool clear(){
            return l->clear();
        }
};

int main(){
    

    return 0;
}