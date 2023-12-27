#include <queue>
#include <iostream>
#include <vector>

class MedianFinder {
public:
    MedianFinder() {}

    void addNum(double num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();

        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }

private:
    std::priority_queue<double> maxHeap;  // Max heap for the smaller half of the elements
    std::priority_queue<double, std::vector<double>, std::greater<double> > minHeap;  // Min heap for the larger half of the elements
};

int main() {
    MedianFinder mf;

    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the elements, one by one:\n";
    for (int i = 0; i < n; ++i) {
        double num;
        std::cin >> num;
        mf.addNum(num);
    }

    double median = mf.findMedian();
    std::cout << "Median: " << median << std::endl;

    return 0;
}