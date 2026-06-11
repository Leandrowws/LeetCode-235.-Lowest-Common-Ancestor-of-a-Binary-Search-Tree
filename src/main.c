#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* Inserir(struct TreeNode* root, int val) {
    if(root==NULL) {
        struct TreeNode* aux = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        aux->val = val;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    }  else {
        if(val < root->val) {
            root->left = Inserir(root->left, val);
        } else {
            root->right = Inserir(root->right, val);
        }
        return root;
    }
}

void Imprimir(struct TreeNode* root) {
    if(root!=NULL) {
        Imprimir(root->left);
        printf("%d ", root->val);
        Imprimir(root->right);
    }
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    while(root) {
        if(p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if(p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }
     return NULL;
}

int main() {
    struct TreeNode* arv = NULL;

    arv = Inserir(arv, 10);
    arv = Inserir(arv, 5);
    arv = Inserir(arv, 15);

    Imprimir(arv);

    printf("\nMenor ancestral comum: %d", lowestCommonAncestor(arv, arv->left, arv->right)->val);

    return 0;
}
