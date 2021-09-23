#include <map>
#include <vector>
#include </home/kareem/Desktop/DataStructures/Arrays/DynamicArray.cpp>

using namespace std;

template <typename T>
class PQueue{
    DynamicArray<T> heap;
    map<T, DynamicArray<int>*> hash;

    // private methods
    bool sink(int index){
        int parent = index, left = 2*index+1, right = 2*index+2;
        int smallest = 0;
        while(right < heap.size()){
            smallest = left;
            if(heap[left] > heap[right]){
                smallest = right;
            }
            if(heap[smallest] < heap[parent]){
                mySwap(smallest, parent);
                parent = smallest;
            }
            else{
                break;
            }
            
            left = 2*parent + 1, right = 2*parent + 2;
        }
        if(right == heap.size() && heap[left] < heap[parent]){
            mySwap(left, parent);
        }
        return 1;
    }

    bool swim(int index){
        int parent = (index-1)/2;

        while(heap[parent] > heap[index] && index > 0){
            mySwap(parent, index);
            index = parent;
            parent = (index-1)/2;
        }
        return 1;
    }

    void mySwap(int i, int j){
        T temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    public:
        PQueue(){
            heap = DynamicArray<T>();
        }
        PQueue(int size){
            heap = DynamicArray<T>(size);
        }
        PQueue(T* arr, int size){
            // This one O(n)

            heap = DynamicArray<T>();
            for(int i = 0; i < size; i++){
                heap.add_back(arr[i]);
                // if(!hash[arr[i]]){
                //     hash[arr[i]] = new DynamicArray<int>();
                //     hash[arr[i]]->add_back(i);
                // }
                // else{
                //     hash[arr[i]]->add_back(i);
                // }
            }

            for(int i = heap.size()/2 - 1; i >= 0; i--){
                sink(i);
            }

            // OR

            // This one O(nlogn)

            // heap = DynamicArray<T>(sizeof(arr)/sizeof(T));
            // for(int i = 0; i < sizeof(arr)/sizeof(T); i++){
            //     add(arr[i]);
            // }
        }
        PQueue(vector<T> coll){
            PQueue(coll.size());
            for(auto it : coll){
                add(it);
            }
        }

        bool isEmpty(){
            return heap.size() == 0;
        }
        bool clear(){
            heap.clear();
            return 1;
        }
        int size(){
            return heap.size();
        }
        T peek(){
            return heap[0];
        }
        bool poll(){
            return removeAt(0);
        }
        // bool contains(T elem){
        //     if(hash[elem]){
        //         return 1;
        //     }
        //     return 0;
        // }

        bool add(T elem){
            heap.add_back(elem);
            return swim(heap.size() - 1);
        }

        bool remove(T elem){
            return removeAt(heap.indexOf(elem));
        }

        bool removeAt(int index){
            if(!heap.size()) throw "error";

            if(index >= heap.size() - 1){
                heap.remove_back();
                return 1;
            } 

            mySwap(index, heap.size()-1);
            heap.remove_back();
            sink(index);
            return 1;
        }

        T* begin(){
            return heap.begin();
        }

        T* end(){
            return heap.end();
        }

        void print(){
            for(int i = 0; i < heap.size(); i++){
                cout << heap[i] << endl;
            }
        }
};

int main(){
    // vector<int> v = {5, 4, 2, 3, 1, 6};
    // PQueue<int> pq(v);

    int* arr = new int[6]{5, 4, 2, 3, 1, 6};
    PQueue<int> pq(arr, 6);
    // pq.add(5);
    // pq.add(4);
    // pq.add(2);
    // pq.add(3);
    // pq.add(1);
    // pq.add(6);
    // pq.add(5);
    // pq.print();
    // pq.remove(1);
    // while(pq.size()){
    //     cout << pq.peek() << endl;
    //     pq.poll();
    // }



    for(auto it = pq.begin(); it < pq.end(); it++){
        cout << *(it) << endl;
    }

    return 0;
}