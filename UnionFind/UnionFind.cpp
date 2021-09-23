#include <iostream>
#include <map>

using namespace std;

class UnionFind {
    private:
        int n;
        int* sz;
        int* id;
        int numComponents;

    public:
        UnionFind(int size){
            if(size == 0){
                // try{
                //     throw "Invalid Size!\n";
                // } catch(const char* msg) {
                //     cout << msg;
                // }
                cerr << "Invalid Size!" << endl;
            }
            this->sz = new int[size];
            this->id = new int[size];

            //initialization
            for(int i = 0; i < size; i++){
                sz[i] = 1;
                id[i] = i;
            }

            this->numComponents = size;
            this->n = size;
        }

        int size(){
            return this->n;
        }

        int components(){
            return this->numComponents;
        }

        bool connected(int i, int j){
            return id[i] == id[j];
        }

        int componentSize(int p){
            return sz[find(p)];
        }

        int find(int p){
            int root = p;
            while(id[root] != root){
                root = id[root];
            }

            // path compression
            // this make the complexity is amorized constant time alpha(n)
            // the first find operation in each new component(group) is O(n)
            while(id[p] != root){
                int next = id[p];
                id[p] = root;
                p = next;
            }

            return root;
        }

        void unify(int i, int j){
            int root1 = find(i);
            int root2 = find(j);

            if(root1 == root2) return;

            if(sz[root1] < sz[root2]){
                sz[root2] += sz[root1];
                id[root1] = id[root2]; // or id[root1] = root2; both are the same.
            }
            else{
                sz[root1] += sz[root2];
                id[root2] = id[root1];
            }

            this->numComponents--;
        }
};

int main(){
    map<char, int> mp;
    mp['A'] = 0, mp['B'] = 1, mp['D'] = 2, mp['C'] = 3, mp['F'] = 4, mp['G'] = 5, mp['E'] = 6, mp['H'] = 7;
    UnionFind uf = UnionFind(8);
    uf.unify(mp['A'], mp['B']);
    uf.unify(mp['C'], mp['D']);
    uf.unify(mp['E'], mp['D']);
    uf.unify(mp['E'], mp['A']);
    cout << uf.find(mp['A']) << endl;
    cout << "uf size: " << uf.size() << endl;
    cout << "uf components: " << uf.components() << endl;

    return 0;
}