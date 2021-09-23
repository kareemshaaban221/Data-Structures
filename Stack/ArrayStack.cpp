#include </home/kareem/Desktop/DataStructures/Arrays/DynamicArray.cpp>

using namespace std;

template <typename T>
class Stack{
    private:
        DynamicArray<T> arr;
        int Top;

    public:
        Stack(){
            this->arr = DynamicArray<T>();
            this->Top = 0;
        }
        
        int size(){
            return Top;
        }
        bool isEmpty(){
            return Top == 0;
        }
        bool isFull(){
            return 0;
        }

        bool push(T data){
            arr.add_back(data);
            Top++;
            return 1;
        }

        bool pop(){
            if(this->isEmpty()){
                return 0;
            }
            arr.remove_back();
            Top--;
            return 1;
        }

        T peek(){
            if(this->isEmpty()){
                cout << "Invalid Peek" << endl
                throw "Invalid Peek";
            }
            return arr[Top - 1];
        }

        bool find(T data){
            if(arr.indexOf(data) == -1){
                return 0;
            }
            return 1;
        }

        void clear(){
            this->Top = 0;
        }

        void destroy(){
            free(arr);
            Top = 0;
            free(this);
        }
};

int main(){
    Stack<int> s = Stack<int>();
    cout << s.isEmpty() << endl;
    s.push(5);
    cout << s.peek() << endl;
    s.pop();
    cout << s.isEmpty() << endl;
    s.push(10);
    cout << s.isEmpty() << endl;

    return 0;
}