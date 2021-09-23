#include <iostream>
#include <cstdarg>
#include <iomanip>
#include <memory>
#include <algorithm>

using namespace std;

template <typename T>
T* merged;

template <typename T>
T* merge(T* left, T* right){
    int leftn = sizeof(left) / sizeof(T), rightn = sizeof(right) / sizeof(T);
    merged<T> = new T[leftn + rightn];
    int i = 0, j = 0, k = 0;
    while(i < leftn && j < rightn){
        if(left[i] < right[j]){
            *(merged<T> + (k++)) = left[i++];
        }
        else{
            *(merged<T> + (k++)) = right[j++];
        }
    }

    while(i < leftn){
        *(merged<T> + (k++)) = left[i++];
    }

    while(j < rightn){
        *(merged<T> + (k++)) = right[j++];
    }

    return merged<T>;
}

// template <typename T>
// T** res = new T*[2];

template <typename T>
T** split(T* arr){
    // if(res<T>[0]) free(res<T>[0]);if(res<T>[1]) free(res<T>[1]);if(res<T>) free(res<T>);
    static T** res = new T*[2];
    int n = sizeof(arr) / sizeof(T);
    // T* left = new T[n/2 + 1]; T* right = new T[n - n/2 - 1];
    res[0] = new T[n/2 + 1]; res[1] = new T[n - n/2 - 1];
    for(int i = 0; i < n/2 + 1; i++){
        res[0][i] = arr[i];
    }
    for(int i = n/2 + 1; i < n; i++){
        res[1][i - n/2 - 1] = arr[i];
    }

    // res[0] = left, res[1] = right;

    // free(left); free(right);

    return res;
}

template <typename T>
T* mergeSortOperation(T* arr){
    if(sizeof(arr) / sizeof(T) == 1){
        return arr;
    }

    T* left = mergeSortOperation(split<T>(arr)[0]);
    T* right = mergeSortOperation(split<T>(arr)[1]);

    return merge(left, right);
}

template <typename T>
void mergeSort(T* arr, int n){
    if(n == 1){
        return;
    }
    else{
        arr = mergeSortOperation(arr);
    }
}

template <typename T>
class DynamicArray {
    private:
        T* arr;
        int n = 0; // size
        int c = 0; // capacity

        void init(int n){
            arr = new T[n]; //garbage
            this->n = 0;
            this->c = n;
        }

    public:
        DynamicArray(){
            this->init(2);
        }
        DynamicArray(int n, T value){
            this->init(n);
            this->n = n;
            for(int i = 0; i < n; i++){
                *(arr+i) = value;
            }
        }
        DynamicArray(int n,...){
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

        int capacity(){
            return this->c;
        }

        void add_back(T data){ //add to the last position in the array // stack operation push
            if(this->c == this->n){
                this->c += this->c;
                T* newArr = new T[this->c];
                for(int i = 0; i < this->n; i++){
                    newArr[i] = arr[i];
                }
                free(arr);
                arr = newArr;
            }
            arr[this->n++] = data;
        }

        void insert(T data){ // O(n)
            if(this->c == this->n){
                this->c += this->c;
                T* newArr = new T[this->c];
                newArr[0] = data;
                for(int i = 1; i <= this->n; i++){
                    newArr[i] = arr[i - 1];
                }
                free(arr);
                arr = newArr;
            }
            else{
                for(int i = this->n - 1; i >= 0; i--){
                    arr[i + 1] = arr[i];
                }
                arr[0] = data;
            }
            this->n++;
        }

        void insert(T data, int position){ //position 1-based
            if(this->c == this->n){
                this->c += this->c;
                T* newArr = new T[this->c];
                for(int i = 0; i < position - 1; i++){
                    newArr[i] = arr[i];
                }
                newArr[position - 1] = data;
                for(int i = position; i <= this->n; i++){
                    newArr[i] = arr[i - 1];
                }
                free(arr);
                arr = newArr;
            }
            else{
                for(int i = this->n - 1; i >= position - 1; i--){
                    arr[i + 1] = arr[i];
                }
                arr[position - 1] = data;
            }
            this->n++;
        }

        int indexOf(T data){ // searching
            for(int i = 0; i < this->n; i++){
                if(*(arr+i) == data){
                    return i;
                }
            }
            return -1;
        }

        void remove_back(){ //remove the last element from the array logically // stack op pop
            this->n--;
        }

        void resize(){ // resize the array to fit its capacity and free the rest
            this->c = this->n;
            T* newArr = new T[this->n];
            for(int i = 0; i < this->n; i++){
                newArr[i] = arr[i];
            }
            free(arr);
            arr = newArr;
        }

        void sorting(){ // O(n log n)
            sort(this->arr, this->arr+this->n);
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
                return *(arr+index);
            }
        }

        T* begin(){
            return arr;
        }

        T* end(){
            return arr+this->n;
        }

        void clear(){
            int n = size();
            T* ptr = arr;
            for(int i = 0; i < n; i++){
                ptr = arr+i;
                ptr = NULL;
            }
            this->n = 0;
            this->c = 0;
        }
};

// int main(){

//     DynamicArray<int> d = DynamicArray<int>(5, 1);
//     cout << d.size() << endl;
//     for(int i = 0; i < d.size(); i++){
//         cout << d[i] << endl;
//     }
//     d.clear();
//     cout << d.size() << endl;
//     for(int i = 0; i < d.size(); i++){
//         cout << d[i] << endl;
//     }
// }


// int main(){
//     /*
//     DynamicArray<int> arr = DynamicArray<int>();

//     arr.add_back(5);
//     arr.add_back(10);
//     arr.add_back(15);
//     arr.insert(200);
//     arr.add_back(5);
//     arr.add_back(5);
//     arr.add_back(5);
//     arr.insert(1, 2);

//     cout << arr.size() << endl;
//     cout << arr.capacity() << endl;

//     // arr.remove_back();
//     // arr.resize();
//     // cout << arr.size() << endl;
//     // cout << arr.capacity() << endl;

//     // arr.sorting();
    
//     arr.print();
//     */
//    int arr[5] = {10,5,4,7,1};

//    mergeSort(arr, 5);

//    for(int i = 0; i < 5; i++){
//        ;
//    }

//     // cout << arr.indexOf(15) << endl;

//     return 0;
// }