// HeapPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class MaxHeap {
private:
	vector<int> heap;

	void heapifyUp(int index) {
		while (index > 0) {
			int parentIndex = (index - 1) / 2;
			if (heap.at(index) <= heap[parentIndex]) {
				break;
			}
			swap(heap.at(index), heap[parentIndex]);
			index = parentIndex;
		}
	}
	void heapifyDown(int index) {
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;
		int largest = index;
		if (leftChild < heap.size() && heap.at(leftChild) > heap.at(largest)) {
			largest = leftChild;
		}
		if (rightChild < heap.size() && heap.at(rightChild) > heap.at(largest)) {
			largest = rightChild;
		}
		if (largest != index) {
			swap(heap.at(index), heap.at(largest));
			heapifyDown(largest);
		}
	}

public:
	MaxHeap() {}
	void push(int value) {
		heap.push_back(value);
		int index = heap.size() - 1;
		heapifyUp(index);
	}
	int top() {
		if (empty())
			throw out_of_range("Heap is empty");
		return heap[0];
	}
	void pop() {
		if (empty())
			throw out_of_range("Heap is empty");
		heap[0] = heap.back();
		heap.pop_back();
		heapifyDown(0);
	}
	bool empty() {
		return heap.empty();
	}
	size_t size() {
		return heap.size();
	}
	void print() const {
		for (const int& element : heap)
			cout << element << " ";
		cout << "\n";
	}
	void clear() {
		heap.clear();
	}
};


int main()
{
	MaxHeap maxHeap;
	maxHeap.push(30);
	maxHeap.push(10);
	maxHeap.push(50);
	maxHeap.push(20);
	maxHeap.push(40);
	cout << "Max-Heap Elements: ";
	while (!maxHeap.empty()) {
		cout << maxHeap.top() << " ";
		maxHeap.pop();
	}
	cout << endl;
	maxHeap.push(3);
	maxHeap.print();
	maxHeap.push(1);
	maxHeap.print();
	maxHeap.push(4);
	maxHeap.print();
	maxHeap.push(1);
	maxHeap.print();
	maxHeap.push(5);
	maxHeap.print();

	return 0;
}

