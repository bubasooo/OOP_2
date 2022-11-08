//
// Created by c4lc on 26.10.22.
//

#include "OrderD.cpp"
#include "Human.cpp"

class DListQueueHuman : OrderD<Human> {
public:
    Element<Human>* push(Human man) override {
        Element<Human>* node = new Element<Human>(man, NULL,NULL);
        DListQueueIterator<Human> current = begin();
        if(OrderD<Human>::head == NULL) {
            OrderD<Human>::head = node;
            OrderD<Human>::tail->setPrevious(node);
            return node;
        }
        while(current != end()) {
            if((*current).getValue() > man)
                break;
            current++;
        }

        DListQueueIterator<Human> prev = current--;
        connectNodes(node,&(*current));
        connectNodes(&(*prev), node);
        OrderD<Human>::num++;
        if(&(*current) == OrderD<Human>::head)
            OrderD<Human>::head = node;
        return node;
    }
    Element<Human>* pop() override {
        if(OrderD<Human>::head == NULL)
            throw;
        Element<Human>* removeNode = OrderD<Human>::head;
        Element<Human>* nextAfterHead = OrderD<Human>::head->getNext();
        OrderD<Human>::head = nextAfterHead;
        nextAfterHead->setPrevious(NULL);
        OrderD<Human>::num--;
        delete removeNode;

    }
};
