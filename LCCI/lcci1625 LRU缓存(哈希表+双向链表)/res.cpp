class LRUCache {
    struct node{
        int key, val;
        node* next, *pre;
        node() {}
        node(int key, int val) : key(key), val(val), next(nullptr), pre(nullptr) {}
    };
    unordered_map<int, node*> ump;
    node* head, *tail;
    int capacity;

    void insertHead(node* cur) {
        cur->next = head->next;
        head->next->pre = cur;
        head->next = cur;
        cur->pre = head;
    }
    void moveToHead(node* cur) {
        node* tmp = deleteNode(cur);
        insertHead(tmp);
    }
    node* deleteNode(node* cur) {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        return cur;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new node();
        tail = new node();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        int ret = -1;
        if (ump.count(key)) {
            // 存在
            node* cur = ump[key];
            ret = cur->val;
            moveToHead(cur);
        }
        return ret;
    }
    
    void put(int key, int value) {
        if (ump.count(key)) {
            // 已存在
            node* cur = ump[key];
            cur->val = value;
            moveToHead(cur);
        }
        else {
            node* cur = new node(key, value);
            if (ump.size() == this->capacity) {
                // 已满 删除尾元素
                node* tmp = deleteNode(tail->pre);
                ump.erase(tmp->key);
                delete tmp;

            }
            insertHead(cur);
            ump[key] = cur;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */