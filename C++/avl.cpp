#include <iostream>

using namespace std;

struct BSTNode {
        int key;
        int elemento;
        int height;
        BSTNode* left;
        BSTNode* right;
        BSTNode(int k, int e){
            this->key = k;
            this->elemento = e;
            this->left = NULL;
            this->right = NULL;
            this->height = 0;
        }
};

class BST {
    private:
        BSTNode* root;
        int nodeCount;
        int index;
        
    public:
        BST(){ // contrutor
            this->root = NULL;
            this->nodeCount = 0;
            this->index = 0;
        }
        void insert(BST* bst, int k, int e){
            this->root = insertHelp(this->root, k, e);
            this->nodeCount++;
        }
        BSTNode* insertHelp(BSTNode* rt, int k, int e){
            if (rt == NULL){
                return new BSTNode(k, e);
            }
            if (rt->key > k){
                
                rt->left = insertHelp(rt->left, k, e);
            } else {
                rt->right = insertHelp(rt->right, k, e);
            }
            rt->height = 1 + max(h(rt->left), h(rt->right));
            int balance = getBalance(rt);
            if (balance < -1 && k >= rt->right->key){
              return leftRotate(rt);
            }
            if (balance > 1 && k < rt->left->key){
              return rightRotate(rt);
            }
            if (balance > 1 && k >= rt->left->key){
              rt->left = leftRotate(rt->left);
              return rightRotate(rt);
            }
            if (balance < -1 && k < rt->right->key){
              rt->right = rightRotate(rt->right);
              return leftRotate(rt);
            }
            return rt;

        }
        BSTNode* rightRotate(BSTNode* rt){
          BSTNode* l= rt->left;
          BSTNode* lr = l->right;
          l->right = rt;
          rt->left = lr;
          rt->height = max(h(rt->left), h(rt->right)) + 1;
          l->height = max(h(l->left), h(l->right)) + 1;
          return l;
        }
        BSTNode* leftRotate(BSTNode* rt){
          BSTNode* r = rt->right;
          BSTNode* rl = r->left;
          r->left = rt;
          rt->right = rl;
          rt->height = max(h(rt->left), h(rt->right)) + 1;
          r->height = max(h(r->left), h(r->right)) + 1;
          return r;
        }
        int h(BSTNode* rt){
            if (rt == NULL){
                return -1;
            } 
            else if(rt->left == NULL && rt->right == NULL) {
                return rt->height;
            }
            else if (rt->left == NULL){
              rt->height++;
              h(rt->right);
            }
            else if (rt->right == NULL) {
              rt->height++;
              h(rt->left);
            }
            return rt->height;
        }
        int getBalance(BSTNode* rt){
            if (rt == NULL){
                return 0;
            } else {
                return h(rt->left) - h(rt->right);
            }
        }
        int find(BST* bst, int k){
          return findHelp(bst->root, k);
        }
        int findHelp(BSTNode* rt, int k){
          if (rt == NULL){
            return -1;
          }
          if (rt->key > k){
            return findHelp(rt->left, k);
          }
          else if (rt->key == k){
            return rt->elemento;
          } else {
            return findHelp(rt->right, k);
          }
        }
        
        BSTNode* deleteMin(BSTNode* rt){
            if (rt->left == NULL){
                if (this->root->key == rt->key){
                    this->nodeCount--;
                    this->root = rt->right;
                    
                } else {
                    this->nodeCount--;
                    return rt->right;
                    
                }
                
            } else {
                rt->left = deleteMin(rt->left);
            }
            
            return rt;
        }
        int getmin(BSTNode* rt){
            if (rt->left == NULL){
                return rt->elemento;
            }
            return getmin(rt->left);
        }
        int inOrder(BSTNode* rt, int k){
            if (rt != NULL){
                inOrder(rt->left, k);
                if (rt->key != k){
                  this->index++;
                } else {
                  return this->index;
                }
                inOrder(rt->right, k);  
            }
            return index;
        }
        BSTNode* getRoot(){
            return this->root;
        }
        int getTamanho(){
            return this->nodeCount;
        }
        void setIndex(){
          this->index = 0;
        }
};

int main(){
  int casos = 0, action = 0, number = 0, loop = 0;
  BST* numbers = new BST();
  scanf("%i", &casos);
  while (loop < casos){
    scanf("%i", &action);
    scanf("%i", &number);
    if(action == 1){
      numbers->insert(numbers, number, loop + 1);
    }
    else if(action == 2){
      if (numbers->find(numbers, number) > 0){
        printf("%i\n", numbers->inOrder(numbers->getRoot(), number) + 1);
        numbers->setIndex();
      } else {
        printf("Data tidak ada\n");
      }
    }
    loop++;
  }
  system("pause");
  return 0;
}