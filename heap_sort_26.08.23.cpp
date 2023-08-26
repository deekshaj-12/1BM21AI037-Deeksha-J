#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> data;

public:
    void heapify();
    void heapify(int end);
    void heapSort();
    void getInput();
    void printHeap();
};

void Heap::heapSort() {
    int size = data.size();
    for (int i = size - 1; i > 1; i--) {
        int root = data[1];
        if (data[1] > data[i]) {
            data[1] = data[i];
            data[i] = root;
            heapify(i - 1);
            printHeap();
        }
    }
    cout << "Heap sort done\n";
}

void Heap::printHeap() {
    int size = data.size();
    cout << "Current heap: ";
    for (int i = 1; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
}

void Heap::heapify() {
    int size = data.size();
    heapify(size);
}

void Heap::heapify(int end) {
    int size = data.size();
    for (int i = end / 2; i > 0; i--) {
        int index = i, value = data[index];
        bool isHeap = false;
        while (!isHeap && 2 * index < end) {
            int childIndex = 2 * index;
            if (childIndex < size) {
                if (data[childIndex] < data[childIndex + 1])
                    childIndex = childIndex + 1;
            }
            if (value > data[childIndex])
                isHeap = true;
            else {
                data[index] = data[childIndex];
                index = childIndex;
            }
        }
        data[index] = value;
    }
}

void Heap::getInput() {
    int count;
    cout << "Enter the number of elements: ";
    cin >> count;
    count = count + 1;
    data.resize(count);
    cout << "Enter the elements: ";
    for (int i = 1; i < count; i++) {
        cin >> data[i];
    }
}

int main(void) {
    Heap heapObj;
    heapObj.getInput();
    heapObj.heapify();
    heapObj.printHeap();
    heapObj.heapSort();
    heapObj.printHeap();
}
