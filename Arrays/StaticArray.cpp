#include <iostream>
#include <cstdarg>
#include <exception>
#include <typeinfo>

using namespace std;

template <class T>
class StaticArray{
    private:
        int n;
        T* arr;

        void init(int n){
            arr = new T[n]; //garbage
            this->n = n;
        }

    public:
        StaticArray(int n, T value){
            this->init(n);
            for(int i = 0; i < n; i++){
                *(arr+i) = value;
            }
        }
        StaticArray(int n,...){
            this->init(n);

            va_list args;
            va_start(args, n);

            for(int i = 0; i < n; i++){
                try{
                    *(arr+i) = va_arg(args, T);
                }
                catch(const char *msg){
                    throw "%s\n", msg;
                }
            }

            va_end(args);
        }

        int size(){
            return this->n;
        }

        void print(){
            for(int i = 0; i < this->n; i++){
                cout << *(arr+i) << ' ';
            }
            cout << endl;
        }

        T& operator[](int index){
            if(index >= this->n){
                cout << "out of bounds" << endl;
                throw "out of bounds";
            }
            else{
                int i = index;
                return *(arr+i);
            }
        }
};

int main(){
    // StaticArray<int> arr = StaticArray<int>(7, 1, 2, 3, 2, 10, 1, 7);

    // for(int i = 0; i < arr.size(); i++){
    //     arr[i] *= 2;
    // }

    // arr.print();

    char** arr = new char*[2];
    arr[0] = new char[5]{'A', 'B', 'C', 'D', 'E'}, arr[1] = new char[5]{'F', 'G', 'H', 'I', 'J'};
    cout << sizeof(arr) << endl;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 5; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}