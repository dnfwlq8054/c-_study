#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class tree {
private:
    int num;
    tree* right;
    tree* left;
public:
    tree() {
        right = NULL;
        left = NULL;
        num = 0;
    }

    ~tree() {
        delete(right);
        delete(left);
    }

    tree* getLeft() {
        return left;
    }

    tree* getRight() {
        return right;
    }

    void insert_right(int number) {
        right = new tree();
        right->setNum(number);
    }

    void insert_left(int number) {
        left = new tree();
        left->setNum(number);
    }

    void setNum(int number) {
        num = number;
    }

    bool left_Check() {
        if (left == NULL) return false;
        else return true;
    }

    bool right_Check() {
        if (right == NULL) return false;
        else return true;
    }

    int getNum() {
        return num;
    }
};

int main()
{
    vector<int> element = { 1, 2, 3, 4, 5, 6, 7, 8 };
    queue<tree *> tree_element;
    queue<int> element_queue;
    tree* t = new tree();
    //unique_ptr<tree*> u_t(move(t));

    for (auto n : element)
        element_queue.emplace(n);

    tree_element.emplace(t);

    while (!element_queue.empty()) {
        tree* temp = tree_element.front();
        tree_element.pop();

        int left, right;

        left = element_queue.front();
        element_queue.pop();

        temp->insert_left(left);
        tree_element.emplace(temp->getLeft());
        if (element_queue.empty()) break;
    
        right = element_queue.front();
        element_queue.pop();

        temp->insert_right(right);
        tree_element.emplace(temp->getRight());
    }

    queue<tree*>().swap(tree_element);

    tree_element.emplace(t);
    while (!tree_element.empty()) {
        tree* temp = tree_element.front();
        tree_element.pop();

        cout << temp->getLeft()->getNum() << " ";
        if(temp->getLeft()->left_Check())
            tree_element.emplace(temp->getLeft());

        cout << temp->getRight()->getNum() << " ";
        if (temp->getRight()->right_Check())
            tree_element.emplace(temp->getRight());
    }

    return 0;
}
