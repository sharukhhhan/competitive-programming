#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> maxHeap;
    maxHeap.push(30);
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(15);

    while(!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    cout << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(15);
    
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }


    cout << '\n';

    // using custom class and comparator
    class Point { 
        int x; 
        int y; 
    public: 
        Point(int x, int y) 
        { 
            this->x = x; 
            this->y = y; 
        } 
        int getX() const { return x; } 
        int getY() const { return y; } 
    }; 
    class myComparator { 
    public: 
        int operator() (const Point& p1, const Point& p2) 
        { 
            return p1.getX() > p2.getX(); 
        } 
    }; 
  
    // Creates a Min heap of points (order by x coordinate) 
    priority_queue <Point, vector<Point>, myComparator > pq; 
    pq.push(Point(10, 2)); 
    pq.push(Point(2, 1)); 
    pq.push(Point(1, 5)); 
  
    // One by one extract items from min heap 
    while (pq.empty() == false) 
    { 
        Point p = pq.top(); 
        cout << "(" << p.getX() << ", " << p.getY() << ")"; 
        cout << endl; 
        pq.pop(); 
    } 
}