#include <iostream>
#include <vector>

using namespace std;

int n,k,pos,val;

class MinHeap {
    public:
    vector<int> a;
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
    void sift_up(int i){
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }
    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        sift_up(i);
    }

    int heapify(int i) {
        if (left(i) > a.size() - 1)
            return i;
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] > a[left(i)]) {
            j = right(i);
        }
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            return heapify(j);
        }
        return i;
    }

    void decreaseKey(int i, int new_value) {
        a[i] -= new_value;
        cout << heapify(i)+1 << "\n";
    }

    void increaseKey(int i, int new_value) {
        a[i] = new_value;
        sift_up(i);
    }

    void print() {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    int extractMin() {
        int root_value = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if(a.size()>0)
            heapify(0);
        return root_value;
    }
    int updatePlus(int i, int val){
      a[i] += val;
      while(i > 0 && a[parent(i)] < a[i]){
          swap(a[parent(i)], a[i]);
          i = parent(i);
      }
      return i;
    }
};

int main() {
    MinHeap *minHeap = new MinHeap();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        minHeap->insert(k);
    }
    // minHeap->print();
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> pos >> val;
        cout << minHeap->updatePlus(pos-1,val) + 1 << "\n";
    }
    minHeap->print();
    return 0;
}