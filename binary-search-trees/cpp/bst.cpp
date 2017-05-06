#include <iostream>

template <class T>
class Node {
    T value;
    Node* left;
    Node* right;

  public:
    Node(T val) {
      this->value = val;
    }

    bool insert(T val) {
      if (this->value == val) { return false;}
      else if (this->value > val) {
        if (this->left) {return this->left->insert(val);}
        else {
          this->left = Node(val);
          return true;
        }

      } else {
        if (this->right){return this->right->insert(val);}
        else {
          this->right = Node(val);
          return true;
        }
      }
    }

    bool find(T val) {
      if (this->value == val) return true;
      else if (this->value > val) {
        if (!this->left) {return false;}
        else {return this->left->find(val);}

      } else {
        if (!this->right) {return false;}
        else {return this->right->find(val);}
      }
    }
};


template <class T>
class Tree {

  private:
    Node<T> *root;

  public:

    bool insert(T val) {
        if (this->root)
            return this->root->insert(val);
        else {
            this->root = new Node<int>(val);
            return true;
        }
    }

    bool find(T val) {
        if (this->root)
            return this->root->find(val);
        return false;
    }
};

int main() {
  Tree<int> bst = Tree<int>();
  bst.insert(10);
  bst.insert(20);
  bst.insert(25);
  
  bool x = bst.find(30);
  std::cout << x;
}
