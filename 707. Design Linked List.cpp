class MyLinkedList {
public:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int x) : val(x), next(nullptr){}
    };

    MyLinkedList() {
        // 链表长度
        _size = 0;
        // 虚拟头指针
        headNode = new LinkedNode(0);
    }
    
    int get(int index) {
        // index 越界直接淘汰
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* curNode = headNode->next;
        while (index--) {
            curNode = curNode->next;
        }
        return curNode->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* tempNode = new LinkedNode(val);
        tempNode->next = headNode->next;
        headNode->next = tempNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* tempNode = new LinkedNode(val);
        LinkedNode* curNode = headNode;
        while(curNode->next != nullptr) {
            curNode = curNode->next;
        }
        // 在尾部添加节点
        curNode->next = tempNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= _size) {
            LinkedNode* tempNode = new LinkedNode(val);
            LinkedNode* curNode = headNode;
            while (index--) {
                curNode = curNode->next;
            }
            tempNode->next = curNode->next;
            curNode->next = tempNode;
            _size++;
        }
    }
    
    void deleteAtIndex(int index) {
        // 过滤不合法的 index
        if (index < _size && index >=0) {
            LinkedNode* curNode = headNode;
            while (index--) {
                curNode = curNode->next;
            }
            LinkedNode* tempNode = curNode->next;
            curNode->next = curNode->next->next;
            // 释放被删除节点的空间
            delete tempNode;
            _size--;
        }
    }

private:
    int _size;
    LinkedNode* headNode;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */