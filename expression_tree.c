#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* createNode(char data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct Node* stack[20];
int top = -1;

void push(struct Node* n) { stack[++top] = n; }
struct Node* pop() { return stack[top--]; }

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int evaluate(struct Node* root) {
    if (isdigit(root->data))
        return root->data - '0';

    int left = evaluate(root->left);
    int right = evaluate(root->right);

    switch (root->data) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
    }
    return 0;
}

int main() {
    char postfix[] = "832*+62/-";

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(createNode(postfix[i]));
        } else {
            struct Node* n = createNode(postfix[i]);
            n->right = pop();
            n->left = pop();
            push(n);
        }
    }

    struct Node* root = pop();

    printf("Inorder   : ");
    inorder(root);

    printf("\nPreorder  : ");
    preorder(root);

    printf("\nPostorder : ");
    postorder(root);

    printf("\nValue     : %d\n", evaluate(root));

    return 0;
}
