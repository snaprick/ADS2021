#include <iostream>
#include <vector>

using namespace std;

uint32_t n,m,a,b,pos,val;

class MinHeap {
    public:
    vector<int> a;
    uint32_t size;
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
        a.push_back(k);
    }
    int sift_up(int i){
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
            return sift_up(i);
        }
        return i+1;
    }
    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return ;
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] > a[left(i)]) {
            j = right(i);
        }
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }
    void siftDown(int n){
        for(int i = 0;i<n;i++){
            heapify(n-i-1);
        }
    }
    void print() {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cin >> n;
    MinHeap *minHeap = new MinHeap();
    for (int i = 0; i < n; i++) {
        cin >> m;
        minHeap->insert(m);
    }
    minHeap->siftDown(n);
    minHeap->print();
    return 0;
}