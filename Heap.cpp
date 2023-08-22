#include <vector>
#include <unordered_map>

using namespace std;

class Heap {
    public:
    struct Node {
        int id;
        int key;
    };

    //int temp;
    //string segfault = "segfault";
    vector<Node> heap;
    unordered_map<int, int> mapIdToIndex;

    // Construct a heap from an array of keys
    Heap(vector<int> keys, int length) {
        heap.resize(length);
        for (int i = 0; i < length; i++) {
            heap[i].id = i;
            heap[i].key = keys[i];
            mapIdToIndex[i] = i;
        }

        // Heapify the entire heap
        for (int i = (length-1)/2; i >= 0; i--) {
            heapify(i);
        }
    }

    // Heapify the subtree rooted at index
    void heapify(int index) {
        int smallest = index;
        int lChild = (2*index) + 1;
        int rChild = (2*index) + 2;

        // Find the smallest Node
        if (lChild < heap.size() && heap[lChild].key < heap[smallest].key) {
            smallest = lChild;
        }
        if (rChild < heap.size() && heap[rChild].key < heap[smallest].key) {
            smallest = rChild;
        }

        // If the smallest Node is not index, swap index and the smallest Node
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            mapIdToIndex[heap[index].id] = index;
            mapIdToIndex[heap[smallest].id] = smallest;
            heapify(smallest);
        }
    }

    bool in_heap(int id) {
        return mapIdToIndex.find(id) != mapIdToIndex.end();
    }

    bool is_empty() {
        return heap.empty();
    }

    int min_key() {
        return heap[0].key;
    }

    int min_id() {
        return heap[0].id;
    }

    int key(int id) {
        return heap[mapIdToIndex[id]].key;
    }

    void delete_min() {
        // Save the minimum Node and the last Node in the heap
        Node minNode = heap[0];
        Node lastNode = heap.back();

        // Remove the minimum Node from the heap and update the mapIdToIndex map
        heap.pop_back();
        mapIdToIndex.erase(minNode.id);

        if (!heap.empty()) {
            // Replace the root with the last Node and update the mapIdToIndex map
            heap[0] = lastNode;
            mapIdToIndex[lastNode.id] = 0;
            heapify(0);
        }
    }

    // Decreases the key value of an Node in the heap with the specified id
    void decrease_key(int id, int newKey) {
        // Get the index of the specified id in the heap
        int index = mapIdToIndex[id];
        // Check if the new key value is greater than or equal to the current key value
        if (newKey >= heap[index].key) {
            return;
        }

        // Set the new key value for the Node at index in the heap
        heap[index].key = newKey;
        // Perform a swap with the parent Node as long as the parent Node has a greater key value
        while (index > 0 && heap[(index-1)/2].key > heap[index].key) { 
            // Swap the Nodes
            swap(heap[index], heap[(index-1)/2]);  
            mapIdToIndex[heap[index].id] = index;  
            mapIdToIndex[heap[(index-1)/2].id] = (index-1)/2;  
            index = (index-1)/2;  
        }
    }
};
