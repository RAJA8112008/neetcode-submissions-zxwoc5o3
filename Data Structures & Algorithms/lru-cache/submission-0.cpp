#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        Node* prev;
        Node* next;
        int key;
        int val;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };

    unordered_map<int, Node*> mp;
    int capacity;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        //connection between head and tail
        head->next = tail;
        tail->prev = head;
    }

    // insert after head
    void insert(Node* node) {
        Node* temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

    // remove any given node
    void remove(Node* delnode) {
        Node* prevNode = delnode->prev;
        Node* nextNode = delnode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* update = mp[key];

        remove(update);
        insert(update);

        return update->val;
    }

    void put(int key, int value) {
        // key already exists
        if (mp.find(key) != mp.end()) {
            Node* existing = mp[key];
            remove(existing);
            mp.erase(key);
            delete existing;
        }

        // cache full
        if (mp.size() == capacity) {
            Node* lru = tail->prev;

            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        insert(newNode);
        mp[key] = newNode;
    }
};