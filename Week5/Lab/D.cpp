#include <iostream>
#include <vector>

using namespace std;

int n,m,a,b,pos,val;

class MinHeap {
    public:
    vector<int> a;
    int size;
    MinHeap(int n){
        size = n;
    }
    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMin() {
        return a[0];
    }
    void insert(int k) {
        if(a.size()==size){
            cout << "-1\n";
            return;
        }
        a.push_back(k);
        int i = a.size() - 1;
        cout << sift_up(i) << "\n";
    }
    int sift_up(int i){
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
            return sift_up(i);
        }
        return i+1;
    }
    int heapify(int i) {
        if (left(i) > a.size() - 1)
            return i+1;
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] > a[left(i)]) {
            j = right(i);
        }
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            return heapify(j);
        }
        return i+1;
    }
    void print() {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    void extractMax() {
        if(a.size() == 0){
            cout << "-1\n";
            return;
        }
        int root_value = a[0];
        if(a.size() == 1){
            a.pop_back();
            cout << 0 << " " << root_value << "\n";
            return;
        }
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        cout << heapify(0) << " " << root_value << "\n";
    }
};

int main() {
    cin >> n >> m;
    MinHeap *minHeap = new MinHeap(n);
    for (int i = 0; i < m; i++) {
        cin >> a;
        if(a == 1)
            minHeap->extractMax();
        if(a == 2){
            cin >> b;
            minHeap->insert(b);
        }
    }
    minHeap->print();
    return 0;
}